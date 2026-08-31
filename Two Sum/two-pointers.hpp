// Time Complexity: O(nlogn) because sorting the array dominates the runtime. The pointer traversal itself takes O(n).
// Space Complexity: O(n) to store the elements and their original indices in a separate vector.

#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSumTwoPointers(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> numWithIndex(n);
    
    for (int i = 0; i < n; i++) {
        numWithIndex[i] = {nums[i], i};
    }
    
    sort(numWithIndex.begin(), numWithIndex.end());
    
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int currentSum = numWithIndex[left].first + numWithIndex[right].first;
        
        if (currentSum == target) {
            return {numWithIndex[left].second, numWithIndex[right].second};
        } else if (currentSum < target) {
            left++; // Move left pointer to increase the sum
        } else {
            right--; // Move right pointer to decrease the sum
        }
    }
    return {};
}

