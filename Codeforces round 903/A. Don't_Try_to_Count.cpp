#include <bits/stdc++.h>
using namespace std;

string x, s;

int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
  {
    int m, n, flag = 0;
    cin >> n >> m >> x >> s;
    int times = 0;
    int string_len = s.length();
    while(x.find(s) == string::npos)
    {
      if(string_len > 25) {flag = 1; break;}
      x = x + x;
      string_len *= 2;
      times++;
    }
    if(flag == 0) cout << times << endl;
    else cout << "-1" << endl;
  }
  return 0;
}