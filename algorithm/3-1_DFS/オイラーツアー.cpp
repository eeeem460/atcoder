#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INCANT cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12)
#ifdef MY_DEBUG
#define dbg(...) debug_out(__VA_ARGS__)
#define dbgv(v) debug_vector(v)
#define dbgvv(vv) debug_vvector(vv)
#else
#define dbg(...)
#define dbgv(v)
#define dbgvv(vv)
#endif
void debug_out();
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T);
template <typename Vec> void debug_vector(Vec V);
template <typename Vvec> void debug_vvector(Vvec Vv);
template <class T> bool chmax(T &, const T &);
template <class T> bool chmin(T &, const T &);
template <class T> T pwr(T, ll);
template <class T> T squ(T);
ll fact(ll);
ll comb(ll, ll);
// const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// https://atcoder.jp/contests/abc213/tasks/abc213_d

int main() {
    INCANT;
    ll n;
    cin >> n;
    vector<ll> a(n - 1), b(n - 1);
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for (auto &x : g) {
        sort(x.begin(), x.end());
    }

    vector<ll> ans;

    auto dfs = [&](auto self, ll cor, ll pre) -> void {
        ans.push_back(cor);

        for (auto next : g[cor]) {
            if (next == pre) continue;
            self(self, next, cor);
            ans.push_back(cor);
        }
    };

    dfs(dfs, 0, -1);

    for (auto x : ans) {
        cout << x + 1 << " ";
    }
    cout << endl;
}

/*


























-----------------------------------MY_FUNCTIONS------------------------------------ */

void debug_out() {
    cout << endl;
}

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cout << "\033[33m" << H << "\033[m"
         << " ";
    debug_out(T...);
}

template <typename Vec> void debug_vector(Vec V) {
    cout << endl;
    for (auto v : V) {
        cout << "\033[33m" << v << "\033[m"
             << " ";
    }
    cout << endl << endl;
}

template <typename Vvec> void debug_vvector(Vvec Vv) {
    cout << endl;
    for (auto V : Vv) {
        for (auto v : V) {
            cout << "\033[33m" << v << "\033[m"
                 << " ";
        }
        cout << endl;
    }
    cout << endl;
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

ll comb(ll n, ll r) {  // comb(60, 30)までオーバーフローなし
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res *= n--;
        res /= i;
    }
    return res;
}
