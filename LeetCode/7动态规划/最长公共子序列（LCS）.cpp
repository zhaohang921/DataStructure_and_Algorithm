// 一个字符串的子序列，是指从该字符串中去掉任意多个字符后剩下的字符在不改变顺序的情况下组成的新字符串。
// 最长公共子序列，是指多个字符串可具有的长度最大的公共的子序列。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 思路1：递归方法求最长公共子序列的长度
// 用递归的方法优点是编程简单，容易理解。
// 缺点是效率不高，有大量的重复执行递归调用，而且只能求出最大公共子序列的长度，
// 求不出具体的最大公共子序列。

// string a = "ABCBDAB";
// string b = "BDCABA";
// int LCS(int i, int j)
// {
//     if(i >= a.size() || j >= b.size())
//         return 0;
//     if(a[i]==b[j])
//         return 1+LCS(i+1,j+1);
//     else
//         return LCS(i+1,j) > LCS(i,j+1)? LCS(i+1,j):LCS(i,j+1);
// }


class Solution {
public:
    string LCS(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        // 标记方向数组： 1表示左上，2表示向上，3表示向左
        vector<vector<int> > mark(m+1, vector<int>(n+1, -1)); 
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    mark[i][j] = 1;
                } else if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    mark[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j-1];
                    mark[i][j] = 3;
                }
            }
        // 从最后一个
        string res1;
        while (m > 0 && n > 0) {
            if (mark[m][n] == 1) {
                res1.push_back(s1[m-1]);
                --m;
                --n;
            } else if (mark[m][n] == 2) {
                --m;
            } else if (mark[m][n] == 3) {
                --n;
            }
        }
        int size = res1.size();
        string res;
        for (int i = size-1; i >= 0; --i) {
            res.push_back(res1[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    string res = s.LCS("ABCD", "AEBD");
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}



// // 思路2
// // 动态规划采用二维数组来标识中间计算结果，避免重复的计算来提高效率。
// // 《算法导论》 P222
// #include<stdio.h>
// #include<string.h>

// char a[500],b[500];
// char num[501][501]; ///记录中间结果的数组
// char flag[501][501];    ///标记数组，用于标识下标的走向，构造出公共子序列
// void LCS(); ///动态规划求解
// void getLCS();    ///采用倒推方式求最长公共子序列

// int main()
// {
//     int i;
//     strcpy(a,"ABCBDABCCCC");
//     strcpy(b,"BDCABACCCC");
//     memset(num,0,sizeof(num));
//     memset(flag,0,sizeof(flag));
//     LCS();
//     printf("%d\n",num[strlen(a)][strlen(b)]);
//     getLCS();
//     return 0;
// }

// void LCS()
// {
//     int i,j;
//     for(i=1;i<=strlen(a);i++)
//     {
//         for(j=1;j<=strlen(b);j++)
//         {
//             if(a[i-1]==b[j-1])   ///注意这里的下标是i-1与j-1
//             {
//                 num[i][j]=num[i-1][j-1]+1;
//                 flag[i][j]=1;  ///斜向下标记
//             }
//             else if(num[i][j-1]>num[i-1][j])
//             {
//                 num[i][j]=num[i][j-1];
//                 flag[i][j]=2;  ///向右标记
//             }
//             else
//             {
//                 num[i][j]=num[i-1][j];
//                 flag[i][j]=3;  ///向下标记
//             }
//         }
//     }
// }

// void getLCS()
// {

//     char res[500];
//     int i=strlen(a);
//     int j=strlen(b);
//     int k=0;    ///用于保存结果的数组标志位
//     while(i>0 && j>0)
//     {
//         if(flag[i][j]==1)   ///如果是斜向下标记
//         {
//             res[k]=a[i-1];
//             k++;
//             i--;
//             j--;
//         }
//         else if(flag[i][j]==2)  ///如果是斜向右标记
//             j--;
//         else if(flag[i][j]==3)  ///如果是斜向下标记
//             i--;
//     }

//     for(i=k-1;i>=0;i--)
//         printf("%c",res[i]);
// }
