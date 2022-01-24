#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INCANT cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12)
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
void debug_out();
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T);
#ifdef MY_DEBUG
#define dbg(...) debug_out(__VA_ARGS__)
#define dbgs(x) cout << x << " "
#define dbge cout << endl
#else
#define dbg(...)
#define dbgs(x)
#define dbge
#endif
template <class T> bool chmax(T &, const T &);
template <class T> bool chmin(T &, const T &);
template <class T> T pwr(T, ll);
template <class T> T squ(T);
ll fact(ll);
ll comb(ll, ll);

// https://atcoder.jp/contests/abc138/tasks/abc138_d

int main() {
    INCANT;
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> cnt(n);
    for (int i = 0; i < q; i++) {
        int p, x; cin >> p >> x;
        p--;
        cnt[p] += x;
    }

    auto dfs = [&](auto self, int now, int before) -> void { // self(self, );
        if (g[now].empty()) return;
        else {
            for (auto x : g[now]) {
                if (x != before) {
                    cnt[x] += cnt[now];
                    self(self, x, now);
                }
            }
            return;
        }
    };

    dfs(dfs, 0, -1);

    for (auto x : cnt) {
        cout << x << " ";
    }
    cout << endl;
}

/*





















-----------------------------------以下関数宣言------------------------------------ */

void debug_out() {
    cout << endl;
}

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cout << H << " ";
    debug_out(T...);
}

template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template <class T> T pwr(T x, ll n) {
    T ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= x;
    }
    return ans;
}

template <class T> T squ(T x) {
    return x * x;
}

ll fact(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) res *= i;
    return res;
}

ll comb(ll n, ll r) {
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res *= n--;
        res /= i;
    }
    return res;
}
