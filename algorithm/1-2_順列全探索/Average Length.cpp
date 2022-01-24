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


// https://atcoder.jp/contests/abc145/tasks/abc145_c


int main() {
    int n; cin >> n;
    vector<int> x(n), y(n); for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<double> dist;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        double cnt = 0;
        for (int i = 0; i < n-1; i++) {
            cnt += sqrt((x[p[i]] - x[p[i+1]])*(x[p[i]] - x[p[i+1]]) + (y[p[i]] - y[p[i+1]])*(y[p[i]] - y[p[i+1]]));
        }

        dist.push_back(cnt);
    } while (next_permutation(p.begin(), p.end()));

    double ans = accumulate(dist.begin(), dist.end(), 0.0) / dist.size();

    cout << fixed << setprecision(10);
    cout << ans << endl;    
}


// cout << fixed << setprecision(10);
