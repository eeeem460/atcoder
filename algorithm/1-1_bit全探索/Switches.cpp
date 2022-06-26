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


// https://atcoder.jp/contests/abc128/tasks/abc128_c


int main() {
    int n, m; cin >> n >> m;
    vector<unordered_set<int>> a(m);
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int s; cin >> s;
            s--;
            a[i].insert(s);
        }
    }
    for (int i = 0; i < m; i++) cin >> p[i];

    int ans = 0;

    for (int i = 0; i < (1 << n); i++) {
        bool can = true;
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) && a[j].count(k)) cnt++;
            }
            if (cnt % 2 != p[j]) can = false; 
        }
        
        if (can) ans++;
    }

    cout << ans << endl;
}


// cout << fixed << setprecision(10);
