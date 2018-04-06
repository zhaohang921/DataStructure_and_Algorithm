
#include<iostream>
using namespace std;


int roll(int T,int M,int n) //n是第n次旋转
{
    if(n==1)
        return (T+M)%T;
    else
        return (roll(T-1,M,n-1)+M)%T;
}
int main()
{
    // int T,M;
    int T=10,M=2;
    //cout<<"请输入玩家个数：";
    //cin>>T;
    //cout<<"请输入每次旋转相邻的人数：";
    //cin>>M;
    //cout<<endl;
    cout<<"最后吃鸡人的编号是："<<roll(T,M,T-1)<<endl;



    return 0;
}