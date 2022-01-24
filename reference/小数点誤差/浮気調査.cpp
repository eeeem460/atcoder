#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
const double ESP = 1e-9;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/abc010/tasks/abc010_3


int main() {
    int txa, tya, txb, tyb; cin >> txa >> tya >> txb >> tyb;
    int t, v; cin >> t >> v;
    int n; cin >> n;

    bool can = false;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        double dist = 0;
        dist += sqrt((x - txa) * (x - txa) + (y - tya) * (y - tya));
        dist += sqrt((x - txb) * (x - txb) + (y - tyb) * (y - tyb));

        if (t * v + ESP >= dist) can = true;
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}
