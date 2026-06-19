#include <iostream>

void addOne(int& number) {
    number++;
}

int main() {
    int value = 10;
    int& ref = value;

    std::cout << "Original value: " << value << '\n';
    ref = 20;
    std::cout << "After changing ref: " << value << '\n';

    addOne(value);
    std::cout << "After addOne: " << value << '\n';

    return 0;
}
