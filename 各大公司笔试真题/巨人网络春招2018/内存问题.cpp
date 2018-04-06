/*
字节对齐主要是为了提高内存的访问效率，比如intel 32为cpu，
每个总线周期都是从偶地址开始读取32位的内存数据，
如果数据存放地址不是从偶数开始，则可能出现需要两个总线周期才能读取到想要的数据，
因此需要在内存中存放数据时进行对齐。
通常我们说字节对齐很多时候都是说struct结构体的内存对齐

内存对齐的三大规则：
1.对于结构体的各个成员，第一个成员的偏移量是0，排列在后面的成员其当前偏移量必须是当前成员类型的整数倍
2.结构体内所有数据成员各自内存对齐后，结构体本身还要进行一次内存对齐，
    保证整个结构体占用内存大小是结构体内最大数据成员的最小整数倍
3.如程序中有#pragma pack(n)预编译指令，则所有成员对齐以n字节为准(即偏移量是n的整数倍)，
    不再考虑当前类型以及最大结构体内类型
*/
#include<iostream>
using namespace std;

//在32位中占用内存应该是注释中一样
struct A{
    char a[6];      //6        偏移量是0
    int b;          //4+2      偏移量是6，偏移量必须是当前类型的整数倍，所以要加上两个内存，让偏移量是4的整数倍8
    long long c;    //8+4      偏移量是12，所以要加上4个内存，让偏移量是8的整数倍16 
    char d[6];      //6        偏移量是24，是6的整数倍
    int e;          //4+2      偏移量是30，所以要加上2个内存，让偏移量是4的整数倍32
    int f;          //4        偏移量是36，是4的整数倍
    int *g;         //4        偏移量40
};                  //48

struct B{
    char a[6];     //6
    char b[6];     //6
    long long c;   //8+4
    int d;         //4
};                 //32

struct C : public A ,public B
{
    char a[6];
    int b;
    long long c;
};                 //104

int main()
{
    int a=sizeof(A);
    int b=sizeof(B);
    int c=sizeof(C);
    cout<<"a="<<a<<" "<<"b="<<b<<" "<<"c="<<c<<endl;
    int int_test=4;
    int* int_test1;
    float float_test=13.2;
    long long_test=2;
    long long longlong_test=21;
    char char_test='s';
    char char_test1[6];

    cout<<"sizeof(int_test)"<<sizeof(int_test)<<endl;
    cout<<"sizeof(int_test1)"<<sizeof(int_test1)<<endl;
    cout<<"sizeof(float_test)"<<sizeof(float_test)<<endl;
    cout<<"sizeof(long_test)"<<sizeof(long_test)<<endl;
    cout<<"sizeof(longlong_test)"<<sizeof(longlong_test)<<endl;
    cout<<"sizeof(char_test)"<<sizeof(char_test)<<endl;
    cout<<"sizeof(char_test1)"<<sizeof(char_test1)<<endl;

    cout << "type: \t\t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t\t" << "所占字节数：" << sizeof(bool);  
    cout << "\t最大值：" << (numeric_limits<bool>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;  
    cout << "char: \t\t\t" << "所占字节数：" << sizeof(char);  
    cout << "\t最大值：" << (numeric_limits<char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;  
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);  
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;  
    cout << "wchar_t: \t\t" << "所占字节数：" << sizeof(wchar_t);  
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;  
    cout << "short: \t\t\t" << "所占字节数：" << sizeof(short);  
    cout << "\t最大值：" << (numeric_limits<short>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;  
    cout << "int: \t\t\t" << "所占字节数：" << sizeof(int);  
    cout << "\t最大值：" << (numeric_limits<int>::max)();  
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;  
    cout << "unsigned: \t\t" << "所占字节数：" << sizeof(unsigned);  
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;  
    cout << "long: \t\t\t" << "所占字节数：" << sizeof(long);  
    cout << "\t最大值：" << (numeric_limits<long>::max)();  
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;  
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);  
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;  
    cout << "double: \t\t" << "所占字节数：" << sizeof(double);  
    cout << "\t最大值：" << (numeric_limits<double>::max)();  
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;  
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);  
    cout << "\t最大值：" << (numeric_limits<long double>::max)();  
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;  
    cout << "float: \t\t\t" << "所占字节数：" << sizeof(float);  
    cout << "\t最大值：" << (numeric_limits<float>::max)();  
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;  
    cout << "size_t: \t\t" << "所占字节数：" << sizeof(size_t);  
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();  
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;  
    cout << "string: \t\t" << "所占字节数：" << sizeof(string) << endl;  
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t\t" << "************size**************"<< endl;  
    return 0;
}