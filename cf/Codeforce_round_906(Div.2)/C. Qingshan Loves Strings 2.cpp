#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
 int t;
 cin >> t;
 while(t--)
 {
  int n, count0 = 0, count1 = 0;
  cin >> n >> s;
  for(int i = 0; i < n; i++)
  {
    if(s[i] == '0') {count0++; continue;}
    count1++;
  }
  if(count0 != count1)
  {
    cout << "-1" << endl;
    continue;
  }
  deque<char> str;
  vector<int> opr;
  for(int i = 0; i < n; i++)
  {
    str.push_back(s[i]);
  }
  int len = n, del = 0, times = 0;
  while(!str.empty())
  {
    if(str[len - 1] != str[0])
    {
      str.pop_back();
      str.pop_front();
      del++;
      len = len - 2;
    }
    if(str[len - 1] == str[0])
    {
      times++;
      if(str[0] == '0')
      {
        str.push_back('0');
        str.push_back('1');
        opr.push_back(len + del);
      }
      else
      {
        str.push_front('1');
        str.push_front('0');
        opr.push_back(del);
      }
      len += 2;
    }
  }
  cout << times << endl;
  for(vector<int>::const_iterator it = opr.begin(); it != opr.end(); it++)
  {
    cout << *it << ' ';
  }
  cout << endl;
 }
}
