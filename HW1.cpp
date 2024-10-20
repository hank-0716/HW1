#include<iostream>

using namespace std;

const int MAX_M = 3; // 可以輸入的最大值
const int MAX_N = 60000;// 顯示最大值

int fun(int m, int n)
{
	if (m == 0)
	{
		return n + 1;
	}
	else if (n==0)
	{
		return fun(m - 1, 1);
	}
	else
	{
		return fun(m - 1, fun(m, n - 1));
	}
}

int fun1(int m, int n)
{
    int x[MAX_M + 1][MAX_N + 1];

    for (int i = 0; i <= MAX_M; ++i)
    {
        for (int j = 0; j <= MAX_N; ++j)
        {
            if (i == 0)
            {
                x[i][j] = j + 1;
            }
            else if (j == 0)
            {
                x[i][j] = x[i - 1][1];
            }
            else
            {
                x[i][j] = x[i - 1][x[i][j - 1]];
            }
        }
    }

    return x[m][n];
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
       cout << fun(m, n) << endl;
       if (m > MAX_M || n > MAX_N)
       {
           cout << "Values are too large!" << endl;
       }
       else
       {
           cout << fun1(m, n) << endl;
       }
	}
}