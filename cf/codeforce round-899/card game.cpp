#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++)
    {
        //初始化，输入数据
        int a[55][55] = {{0}};
        int size[55] = {0};
        int num;//数组的个数
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            cin >> size[j];
            for(int m = 0; m < size[j]; m++)
            {
                cin >> a[j][m];
            }
        }
        //appear计算每个数字出现的次数
        int appear[50] = {0};
        for(int j = 0; j < num; j++)
        {
            for(int m = 0; m < size[j]; m++)
            {
                appear[a[j][m]] += 1;
            }
        }
        //计算出现的数字的总数
        int nb =0;
        for(int j = 0; j < 50 ; j++)
        {
            if(appear[j] != 0) nb += 1;
        }
        //计算每个数组中只出现一次的数的个数并存储到数组compare中
        int compare[55] = {0};
        for(int j = 0; j < num; j++)
        {
             for(int m = 0; m < size[j]; m++)
            {
                if(appear[a[j][m]] == 1)
                {
                    compare[j] += 1;
                }
            }
        }
        //找到最小正数,用final存储
        int final;
        sort(compare, compare + num, greater<int>());
        for(int j = num - 1; j >= 0; j--)
        {
            if(compare[j] != 0) final = compare[j];
        }
        printf("%d\n", nb - final);
    }
    return 0;
}