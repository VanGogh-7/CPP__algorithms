#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers{3, 1, 4};
    numbers.push_back(2);

    int sum = 0;
    for (int number : numbers) {
        sum += number;
        std::cout << number << ' ';
    }

    std::cout << "\nSum: " << sum << '\n';
    return 0;
}
