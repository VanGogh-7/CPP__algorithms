#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int main() {
    std::mutex mtx;
    auto print_thread_id = [&mtx](int id) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << id << '\n';
    };

    std::vector<std::jthread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(print_thread_id, i);
    }
    return 0;
}
