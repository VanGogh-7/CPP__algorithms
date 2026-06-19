#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(3);
    minHeap.push(2);

    std::cout << "Min heap order: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << ' ';
        minHeap.pop();
    }

    std::cout << '\n';
    return 0;
}
