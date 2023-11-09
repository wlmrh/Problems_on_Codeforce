#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    int small = min({a, b, c});
    if(a == b && b == c) {printf("YES\n"); continue;}
    if(a % small != 0 || b % small != 0 || c % small != 0) {printf("NO\n"); continue;}
    a /= small;
    b /= small;
    c /= small;
    if((a + b + c) <= 6) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}