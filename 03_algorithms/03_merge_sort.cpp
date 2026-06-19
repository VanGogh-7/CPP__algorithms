#include <iostream>
#include <vector>

void merge(std::vector<int>& numbers, int left, int middle, int right) {
    std::vector<int> temp;
    int i = left;
    int j = middle + 1;

    while (i <= middle && j <= right) {
        if (numbers[i] <= numbers[j]) {
            temp.push_back(numbers[i]);
            i++;
        } else {
            temp.push_back(numbers[j]);
            j++;
        }
    }

    while (i <= middle) {
        temp.push_back(numbers[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(numbers[j]);
        j++;
    }

    for (int k = 0; k < static_cast<int>(temp.size()); k++) {
        numbers[left + k] = temp[k];
    }
}

void mergeSort(std::vector<int>& numbers, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSort(numbers, left, middle);
    mergeSort(numbers, middle + 1, right);
    merge(numbers, left, middle, right);
}

int main() {
    std::vector<int> numbers{8, 4, 5, 2, 9, 1};
    mergeSort(numbers, 0, static_cast<int>(numbers.size()) - 1);

    for (int number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';
    return 0;
}
