#include <bits/stdc++.h>
using namespace std;
int cal(char k, int i, int j);
double record_count = 0;
char a[1001][1001] = {0};
int n = 0;

int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
  {
    //initialization
    int oper = 0;
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
      for(int j = 1; j <= n ; j++)
      {
        cin >> a[i][j];
      }
    }
    //四个相关旋转位最简调整
    double mid = (1 + n) / 2;
    record_count = mid;
    for(int i = 1; i <= mid; i++)
    {
      for(int j = i; j <= (n - i); j++)
      {
        oper += cal(a[i][j], i, j);
      }
    }
    printf("%d\n", oper);
  }
  return 0;
}

int cal(char k, int i, int j)
{
  int left1 = i - 1, left2 = j - 1;
  int c = k - 'a' + 1;
  int d = a[1 + left2][n - left1] - 'a' + 1;
  int e = a[n - left1][n - left2] - 'a' + 1;
  int f = a[n - left2][1 + left1] - 'a' + 1;
  int final = max(max(max(c, d), e), f);
  return 4 * final - c - d - e - f;
}