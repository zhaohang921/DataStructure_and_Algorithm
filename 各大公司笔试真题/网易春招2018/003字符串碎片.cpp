// 一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。
// 例如,"aaabbaaac"是由下面碎片组成的:'aaa','bb','c'。
// 牛牛现在给定一个字符串,请你帮助计算这个字符串的所有碎片的平均长度是多少。
// 输入描述:
// 输入包括一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),s只含小写字母('a'-'z')
// 输出描述:
// 输出一个整数,表示所有碎片的平均长度,四舍五入保留两位小数。
// 如样例所示: s = "aaabbaaac"
// 所有碎片的平均长度 = (3 + 2 + 3 + 1) / 4 = 2.25
// 输入例子1:
// aaabbaaac
// 输出例子1:
// 2.25

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string s;
    cin>>s;
    float length=s.size(); //字符串长度
    float size=1; //碎片种类数
    auto beg=s.begin();
    auto first=beg;
    auto second=++beg;
    while(second!=s.end())
    {
        if(*first!=*second)
            ++size;
        ++first;
        ++second;
    }
    //setiosflags(ios::fixed)是指以固定的浮点显示，
    //当setiosflags(ios::fixed)和setprecision(n)两个一起用时就表示保留n位小数输出。
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<(length/size)<<endl;
    return 0;
}

