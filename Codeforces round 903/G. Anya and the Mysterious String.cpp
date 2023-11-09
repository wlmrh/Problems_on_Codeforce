#include <bits/stdc++.h>
using namespace std;
vector<int> command1;
vector<int> command2;
vector<char> str;
void cmd1(int start, int end, int add, vector<char> &d);
bool cmd2(int start, int end, vector<char> &d);


int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
  {//数据输入
    str.clear();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
      char letter;
      cin >> letter;
      str.push_back(letter);
    }
    //读入并立即处理指令
    for(int i = 0; i < m; i++)
    {
      command1.clear();
      command2.clear();
      int flag = 1;
      int crt;
      cin >> crt;
      if(crt == 1)
      {
        command1.push_back(1);
        for(int i = 1; i <= 3; i++)
        {
          int crt;
          cin >> crt;
          command1.push_back(crt);
        }
      }
      else
      {
        flag = 2;
        command2.push_back(2);
        for(int i = 1; i <= 2; i++)
        {
          int crt;
          cin >> crt;
          command2.push_back(crt);
        }
      }
      if(flag == 1) {cmd1(command1[1], command1[2], command1[3], str); continue;}
      if(cmd2(command2[1], command2[2], str)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
}

void cmd1(int start, int end, int add, vector<char> &d)
{
  start--;
  end--;
  for(int i = start; i <= end; i++)
  {
    d[i] += add % 26;
    if(d[i] > 'z') d[i] -= 26;
  }
}

bool cmd2(int start, int end, vector<char> &d)
{
  start--;
  end--;
  int flag = 1;
  for(int i = start; i < end; i++)
  {
    if(d[i] == d[i + 1]) return false;
  }
  for(int i = start; i < end - 1; i++)
  {
    if(d[i] == d[i + 2]) return false;
  }
  return true;
}