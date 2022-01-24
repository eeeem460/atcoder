#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


int main() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        int u, k; cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v;
            v--;
            G[i].push_back(v);
        }
    }

    vector<int> d(n, -1);
    queue<int> qu;

    qu.push(0);
    d[0] = 0;

    while (!qu.empty()) {
        int k = qu.front();
        qu.pop();

        for (auto x : G[k]) {
            if (d[x] != -1) continue;

            qu.push(x);
            d[x] = d[k] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i+1 << " " << d[i] << endl;
    }
}


// cout << fixed << setprecision(10);
