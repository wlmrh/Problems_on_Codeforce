#include <bits/stdc++.h>
using namespace std;

int pref[200001][31] = {0};//pref[位置][位数] = {位值}
int n, t = 0;
void pre_build(int a[]);
int get_value(int l, int r);

int main()
{
  cin >> t;
  while(t--)
  {
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    pre_build(a); 
    int q, l, k;
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
      cin >> l >> k;
      if(a[l] < k) {cout << -1 << " "; continue;}
      //二分查找r
       int lo =  l;
        int hi = n;
        int ans = l;
        while(lo <= hi){
            int s = (lo + hi) / 2;
            int num = 0;
            num = get_value(lo, s);
            if(num >= k){
                lo = s+1;
                ans = max(ans, s);
            }
            else hi = s - 1;
        }
        cout << ans << '\n';
    }
  }
}

void pre_build(int a[])
{
  for(int j = 1; j <= n; j++)
  {
    for(int i = 1; i <= j; i++)
    {
      for(int m = 1; m <= 30; m++)
      {
        if((a[i] & (1 << (m - 1))) != 0)
        {
          pref[j][m]++;
        }
      }
    }
  }
  return;
}

int get_value(int l, int r)
{
  int value = 0;
  for(int i = 1; i <= 30; i++)
  {
    if((pref[r][i] - pref[l - 1][i]) == r - l + 1)
    {
      value +=  1 << (i - 1);
    }
  }
  return value;
}