/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/

#include <vector>
#include <algorithm>
using namespace std;

// 对撞指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int l = 0, r = size - 1;
        vector<int> res;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                int res[2] = {l+1, r+1};
                return vector<int>(res, res+2);
            } else if (numbers[l] + numbers[r] < target) {
                ++l;
            } else {
                --r;
            }
        }
        throw invalid_argument("The input has no solution.");
    }
};