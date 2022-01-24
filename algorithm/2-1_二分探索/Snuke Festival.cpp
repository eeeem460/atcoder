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


// https://atcoder.jp/contests/abc077/tasks/arc084_a


int main() {
    int n; cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;

    vector<ll> cntb(n+2);

    b.push_back(INF);

    for (int i = 1; i <= n; i++) {
        int left = 0, right = n + 1;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (b[mid] > a[i]) right = mid;
            else left = mid;
        }
        cntb[right]++;     
    }

    for (int i = 0; i <= n; i++) {
        cntb[i+1] += cntb[i];
    }

    c.push_back(INF);

    for (int i = 1; i <= n; i++) {
        int left = 0, right = n+1;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (c[mid] > b[i]) right = mid;
            else left = mid;
        }

        ans += (n - left) * cntb[i];
    }
        
    cout << ans << endl;
}


// cout << fixed << setprecision(10);
