#include <iostream>
#include <string>

int main() {
    int age = 20;
    double score = 95.5;
    char grade = 'A';
    bool passed = true;
    std::string name = "Alice";

    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Score: " << score << '\n';
    std::cout << "Grade: " << grade << '\n';
    std::cout << "Passed: " << std::boolalpha << passed << '\n';

    return 0;
}
