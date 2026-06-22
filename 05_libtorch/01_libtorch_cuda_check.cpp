#include <iostream>

#include <torch/torch.h>

int main() {
    std::cout << std::boolalpha;

    std::cout << "LibTorch version: "
              << TORCH_VERSION_MAJOR << '.'
              << TORCH_VERSION_MINOR << '.'
              << TORCH_VERSION_PATCH << '\n';

    const bool cuda_available = torch::cuda::is_available();
    std::cout << "CUDA available: " << cuda_available << "\n\n";

    torch::Tensor cpu_tensor = torch::rand({2, 3});
    std::cout << "CPU tensor:\n" << cpu_tensor << "\n\n";

    if (cuda_available) {
        torch::Tensor gpu_tensor = cpu_tensor.to(torch::kCUDA);
        std::cout << "GPU tensor:\n" << gpu_tensor << "\n\n";

        torch::Tensor a = torch::rand({2, 3}, torch::device(torch::kCUDA));
        torch::Tensor b = torch::rand({2, 3}, torch::device(torch::kCUDA));
        torch::Tensor result = a + b;

        std::cout << "CUDA tensor addition result:\n" << result << '\n';
    } else {
        std::cout << "LibTorch was found, but CUDA is not available at runtime.\n";
        std::cout << "Check that you installed a CUDA-enabled LibTorch build and that your GPU driver/runtime are available.\n";
    }

    return 0;
}
