#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 50;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}

// ABC077 C
// upper_bound(a.begin(), a.end(), k) で k < a[i] となる最小のイテレータを返す
//
// auto itr = upper_bound(a.begin(), a.end(), k);
// int index = itr - a.begin();
// で添え字を返す. 下の例の範囲外に注意.
// 
// a.end() - itr で k < a[j] をみたす j の個数

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        auto itr1 = lower_bound(a.begin(), a.end(), b[i]);
        auto itr2 = upper_bound(c.begin(), c.end(), b[i]);
        ans += (itr1 - a.begin()) * (c.end() - itr2);
    }
        
    cout << ans << endl;
}


// cout << fixed << setprecision(10);
