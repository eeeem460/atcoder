#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
using Modint = modint1000000007;
#define debug(x) cerr<<"\033[33m(line:"<<__LINE__<<") "<<x<<"\033[m"<<endl;
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;     // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;


// https://atcoder.jp/contests/abc002/tasks/abc002_4


int main() {
    int n, m; cin >> n >> m;
    vector<unordered_set<int>> p(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        p[x].insert(y);
        p[y].insert(x);
    }

    int ans = 0;

    for (int i = 0; i < (1 << n); i++) {
        bool can = true;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cnt++;
                for (int k = j+1; k < n; k++) {
                    if (i & (1 << k)) {
                        if (!p[j].count(k)) can = false;
                    }
                }
            }
        }

        if (can) chmax(ans, cnt);
    }

    cout << ans << endl;
}


// cout << fixed << setprecision(10);
