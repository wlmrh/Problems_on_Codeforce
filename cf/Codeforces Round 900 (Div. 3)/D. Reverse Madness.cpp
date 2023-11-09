#include <bits/stdc++.h>
using namespace std;

int n, k = 0;

int main()
{
  std::ios::sync_with_stdio (0);
  std::cin.tie (0); 
  //输入字符串
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    string str;
    cin >> n >> k;
    int l[k], r[k];
    cin >> str;
    for(int i = 0; i < k ; i++)
    {
      cin >> l[i];
    }
    for(int i = 0; i < k ; i++)
    {
      cin >> r[i];
    }
    //输入modification
    int times, record;
    int deal[n + 1] = {0};
    cin >> times;
    int operation[times];
    for(int k = 0; k < times; k++)
    {
      cin >> operation[k];
      deal[operation[k]]++;
    }
    //find i
    /*
    for(int j = 0; j < times ; j++)
    {
      for(int i = 0; i < k ; i++)
      {
        if(l[i] <= operation[j] && r[i] >= operation[j])
        {
          record = i;
          break;
        }
      }
      //reverse
      int start = min((l[record] + r[record] - operation[j]), operation[j]) - 1;
      int final = max((l[record] + r[record] - operation[j]), operation[j]);
      reverse(str + start, str + final);
    }
    */
   //处理
  for(int i = 0; i <= k - 1; i++)
  {
    int sum = 0;
    for(int j = l[i]; j <= (l[i] + r[i]) / 2; j++)
    {
      sum += deal[j] +  deal[l[i] + r[i] - j];
      if(sum & 1) swap(str[j - 1], str[l[i] + r[i] - j - 1]);
    }
    for(int m = l[i] - 1; m <= r[i] - 1; m++)
    {
      printf("%c", str[m]);
    }
  }
  printf("\n");
  }
}
