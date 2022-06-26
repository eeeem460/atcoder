#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja


int main() {
    int n; cin >> n;
    vector<int> s(n); for (int i = 0; i < n; i++) cin >> s[i];
    int q; cin >> q;
    vector<int> t(q); for (int i = 0; i < q; i++) cin >> t[i];

    int ans = 0;

    for (int i = 0; i < q; i++) {
        int left = 0, right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (s[mid] > t[i]) right = mid;
            else left = mid;
        }

        if (s[left] == t[i]) ans++;
    }

    cout << ans << endl;
}


// cout << fixed << setprecision(10);
