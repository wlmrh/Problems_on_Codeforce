#include <bits/stdc++.h>
using namespace std;

double n, k, x = 0;


int main()
{
  double t, min, max;
  cin >> t;
  for(int i = 0; i < t ; i++)
  {
    cin >> n >> k >> x;
    min = (1 + k) * k / 2;
    max = (2 * n - k + 1) * k / 2;
    if(x >= min && x <= max)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}