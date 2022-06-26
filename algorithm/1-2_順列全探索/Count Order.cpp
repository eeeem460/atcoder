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


// https://atcoder.jp/contests/abc150/tasks/abc150_c


int main() {
    int n; cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i]; for (int i = 0; i < n; i++) cin >> q[i];
    int a, b;

    vector<int> per(n);
    int cnt = 0;
    iota(per.begin(), per.end(), 1);
    do {
        cnt++;
        if (p == per) a = cnt;
        if (q == per) b = cnt;
    } while (next_permutation(per.begin(), per.end()));
    
    cout << abs(a - b) << endl;
}


// cout << fixed << setprecision(10);
