#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}


// https://atcoder.jp/contests/abc151/tasks/abc151_d


int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h + 2, vector<char>(w + 2, '#'));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> s[i][j];
        }
    }

    int ans = 0;
    vector<int> dy(4);
    dy = {0, 0, 1, -1};
    vector<int> dx(4);
    dx = {1, -1, 0, 0};

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (s[i][j] == '#') continue;

            int sh = i, sw = j;
            queue<pair<int, int>> qu;
            qu.emplace(sh, sw);
            vector<vector<char>> c = s;
            c[sh][sw] = '#';
            int cnt = 0;

            while (!qu.empty()) {
                int si = qu.size();
                for (int l = 0; l < si; l++) {
                    auto [fr, se] = qu.front();
                    qu.pop();

                    for (int k = 0; k < 4; k++) {
                        int dh = fr + dx[k];
                        int dw = se + dy[k];
                        if (c[dh][dw] == '.') {
                            qu.emplace(dh, dw);
                            c[dh][dw] = '#';
                        }
                    }
                }
                cnt++;
            }
            cnt--;
            chmax(ans, cnt);
        }
    }

    cout << ans << endl;
}
