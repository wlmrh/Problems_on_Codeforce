#include <bits/stdc++.h>
using namespace std;

int t;
int n, x;
int a[200005];
int water(int height);

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
  cin >> t;
  while(t--)
  {
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int h = 0;
    long long high = 2'000'000'007, low = 0;
    long long mid = (high + low) / 2;
    while(low + 1 < high)
    {
      if(water(mid) < x){low = mid - 1; mid = (high + low) / 2;}
      if(water(mid) > x){high = mid; mid = (high + low) / 2;}
      if(water(mid) == x){break;}
    }
    printf("%d\n", low);
  }
  return 0;
}



int water(int height)
{
  int result = 0;
  for(int i = 0; i < n; i++)
  {
    if(height > a[i])
    {
      result += (height - a[i]);
    }
  }
  return result;
}