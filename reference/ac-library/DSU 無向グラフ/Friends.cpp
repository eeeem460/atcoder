#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using Modint = modint1000000007;
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/abc177/tasks/abc177_d


int main() {
    int n, m; cin >> n >> m;

    dsu d(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        d.merge(a, b);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        chmax(ans, d.size(i));  // O(α(n)) は O(log n) よりも小さい!!!
    }

    cout << ans << endl;
}
