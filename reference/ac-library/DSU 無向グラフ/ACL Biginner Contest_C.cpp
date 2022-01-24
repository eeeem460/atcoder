#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;  // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9;   // 10^9
const ll LINF = 1e18;  // 10^18, INF と間違えない
const int MOD = 1000000007;

// https://atcoder.jp/contests/abl/tasks/abl_c

int main() {
    int n, m;
    cin >> n >> m;

    dsu d(n);  // O(n) 頂点番号は {0, 1, ..., n-1}
               /*
                  size() は　int型なのでオーバーフローに注意！！！
               */

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        d.merge(a, b);  // O(1)
    }

    cout << d.groups().size() - 1 << endl;  // O(1)
}

// cout << fixed << setprecision(10);
