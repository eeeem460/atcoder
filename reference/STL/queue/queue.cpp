#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
using Modint = modint1000000007;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


int main() {
    //** pair型の要素追加
    {
        queue<pair<int, int>> qu;
        qu.emplace(1, 1);  // emplace(make_pair()), push(make_pair()) とほぼ同じ意味

        auto [q1, q2] = qu.front(); // 各変数に代入 
    }
    
}
