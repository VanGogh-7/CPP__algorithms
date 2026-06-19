#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores;
    scores["Alice"] = 90;
    scores["Bob"] = 82;
    scores["Carol"] = 95;

    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << '\n';
    }

    std::cout << "Bob's score: " << scores["Bob"] << '\n';
    return 0;
}
