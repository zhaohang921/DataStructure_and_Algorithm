/*
快速排序

快速排序的最差时间复杂度和冒泡排序是一样的都是O(N2)，它的平均时间复杂度为O(NlogN)

从小到大排序，步骤：
找一个基准数（假设为最左边的数），将小于基准数的都放在基准数的左边，大于基准数的都放在基准数的右边
设置两个哨兵，一个在最左边，一个在最右边，
右哨兵先从右往左找比基准数小的数，找到就停下
左哨兵再从左往右找比基准数大的数，找到就停下
交换两个哨兵的数
按照上述步骤继续找，右哨兵先找，左哨兵再找，直到两个哨兵在同一个位置就停下
将基准数与这两个哨兵的数交换


*/

#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;


void QuickSort(vector<int>& a,int lhs,int rhs){
    int i=lhs,j=rhs,temp=a[lhs];  //temp就是基准数
    if(lhs>rhs)
        return;
    while(i!=j){
        while(a[j]>=temp && i<j) //先从右边开始找比temp小的
            --j;
        while(a[i]<=temp && i<j) //再从左边找比temp大的
            ++i;
        if(i<j)
            swap(a[i],a[j]); //将找到的两个树交换
    }
    swap(a[lhs],a[i]);
    // for(auto i : a){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
    QuickSort(a,lhs,i-1);
    QuickSort(a,i+1,rhs);
}

int main(){
    vector<int> a;
    a.push_back(23);
    a.push_back(466);
    a.push_back(5);
    a.push_back(26);
    a.push_back(87);
    a.push_back(63);
    a.push_back(8);
    a.push_back(34);
    a.push_back(267);
    a.push_back(2424);
    a.push_back(5);
    a.push_back(646);
    cout<<"原来的顺序："<<endl;
    for(auto i : a){
        cout<<i<<' ';
    }
    cout<<endl;
    QuickSort(a,0,a.size()-1);

    cout<<"快速排序结果：";
    for(auto i : a){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}

