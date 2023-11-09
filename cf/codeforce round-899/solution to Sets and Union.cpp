#include <bits/stdc++.h>
using namespace std;

int n;
int s[55][55];
int sz[55];//sz数组存储s中每一列中元素的个数
bool f[55];
bool found[55][55];
bool exist[55];
void solve(){
    cin >> n;
    //found, exist 初始化
    for(int i = 1; i <= 50; i++)
        for(int j = 0; j < n; j++)
            found[i][j] = exist[i] = 0;

    for(int i = 0; i < n; i++){
        cin >> sz[i];
        for(int j = 0; j < sz[i]; j++){
            cin >> s[i][j];
            found[s[i][j]][i] = 1;
            exist[s[i][j]] = 1;
        }
    }

    int ans = 0;

    for(int x = 1; x <= 50; x++){
        if(!exist[x])
            continue;
        for(int j = 1; j <= 50; j++)
            f[j] = 0;
        for(int i = 0; i < n; i++){
            if(!found[x][i]){
                for(int j = 0; j < sz[i]; j++)
                    f[s[i][j]] = 1;
            }
        }
        int cnt = 0;
        for(int y = 1; y <= 50; y++)
            cnt += f[y];
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}