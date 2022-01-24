#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=ja


int main() {
    while (true) {
        int w, h; cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<vector<int>> c(h+2, vector<int>(w+2));
        for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin >> c[i][j];

        int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        
        function<void(int, int)> dfs = [&](int s, int t) {
            c[s][t] = 0;
            for (int i = 0; i < 8; i++) {
                int x = s + dx[i];
                int y = t + dy[i];
                if (c[x][y] == 1) dfs(x, y);
            }           
        };

        ll ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (c[i][j] == 1) {
                    ans++;
                    dfs(i, j);
                }
            }
        }

        cout << ans << endl;
    }
}


// cout << fixed << setprecision(10);
