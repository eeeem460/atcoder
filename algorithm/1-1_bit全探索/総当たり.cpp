#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    int q; cin >> q;
    vector<int> m(q); for (int i = 0; i < q; i++) cin >> m[i];

    unordered_set<int> st;

    for (int j = 0; j < (1 << n); j++) {
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            if (j & (1 << k)) cnt += a[k];
        }
        st.insert(cnt);
    }

    for (int i = 0; i < q; i++) {
        bool can = false;
        if (st.count(m[i])) cout << "yes" << endl;
        else cout << "no" << endl;       
    }
}


// cout << fixed << setprecision(10);
