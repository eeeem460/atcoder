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


// https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b


int main() {
    int d, n, m; cin >> d >> n >> m;
    vector<int> dist(n); for (int i = 1; i < n; i++) cin >> dist[i];
    vector<int> k(m); for (int i = 0; i < m; i++) cin >> k[i];

    int ans = 0;

    sort(dist.begin(), dist.end());
    dist.push_back(d);

    for (int i = 0; i < m; i++) {
        auto itr = lower_bound(dist.begin(), dist.end(), k[i]);
        int index = itr - dist.begin();

        if (index == 0) continue;
        else {
            int move = min(abs(k[i] - dist[index]), abs(k[i] - dist[index - 1]));
            ans += move;
        }
    }

    cout << ans << endl;
}


// cout << fixed << setprecision(10);

