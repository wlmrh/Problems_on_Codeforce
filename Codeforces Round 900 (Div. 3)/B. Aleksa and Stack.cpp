#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for(int i = 0; i < t ; i++)
  {
    int num = 0;
    cin >> num;
    for(double i = 0; i <= num - 1; i++)
    {
      double m = 3 * i + 1;
      m = round(m);
      printf("%.0lf ", m);
    }
    printf("\n");
  }
  return 0;
}