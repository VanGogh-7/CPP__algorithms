#include <iostream>

int main() {
    int value = 42;
    int* pointer = &value;

    std::cout << "Value: " << value << '\n';
    std::cout << "Address stored in pointer: " << pointer << '\n';
    std::cout << "Value through pointer: " << *pointer << '\n';

    *pointer = 100;
    std::cout << "Changed value: " << value << '\n';

    return 0;
}
