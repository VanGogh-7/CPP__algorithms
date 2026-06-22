include_guard(GLOBAL)

function(add_libtorch_executable target_name source_file)
    if(NOT Torch_FOUND)
        find_package(Torch REQUIRED)
    endif()

    find_library(LIBTORCH_CUDA_NCCL_LIBRARY
            NAMES nccl libnccl.so.2
            HINTS
            "/home/van-gogh/miniconda3/envs/deep_learning/lib"
            "/usr/lib/x86_64-linux-gnu"
            REQUIRED
    )
    find_library(LIBTORCH_CUDA_CUPTI_LIBRARY
            NAMES libcupti.so.12 cupti
            HINTS
            "/home/van-gogh/miniconda3/envs/deep_learning/lib/python3.10/site-packages/nvidia/cuda_cupti/lib"
            "/home/van-gogh/miniconda3/pkgs/cuda-cupti-12.9.79-h7354ed3_0/lib"
            "/usr/lib/x86_64-linux-gnu"
            REQUIRED
    )
    find_library(LIBTORCH_CUDA_CUDART_LIBRARY
            NAMES libcudart.so.12 cudart
            HINTS
            "/home/van-gogh/miniconda3/envs/deep_learning/lib/python3.10/site-packages/nvidia/cuda_runtime/lib"
            "/home/van-gogh/miniconda3/pkgs/cuda-cudart_linux-64-12.9.79-hfb20e49_0/targets/x86_64-linux/lib"
            "/usr/lib/x86_64-linux-gnu"
            REQUIRED
    )

    set(_libtorch_cuda_runtime_library_dirs
            "${TORCH_INSTALL_PREFIX}/lib"
    )
    foreach(_libtorch_cuda_library IN LISTS
            LIBTORCH_CUDA_NCCL_LIBRARY
            LIBTORCH_CUDA_CUPTI_LIBRARY
            LIBTORCH_CUDA_CUDART_LIBRARY)
        get_filename_component(_libtorch_cuda_library_dir "${_libtorch_cuda_library}" DIRECTORY)
        list(APPEND _libtorch_cuda_runtime_library_dirs "${_libtorch_cuda_library_dir}")
    endforeach()
    list(APPEND _libtorch_cuda_runtime_library_dirs "/usr/lib/x86_64-linux-gnu")
    list(REMOVE_DUPLICATES _libtorch_cuda_runtime_library_dirs)

    add_executable(${target_name} ${source_file})

    target_link_libraries(${target_name} PRIVATE
            ${TORCH_LIBRARIES}
            ${LIBTORCH_CUDA_NCCL_LIBRARY}
            ${LIBTORCH_CUDA_CUPTI_LIBRARY}
            ${LIBTORCH_CUDA_CUDART_LIBRARY}
    )

    target_compile_options(${target_name} PRIVATE ${TORCH_CXX_FLAGS})

    target_link_directories(${target_name} PRIVATE ${_libtorch_cuda_runtime_library_dirs})

    # Keep the explicit CUDA runtime libraries in DT_NEEDED so rpath resolves
    # compatible copies before older system libraries.
    target_link_options(${target_name} PRIVATE "-Wl,--no-as-needed")

    foreach(_libtorch_cuda_runtime_library_dir IN LISTS _libtorch_cuda_runtime_library_dirs)
        target_link_options(${target_name} PRIVATE
                "-Wl,-rpath,${_libtorch_cuda_runtime_library_dir}"
                "-Wl,-rpath-link,${_libtorch_cuda_runtime_library_dir}"
        )
    endforeach()
endfunction()
