#include <bits/stdc++.h>
using namespace std;
string s, t;
bool initial_judge(string str, int len);

int main()
{
  int time;
  cin >> time;
  while(time--)
  {
    int n, m, flag = 0;
    cin >> n >> m >> s >> t;
    //判断s是否需要操作
    if(initial_judge(s, n)) {cout << "YES" << endl; continue;}
    //判断t是否具备支持s的条件：自身是否01交替出现
    if(!initial_judge(t, m)) {cout << "NO" << endl; continue;}
    //判断t是否具备支持s的条件：首位和末尾是否相等
    if(t[0] != t[m - 1]) {cout << "NO" << endl; continue;}
    char support = t[0];
    for(int i = 0; i <= n - 2; i++)
    {
      if(s[i] == s[i + 1])
      {
        if(s[i] == support) {cout << "NO" << endl; flag = 1; break;}
      }
    }
    if(flag == 0) cout << "YES" << endl;
  }
  return 0;
}

//判断是否01交替出现，true是，false不是
bool initial_judge(string str, int len)
{
  int flag = 1;
  for(int i = 0; i <= len - 2; i++)
  {
    if(str[i] == str[i + 1]) {flag = 0; break;}
  }
  if(flag == 1) return true;
  return false;
}

