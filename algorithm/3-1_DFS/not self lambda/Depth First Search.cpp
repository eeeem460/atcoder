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
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int z; cin >> z;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v;
            v--;
            graph[i].push_back(v);
        }
    }

    unordered_set<int> done;
    vector<int> d(n), f(n);
    int cnt = 0;

    function<void(int)> dfs = [&](int k) {
        cnt++;
        d[k] = cnt;
        done.insert(k);
        
        for (auto x : graph[k]) {
            if (!done.count(x)) {
                dfs(x);
            }
        }

        cnt++;
        f[k] = cnt;
        
        return;
    };

    for (int i = 0; i < n; i++) {
        if (!done.count(i)) dfs(i);
    }

    for (int i = 0; i < n; i++) {
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }
}


// cout << fixed << setprecision(10);
