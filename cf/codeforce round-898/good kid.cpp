#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        int n;
        int max = 0;
        scanf("%d", &n);
        int a[n];
        for(int j = 0; j <= n - 1 ; j++)
        {
            cin >> a[j];
        }
        for(int j = 0; j <= n - 1; j++)
        {
            a[j] += 1;
            int result = 1;
            for(int k = 0; k <= n - 1; k++)
            {
                result *= a[k];
            }
            if(result > max)
            {
                max = result;
            }
            a[j] -= 1;
        }
        printf("%d\n", max);
    }
    return 0;
}