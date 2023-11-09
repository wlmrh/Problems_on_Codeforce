#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> road;
void dfs(int start, int dont, vector<int> &d);
vector<int> marked;
int t1, t2;

int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
  {
    //输入数据
    int n, k;
    cin >> n >> k;
    road.assign(n + 1, vector<int>(0));
    vector<int> marked;
    for(int i = 0; i < k; i++)
    {
      int a;
      cin >> a;
      marked.push_back(a);
    }
    for(int j = 0; j < n - 1; j++)
    {
      int u, v;
      cin >> u >> v;
      road[u].push_back(v);
      road[v].push_back(u);
    }
    if(k == 1)
    {
      cout << 0 << endl;
      continue;
    }
    //
    vector<int> s1(n + 1);
    t1 = marked[0];
    dfs(marked[0], -1, s1);
    s1[marked[0]] = 0;
    int max = marked[0];
    for(int i : marked)
    {
      if(s1[i] > s1[max]) max = i;
    }
    vector<int> s2(n + 1);
    dfs(max, -1, s2);
    s2[max] = 0;
    max = marked[0];
    for(int i : marked)
    {
      if(s2[i] > s2[max]) max = i;
    }
    cout << (s2[max] + 1) / 2 << endl;
  }
  return 0;
}

void dfs(int start, int dont, vector<int> &d)
{
  for(int i: road[start])
  {
    if(d[i] == 0 && i != dont) {d[i] = d[start] + 1; dfs(i, start, d);}
  }
}