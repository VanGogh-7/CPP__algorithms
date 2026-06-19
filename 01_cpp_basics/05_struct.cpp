#include <iostream>

struct Rectangle {
    int width;
    int height;
};

int area(const Rectangle& rectangle) {
    return rectangle.width * rectangle.height;
}

int main() {
    Rectangle box{10, 20};
    Rectangle* pointer = &box;

    std::cout << "Width: " << box.width << '\n';
    std::cout << "Height: " << box.height << '\n';
    std::cout << "Area: " << area(box) << '\n';

    // This is similar to the original main.cpp pointer access demo.
    pointer->width = 15;
    std::cout << "New width through pointer: " << box.width << '\n';

    return 0;
}
