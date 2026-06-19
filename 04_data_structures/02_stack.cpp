#include <iostream>
#include <stack>

int main() {
    std::stack<int> numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Stack top to bottom: ";
    while (!numbers.empty()) {
        std::cout << numbers.top() << ' ';
        numbers.pop();
    }

    std::cout << '\n';
    return 0;
}
