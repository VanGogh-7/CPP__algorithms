#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& numbers) {
    for (int i = 1; i < static_cast<int>(numbers.size()); i++) {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = key;
    }
}

int main() {
    std::vector<int> numbers{5, 2, 4, 6, 1, 3};
    insertionSort(numbers);

    for (int number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';
    return 0;
}
