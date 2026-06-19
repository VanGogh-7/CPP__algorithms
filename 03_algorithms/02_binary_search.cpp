#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& numbers, int target) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == target) {
            return middle;
        }
        if (numbers[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> numbers{1, 3, 5, 7, 9};
    int target = 7;
    int index = binarySearch(numbers, target);

    std::cout << "Target " << target << " found at index: " << index << '\n';
    return 0;
}
