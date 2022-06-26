#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
//using Modint = modint1000000007;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;


// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e


int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> a(h + 2, vector<char>(w + 2));
    vector<vector<int>> p(n+1, vector<int>(2));
    int sh, sw;
    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            if (i == 0 || j == 0 || i == h + 1 || j == w + 1) {
                a[i][j] = 'X';
                continue;
            }
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sh = i, sw = j;
            }
            if (1 + '0' <= a[i][j] && a[i][j] <= n + '0') {
                p[a[i][j] - '0'][0] = i;
                p[a[i][j] - '0'][1] = j;
            }
        }
    }

    vector<int> dy(4); dy = {0, 0, 1, -1};
    vector<int> dx(4); dx = {1, -1, 0, 0};

    int ans = 0;

    for (int k = 1; k <= n; k++) {
        vector<vector<char>> c = a;
        int gh = p[k][0], gw = p[k][1];
        queue<pair<int, int>> qu;
        qu.emplace(sh, sw);  // emplace(make_pair), push(make_pair) と同じ意味
        bool can = false;

        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                if (qu.front() == make_pair(gh, gw)) {
                    can = true;
                    break;
                }

                auto [nh, nw] = qu.front(); // 構造化束縛
                qu.pop();
                
                for (int j = 0; j < 4; j++) {
                    int dh = nh + dx[j], dw = nw + dy[j];
                    if (c[dh][dw] != 'X') {
                        qu.emplace(dh, dw);
                        c[dh][dw] = 'X';
                    }
                }
            }
            if (can) break;

            ans++;
        }

        sh = gh, sw = gw;
    }

    cout << ans << endl;
}
