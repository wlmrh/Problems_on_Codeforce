#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for(int i = 0; i < t ; i++)
  {
    int n,k;
    int judge = 0;
    cin >> n >> k;
    int array[n];
    for(int i = 0; i < n ; i++)
    {
      cin >> array[i];
    }
    for(int i = 0; i < n; i++)
    {
      if(array[i] == k) judge += 1;
    }
    if(judge > 0) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}