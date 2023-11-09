#include <bits/stdc++.h>
using namespace std;
long long a[200005] = {0};
int b[200005] = {0};
int n , c, inter, flag = 0;
bool cmp(const int &num1, const int &num2);

int main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--)
  {
    flag = 0;
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    iota(b + 1, b + n + 1, 1);
    sort(b + 2, b + n + 1, cmp/*[&] (const int &u, const int &v) {
		return 1ll * u * c - a[u] < 1ll * v * c - a[v];
	}*/);
    long long sum = a[1];
    for(int i = 2; i <= n; i++)
    {
      sum += a[b[i]];
      if(sum < 1ll * b[i] * c)
      {
        flag = 1;
        cout << "NO" << endl;
        break;
      }
    }
    if(flag == 0) cout << "YES" << endl;
  }
  return 0;
}

bool cmp(const int &num1, const int &num2)
{
  return 1ll * c * num1 - a[num1] < 1ll * c * num2 - a[num2];
}