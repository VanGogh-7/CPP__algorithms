#include <iostream>
#include <vector>

int partition(std::vector<int>& numbers, int low, int high) {
    int pivot = numbers[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (numbers[j] <= pivot) {
            i++;
            std::swap(numbers[i], numbers[j]);
        }
    }

    std::swap(numbers[i + 1], numbers[high]);
    return i + 1;
}

void quickSort(std::vector<int>& numbers, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partition(numbers, low, high);
    quickSort(numbers, low, pivotIndex - 1);
    quickSort(numbers, pivotIndex + 1, high);
}

int main() {
    std::vector<int> numbers{10, 7, 8, 9, 1, 5};
    quickSort(numbers, 0, static_cast<int>(numbers.size()) - 1);

    for (int number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';
    return 0;
}
