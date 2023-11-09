#include <bits/stdc++.h>
using namespace std;
vector<int> num;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    num.clear();
    num.push_back(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      num.push_back(a);
    }
    int max_s = 1;
    if(n == 1) cout << "YES" << endl;
    while(max_s *= 2)
    {
      if(max_s > n) break;
    }
    max_s /= 2;
    int flag = 0;
    for(int i = 0; pow(2, i) < max_s; i++)
    {
      for(int j = pow(2, i) + 1; j < pow(2, i + 1); j++)
      {
        if(num[j] > num[j + 1]) {flag = 1; break;}
      }
      if(flag == 1) break;
    }
    if(flag == 1) {cout << "NO" << endl; continue;}
    for(int i = max_s + 1; i < n; i++)
    {
      if(num[i] > num[i + 1]) {flag = 1; break;}
    }
    if(flag == 1) {cout << "NO" << endl; continue;}
    cout << "YES" << endl;
  }
  return 0;
}