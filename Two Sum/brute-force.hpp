// Time Complexity: O(n^2) due to the nested loops.
// Space Complexity: O(1) because it uses no extra memory.

#include <vector>

std::vector<int> twoSumBruteForce(std::vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // No solution found
}
