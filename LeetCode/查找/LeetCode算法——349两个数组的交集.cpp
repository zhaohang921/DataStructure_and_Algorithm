/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/

#include <vector>
#include <set>
using namespace std;

// set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto i = nums2.begin(); i != nums2.end(); ++i) {
            if (s.find(*i) != s.end()) {
                res.push_back(*i);
                s.erase(*i);
            }
        }
        return res;
    }
};
