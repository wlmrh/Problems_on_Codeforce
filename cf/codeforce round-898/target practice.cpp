#include <bits/stdc++.h>
using namespace std;

int main()
{
    char target[10][10];
    int t;
    cin >> t;
    for(int i = 1; i <= t ; i++)
    {
        int score = 0;
        //输入数据
        for(int m = 0; m < 10 ; m++)
        {
            for(int n = 0; n < 10 ; n++)
            {
                cin >> target[m][n];
            }
        }
        //计算得分
         for(int m = 0; m < 10 ; m++)
        {
            for(int n = 0; n < 10 ; n++)
            {
                if(target[m][n] == 'X')
                {
                    score += min({m+1 , n+1 , 10 - m , 10 - n});
                }
            }
        }
        printf("%d\n", score);
    }
    return 0;
}