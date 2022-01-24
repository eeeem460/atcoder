#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
using Modint = modint1000000007;
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}

// けんちょんさんの記事より

using Data = pair<ll, vector<int> >; 

int main() {
    vector<ll> n(3);
    int k;
    cin >> n[0] >> n[1] >> n[2] >> k;
    vector<vector<ll>> v(3);
    for (int i = 0; i < 3; i++) {
        v[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) cin >> v[i][j];
        sort(v[i].begin(), v[i].end(), greater<ll>());
    }
    priority_queue<Data> que;
    set<Data> st;
    que.push(Data(v[0][0] + v[1][0] + v[2][0], vector<int>({0, 0, 0})));
    for (int i = 0; i < k; i++) {
        auto c = que.top(); que.pop();
        cout << c.first << endl;

        for (int j = 0; j < 3; j++) {
            if (c.second[j] + 1 < n[j]) {
                ll sum = c.first - v[j][c.second[j]] + v[j][c.second[j] + 1];
                auto num = c.second; num[j]++;
                auto d = Data(sum, num);

                if (!st.count(d)) st.insert(d), que.push(d);
            }
        }
    }
}


// cout << fixed << setprecision(10);
