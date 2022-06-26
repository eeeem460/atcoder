#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
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
const ll LINF = (ll)1e18 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// https://atcoder.jp/contests/abc191/tasks/abc191_e

// けんちょん本 p.263, 264 参照

struct edge {
    ll to;
    ll w;
    // edge v;
    // v.to, v.w でメンバ変数を呼び出す
    edge(ll to, ll w) : to(to), w(w) {
    }
    // graph[from].push_back(edge(to, w)) の形で使う
};

using graph = vector<vector<edge>>;

int main() {
    INCANT;
    ll n, m;
    cin >> n >> m;
    graph g(n);
    vector<ll> a(m), b(m), c(m);
    for (ll i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(edge(b[i], c[i]));
    }

    for (ll i = 0; i < n; i++) {
        vector<ll> dist(n, LINF);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        for (auto &x : g[i]) {
            auto [to, w] = x;
            if (chmin(dist[to], w)) {
                q.emplace(w, to);
            };
        }

        while (q.size()) {
            auto [d, v] = q.top();
            q.pop();

            // 以下でdは使わないのでこの行はなくてもいいがあった方が速い
            if (d > dist[v]) continue; 
            
            for (auto &x : g[v]) {
                auto [to, w] = x;
                if (chmin(dist[to], dist[v] + w)) {
                    q.emplace(dist[to], to);
                }
            }
        }

        if (dist[i] == LINF)
            cout << -1 << endl;
        else
            cout << dist[i] << endl;
    }
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
    T res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
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
