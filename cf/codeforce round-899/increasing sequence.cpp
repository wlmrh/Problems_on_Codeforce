#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++)
    {
        //初始化，输入数据
        int a[105] = {0}, n = 0;
        int b[105] = {0};
        cin >> n;
        for(int j = 0; j < n ; j++)
        {
            b[j] = j + 1;
        }
        for(int j = 0; j < n ; j++)
        {
            cin >> a[j];
        }
        //对b数组进行调整
        for(int j = 0; j < n ; j++)
        {
            if(b[j] == a[j])
            {
                for(int m = j; m < n ; m++)
                {
                    b[m] += 1;
                }
            }
        }
        printf("%d\n", b[n-1]);
    }
    return 0;
}