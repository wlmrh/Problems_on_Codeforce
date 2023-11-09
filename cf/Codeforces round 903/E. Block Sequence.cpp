#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int dp[200005];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    dp[n+1]=0;
    for(int i = n; i >= 1; i--)
    {
      if(i+a[i] > n) dp[i] = dp[i+1] + 1;
      else dp[i] = min(dp[i+1] + 1,dp[i + a[i] + 1]);
    }
    cout << dp[1] << endl;
  }
  return 0;
}
