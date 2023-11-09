#include <bits/stdc++.h>
using namespace std;

int t;
int n, x;
int a[200005];
long long water(int height);

int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while(t--)
  {
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    int h = 0;
    int high = 2'000'000'007, low = 0;
    int mid;
    while(low < high)
    {
      mid = high / 2 + low / 2;
      if(water(mid) < 1ll * x){low = mid + 1;}
      else if(water(mid) > 1ll * x){high = mid - 1;}
      else if(water(mid) == 1ll * x){low = mid; break;}
    }
    if(water(low) > x) low--;
    printf("%d\n", low);
  }
  return 0;
}

long long water(int height)
{
  long long result = 0;
  for(int i = 1; i <= n; i++)
  {
    if(height > a[i])
    {
      result += 1ll * (height - a[i]);
    }
  }
  return result;
}