#include "../include/random.hpp"
#include<vector>
#include<random>
#include<algorithm>

std::vector<int> makeRandom(int max) {
    std::vector<int> nums(max);
    for(int i=0; i<max; i++) {
        nums[i] =  i + 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    shuffle(nums.begin(), nums.end(), gen);
    return nums;
}
