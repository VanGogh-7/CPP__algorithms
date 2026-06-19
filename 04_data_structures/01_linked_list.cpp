#include <iostream>

struct Node {
    int value;
    Node* next;
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << '\n';
}

int main() {
    Node first{10, nullptr};
    Node second{20, nullptr};
    Node third{30, nullptr};

    first.next = &second;
    second.next = &third;

    printList(&first);
    return 0;
}
