// Time Complexity: O(n) because hash map lookups take O(1) on average, and we loop through the array exactly once.
// Space Complexity: O(n) to store up to n elements in the hash map.

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumHashMap(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // Value -> Original Index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // If complement exists in map, return its index and current index
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        
        // Otherwise, store current number and index
        seen[nums[i]] = i;
    }
    return {};
}
