#include <iostream>
#include <ostream>
#include <vector>

class solution {
public:
    std::vector<int> find_error_nums(std::vector<int> &nums) {
        const int n = static_cast<int>(nums.size());
        std::vector<int> count(n + 1, 0);

        for (const int num: nums) {
            ++count[num];
        }
        int duplicated = -1;
        int missing = -1;

        for (int num = 1; num <= n; ++num) {
            if (count[num] == 2) {
                duplicated = num;
            } else if (count[num] == 0) {
                missing = num;
            }
        }
        return {duplicated, missing};
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 3, 4};
    std::vector<int> n = solution().find_error_nums(nums);
    for (int num: n) {
        std::cout << num << std::endl;
    }
    return 0;
}
