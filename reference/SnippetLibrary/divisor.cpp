#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}

// 第二回日本最強プログラマー学生選手権 C

vector<long long> divisor(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll a, b; cin >> a >> b;
    unordered_set<ll> st;
    ll ans = -1;

    for (int i = b; i >= a; i--) {
        auto v = divisor(i);
        for (auto x : v) {
            if (st.count(x)) chmax(ans, x);
            else st.insert(x);
        }
    }

    cout << ans << endl;
}


// cout << fixed << setprecision(10);
