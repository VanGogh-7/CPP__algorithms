#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> line;
    line.push("Alice");
    line.push("Bob");
    line.push("Carol");

    std::cout << "Queue front to back: ";
    while (!line.empty()) {
        std::cout << line.front() << ' ';
        line.pop();
    }

    std::cout << '\n';
    return 0;
}
