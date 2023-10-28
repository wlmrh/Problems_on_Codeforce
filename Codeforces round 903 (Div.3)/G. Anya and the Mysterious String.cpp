#include <bits/stdc++.h>
using namespace std;
vector<int> command1(4);
vector<int> command2(3);
void cmd1(int start, int end, int add, vector<char> &d);
bool cmd2(int start, int end, vector<char> &d);

int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
  {//数据输入
    int flag = 1;
    int n, m;
    cin >> n >> m;
    vector<char> str;
    for(int i = 0; i < n; i++)
    {
      char letter;
      cin >> letter;
      str.push_back(letter);
    }
    //读入并立即处理指令
    for(int i = 0; i < m; i++)
    {
      int crt;
      cin >> crt;
      if(crt == 1)
      {
        cin >> command1[1] >> command1[2] >> command1[3];
      }
      else
      {
        flag = 2;
        cin >> command2[1] >> command2[2];
      }
      if(flag == 1) {cmd1(command1[1], command1[2], command1[3], str); continue;}
      if(cmd2(command2[1], command2[2], str)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
}

void cmd1(int start, int end, int add, vector<char> &d)
{
  for(int i = start; i <= end; i++)
  {
    d[i] = (d[i] - 'a' + 1 + add) % 26 + 'a' - 1;
  }
}

bool cmd2(int start, int end, vector<char> &d)
{
  int flag = 1;
  while(start <= end)
  {
    if(d[start] != d[end]) {flag = 0; break;}
    start++;
    end--;
  }
  if(flag == 1) return true;
  return false;
}