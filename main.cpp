#include <iostream>
#include <ostream>

struct Rectangle {
    int x;
    int y;
};

int main() {
    struct Rectangle *p;
    p = new Rectangle;
    p->x = 10;
    p->y = 20;
    std::cout << p->x << std::endl;
}