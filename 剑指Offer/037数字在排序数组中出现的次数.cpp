// 题目描述
// 统计一个数字在排序数组中出现的次数。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//思路：用STL的算法
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return count(data.begin(), data.end(), k);
    }
};

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto i1 = lower_bound(data.begin(), data.end(), k);
        auto i2 = upper_bound(data.begin(), data.end(), k);
        int result = i2 - i1;
        return result;
    }
};

//暴力匹配，时间复杂度第O(n)
//观察数组本身的特性可以发现，排序数组这样做没有充分利用数组的特性，可以使用二分查找，找出数据，然后进行左右进行统计
//具体算法设计：     二分查找找到k的所在位置
//                 在原数组里面分别左右对k的出现次数进行统计
class Solution {
public:
int BinarySearch(vector<int> data, int low, int high, int k)
{
    while (low<=high)
    {
        int m = (high + low) / 2;
        if (data[m] == k)return m;
        else if (data[m] < k) low = m+ 1;
        else high = m - 1;
    }
    return -1;
}
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0)return 0;
         int len=data.size();
        int KeyIndex=0;
         
        KeyIndex=BinarySearch(data,0,len-1,k);
       if(KeyIndex==-1) return 0;
        int sumber=1;
        int m=KeyIndex-1;
        int n=KeyIndex+1;
       
       while(m>=0&&data[m]==k)
        {
                m--;sumber++;
            }
        while(n<len&&data[n]==k)
        {
               n++; sumber++;
            }
        return sumber;
    }
};
