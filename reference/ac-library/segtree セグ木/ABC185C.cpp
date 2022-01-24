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


// https://atcoder.jp/contests/abc185/tasks/abc185_f


int op(int a, int b) {
    return a ^ b;
}

int e() {
    return 0;
}

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    segtree<int, op, e> seg(a);

    for (int i = 0; i < q; i++) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            seg.set(x - 1, seg.get(x - 1) ^ y); // 要素の更新 O(log n)
        }
        else {
            // 右は半開区間であることに注意
            cout << seg.prod(x - 1, y) << endl; // 区間の積の取得 O(log n)
        }
    }
}
