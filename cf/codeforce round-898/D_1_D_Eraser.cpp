#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        int count = 0;
        char color[n + 1];
        for(int i = 0 ; i < n; i++)
        {
          cin >> color[i];
        }
        for(int j = 0; j < n; j++)
        {
            if(color[j] == 'B')
            {
                for(int m = j; m <= min(j + k - 1, n - 1); m++)
                {
                    color[m] = 'W';
                }
                j += k - 1;
                count += 1;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}