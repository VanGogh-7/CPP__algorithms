#include <iostream>
#include <ostream>
#include <string>

struct Student {
    std::string name;
    int age;
    double score;
};


int main() {
    Student student{"van", 20, 90.1};
    Student *p = &student;
    p->name = "van gogh";
    std::cout << p->name << std::endl;

    Student *p1 = new Student{"Bob", 21, 88.0};
    std::cout << p1->name << std::endl;
    std::cout << p1->age << std::endl;
    std::cout << p1->score << std::endl;

    return 0;
}
