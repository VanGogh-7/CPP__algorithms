#include <iostream>
#include <istream>
#include <memory>

struct Point_2d {
    int x;
    int y;
    void print() {
        std::cout << x << "," << y << std::endl;
    }
};

class Point_3d {
    int x;
    int y;
    int z;
    void print() {
        std::cout << x << "," << y << ',' << std::endl;
    }
};


int main() {
    std::unique_ptr<int[]> ptr1(new int[10]);
    auto ptr2 = std::make_unique<int[]>(10);

    std::shared_ptr<int[]> ptr3(new int[10]);
    auto ptr4 = ptr3;

    for (int i = 0; i < 10; i++) {
        ptr1[i] = i * i;
    }
    std::cout << ptr1[4] << std::endl;
    return 0;
}
