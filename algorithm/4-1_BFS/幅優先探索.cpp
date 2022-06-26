#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
using Modint = modint1000000007;
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;     // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/abc007/tasks/abc007_3


int main() {
    int r, c; cin >> r >> c;
    int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    pair<int, int> s(sy, sx);
    pair<int, int> g(gy, gx);

    vector<vector<char>> a(r, vector<char>(c));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> a[i][j];
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    int cnt = 0;
    bool can = false;

    queue<pair<int, int>> qu;
    qu.push(s);
    a[s.first][s.second] = '#';

    while (!qu.empty()) {
        int si = qu.size();
        for (int i = 0; i < si; i++) {
            pair<int, int> t = qu.front();
            qu.pop();

            if (t == g) {
                can = true;
                break;
            }

            for (int j = 0; j < 4; j++) {
                int y = t.first + dy[j], x = t.second + dx[j];
                if (a[y][x] == '.') {
                    qu.push(make_pair(y, x));
                    a[y][x] = '#';
                }
            }
        }

        if (can) break;

        cnt++;
    }

    cout << cnt << endl;
}


// cout << fixed << setprecision(10);

