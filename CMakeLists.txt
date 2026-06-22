cmake_minimum_required(VERSION 4.2)
project(CPP_algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(hello 01_cpp_basics/01_hello.cpp)
add_executable(variables 01_cpp_basics/02_variables.cpp)
add_executable(references 01_cpp_basics/03_references.cpp)
add_executable(pointers 01_cpp_basics/04_pointers.cpp)
add_executable(struct 01_cpp_basics/05_struct.cpp)
add_executable(class 01_cpp_basics/06_class.cpp)

add_executable(vector_demo 02_stl/01_vector.cpp)
add_executable(string_demo 02_stl/02_string.cpp)
add_executable(map_demo 02_stl/03_map.cpp)
add_executable(set_demo 02_stl/04_set.cpp)
add_executable(priority_queue_demo 02_stl/05_priority_queue.cpp)

add_executable(insertion_sort 03_algorithms/01_insertion_sort.cpp)
add_executable(binary_search_demo 03_algorithms/02_binary_search.cpp)
add_executable(merge_sort 03_algorithms/03_merge_sort.cpp)
add_executable(quick_sort 03_algorithms/04_quick_sort.cpp)
add_executable(dfs_bfs 03_algorithms/05_dfs_bfs.cpp)

add_executable(linked_list_demo 04_data_structures/01_linked_list.cpp)
add_executable(stack_demo 04_data_structures/02_stack.cpp)
add_executable(queue_demo 04_data_structures/03_queue.cpp)
add_executable(binary_tree_demo 04_data_structures/04_binary_tree.cpp)
add_executable(heap_demo 04_data_structures/05_heap.cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(LibTorchSetup)

add_libtorch_executable(
        libtorch_cuda_check
        05_libtorch/01_libtorch_cuda_check.cpp
)
