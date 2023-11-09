#include <bits/stdc++.h>
using namespace std;

struct string_sort
{
  char letter;
  int order;
};

int main() 
{
  int num = 1;
  int n, k = 0;
  cin >> n >> k;
  string_sort str[n + 1];
  for(int i = 0; i < n; i++)
  {
    cin >> str[i].letter;
  }
  //标号
  for(char i = 97; i <= 97 + 24 ; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(str[j].letter == i)
      {
        str[j].order = num;
        num++;
      }
    }
  }
  //输出
  for(int i = 0; i < n; i++)
  {
    if(str[i].order > k) printf("%c", str[i].letter);
  }
  return 0;
}