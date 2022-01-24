#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e


int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> a[i][j];

    int ans = 0;
    for (int bit = 0; bit < (1 << r); bit++) {
        int cnt = 0;
        for (int j = 0; j < c; j++) {
            int ma = 0;
            for (int i = 0; i < r; i++) {
                if (a[i][j] == 1 && (bit & (1 << i))) ma++;
                if (a[i][j] == 0 && (!(bit & (1 << i)))) ma++;
            }
            cnt += max(ma, r - ma);
        }
        chmax(ans, cnt);
    }

    cout << ans << endl;
}
