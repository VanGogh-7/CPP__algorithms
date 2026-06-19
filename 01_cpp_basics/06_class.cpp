#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    double score;

public:
    Student(std::string name, int age, double score) {
        this->name = name;
        this->age = age;
        this->score = score;
    }

    void print() {
        std::cout << name << ", "
                  << age << ", "
                  << score << '\n';
    }
};

int main() {
    Student s("Alice", 20, 95.5);

    s.print();

    return 0;
}

