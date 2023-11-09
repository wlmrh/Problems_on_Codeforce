#include <bits/stdc++.h>
using namespace std;
map<int, int> lib;
void dispose(int n);

int main()
{
  ios::sync_with_stdio(false);
  int t, a;
  cin >> t;
  while(t--)
  {
    int flag = 0;
    lib.clear();
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
      cin >> a;
      dispose(a);
    }
    for(map<int, int>::iterator it = lib.begin(); it != lib.end(); it++)
    {
      if(it->second % num != 0) {flag = 1; break;}
    }
    if(flag == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

void dispose(int n)
{
  int divider = 2;
  for(divider = 2; divider * divider <= n; divider++)
  {
    if(n % divider == 0)
    {
      if(!lib.count(divider)) lib[divider] = 0;
      while(n % divider == 0)
      {
        n /= divider;
        lib[divider]++;
      }
    }
  }
  if(n != 1)
  {
    if(!lib.count(n)) lib[n] = 0;
    lib[n]++;
  }
}