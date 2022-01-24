#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=ja


int main() {
    int n, w; cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second; 
    }

    vector<int> dp(w + 1);

    for (int i = 0; i <= w; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j].second >= 0) chmax(dp[i], dp[i - a[j].second] + a[j].first);
        }
    }

    cout << dp[w] << endl;
}
