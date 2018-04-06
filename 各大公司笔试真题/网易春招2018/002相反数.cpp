// 为了得到一个数的"相反数",我们将这个数的数字顺序颠倒,然后再加上原先的数得到"相反数"。
// 例如,为了得到1325的"相反数",首先我们将该数的数字顺序颠倒,我们得到5231,之后再加上原先的数,
// 我们得到5231+1325=6556.如果颠倒之后的数字有前缀零,前缀零将会被忽略。例如n = 100, 颠倒之后是1. 
// 输入描述:
// 输入包括一个整数n,(1 ≤ n ≤ 10^5)
// 输出描述:
// 输出一个整数,表示n的相反数
// 输入例子1:
// 1325
// 输出例子1:
// 6556

#include<iostream>
#include<stack>
using namespace std;

stack<int> a;

int main()
{
    int n=0;
    cout<<"请输入整数："<<endl;
    cin>>n;
    int size=0; //size是整数的位数
    int n_origin=n;
    int m=0; //m是反转之后的整数
    while(n)
    {
        a.push(n%10);
        n/=10;
        ++size;
    }
    int i=1;
    for(;size>0;--size)
    {
        m+=a.top()*i;
        i*=10;
        a.pop();
    }
    cout<<n_origin+m<<endl;
    cout<<endl;
    return 0;
}

