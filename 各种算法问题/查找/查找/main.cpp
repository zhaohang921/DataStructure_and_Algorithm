#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef int DataType;
int n;
const int MAXN = 1000;
DataType x[MAXN];

int BinarySearch(DataType t)
{
	int l, u, m;
	l = 0;
	u = n - 1;
	while (l <= u)
	{
		m = (l + u) / 2;
		if (x[m] < t)
			l = m + 1;
		else if (x[m] == t)
			return m;
		else
			u = m - 1;
	}
	return -1;
}
int main()
{
	int t;
	while ((cin >> n && cin >> t)!=EOF)
	{
		for (int i = 0; i < n; i++)
			x[i] = 10 * i;	
		cout << BinarySearch(t) << endl;
	}


	return 0;
}