#include <bits/stdc++.h>
using namespace std;
int a[101] = {0};
int num[2] = {0};
map<int, int> rcd;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    rcd.clear();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      if(rcd.count(a[i]) == 0) rcd[a[i]] = 0;
      rcd[a[i]]++;
    }
    map<int, int>::iterator it = rcd.begin();
    if(rcd.size() >= 3) {cout << "NO" << endl; continue;}
    if(rcd.size() == 2 && abs(it->second - (++it)->second) >= 2) {cout << "NO" << endl; continue;}
    cout << "YES" << endl;
  }
}