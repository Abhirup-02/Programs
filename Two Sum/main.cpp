#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include "helper.hpp"
#include "brute-force.hpp"
#include "two-pointers.hpp"
#include "hash-map.hpp"

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    cout << "Target: " << target << "\n\n";

    // Test Approach 1
    vector<int> res1 = twoSumBruteForce(nums, target);
    printResult("1. Brute Force", res1);
    
    // Test Approach 2
    vector<int> res2 = twoSumTwoPointers(nums, target);
    printResult("2. Two Pointers", res2);

    // Test Approach 3
    vector<int> res3 = twoSumHashMap(nums, target);
    printResult("3. Hash Map", res3);
}

