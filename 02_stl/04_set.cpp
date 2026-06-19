#include <iostream>
#include <set>

int main() {
    std::set<int> uniqueNumbers{3, 1, 2, 3, 2, 4};

    std::cout << "Unique sorted numbers: ";
    for (int number : uniqueNumbers) {
        std::cout << number << ' ';
    }

    std::cout << "\nContains 3: " << std::boolalpha << uniqueNumbers.contains(3) << '\n';
    return 0;
}
