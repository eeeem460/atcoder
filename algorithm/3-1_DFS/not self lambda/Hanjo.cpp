#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std; // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;         // int は 2 * 10^9 まで
const int INF = 1e9; // 10^9
const ll LINF = 1e18;  // 10^18
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/abc165/tasks/abc165_c


int h, w;
vector<vector<bool>> used(16, vector<bool>(16));

ll dfs (int i, int j, int a, int b) {
    if (a < 0 || b < 0) return 0;
    if (i == h) return 1;
    if (j == w) return dfs(i+1, 0, a, b);
    if (used[i][j]) return dfs(i, j+1, a, b);
    
    ll res = 0;
    used[i][j] = true;
    
    res += dfs(i, j+1, a, b-1);

    if (j+1 < w && used[i][j+1] == false) {
        used[i][j+1] = true;
        res += dfs(i, j+1, a-1, b);
        used[i][j+1] = false;
    }

    if (i+1 < h && used[i+1][j] == false) {
        used[i+1][j] = true;
        res += dfs(i, j+1, a-1, b);
        used[i+1][j] = false;
    }

    used[i][j] = false;

    return res;
}

int main() {
    int a, b;
    cin >> h >> w >> a >> b;    

    cout << dfs(0, 0, a, b) << endl;
}
