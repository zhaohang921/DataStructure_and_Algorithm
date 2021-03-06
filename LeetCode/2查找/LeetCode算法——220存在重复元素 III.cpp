/*
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，
使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，
并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false
*/

#include <vector>
#include <set>
using namespace std;

// 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        set<long long> record;
        for (int i = 0; i < size; ++i) {
            if (record.lower_bound((long long)nums[i] - (long long)t) != record.end() &&
                *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t)
                return true;
            record.insert(nums[i]);
            // 保持record中最多有k个元素
            if (record.size() == k + 1)
                record.erase(nums[i-k]);
        }
        return false;
    }
};