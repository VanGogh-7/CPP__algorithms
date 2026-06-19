#include <iostream>
#include <string>

int main() {
    std::string first = "C++";
    std::string second = "Algorithms";
    std::string title = first + " " + second;

    std::cout << title << '\n';
    std::cout << "Length: " << title.size() << '\n';
    std::cout << "First word: " << title.substr(0, 3) << '\n';

    return 0;
}
