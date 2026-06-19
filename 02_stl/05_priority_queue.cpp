#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> tasks;
    tasks.push(2);
    tasks.push(5);
    tasks.push(1);

    std::cout << "Highest priority first: ";
    while (!tasks.empty()) {
        std::cout << tasks.top() << ' ';
        tasks.pop();
    }

    std::cout << '\n';
    return 0;
}
