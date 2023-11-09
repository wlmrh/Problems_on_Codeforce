#include <bits/stdc++.h>
using namespace std;

int len(string str);

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    string a;
    cin >> a;
    if(len(a) <= 10) {cout << a; printf("\n");}
    else
    {
      printf("%c%d%c\n", a[0], len(a) - 2, a[len(a) - 1]);
    }
  }
  return 0;
}

int len(string str)
{
  int count = 0, i = 0;
  while(str[i] != '\0')
  {
    count += 1;
    i++;
  }
  return count;
}