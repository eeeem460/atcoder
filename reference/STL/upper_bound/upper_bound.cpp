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

    vector<ll> cntb(n);

    for (int i = 0; i < n; i++) {
        auto ite = upper_bound(b.begin(), b.end(), a[i]);
        int index = ite - b.begin();
        // b = {1, 2, 2, 2, 3} , a[i] = 2 なら index = 4, a[i] = 3 なら index = 5 (範囲外)
        if (index < n) cntb[index]++;
        // イテレータが一番後ろの時に注意     
    }

    for (int i = 0; i < n-1; i++) {
        cntb[i+1] += cntb[i];
    }

    for (int i = 0; i < n; i++) {
        auto ite = upper_bound(c.begin(), c.end(), b[i]);

        ans += (c.end() - ite) * cntb[i];
        // b[i] < c[j] をみたす j の個数
    }
        
    cout << ans << endl;
}


// cout << fixed << setprecision(10);
