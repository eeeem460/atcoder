#include <bits/stdc++.h>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/abc161/tasks/abc161_d


vector<ll> a;

void dfs (ll n) {
    if (n > 3234566667) return;
    if (n == 0) {
        for (ll i = 1; i <= 9; i++) {
            dfs(i);
        }
        return;
    }

    a.push_back(n);

    for (ll i = max(n % 10 - 1, 0LL); i <= min(n % 10 + 1, 9LL); i++) {
        dfs(10 * n + i);
    }

    return;
}

int main() {
    ll k; cin >> k;

    dfs(0LL);

    sort(a.begin(), a.end());

    cout << a[k-1] << endl;
}


// cout << fixed << setprecision(10);
