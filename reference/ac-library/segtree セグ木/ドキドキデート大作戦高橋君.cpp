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

// https://atcoder.jp/contests/arc045/tasks/arc045_b

#include <atcoder/all>
using namespace atcoder;
using Modint = modint1000000007;

ll op(ll a, ll b) {
    return a * b;
}

ll e() {
    return 1;
}

int main() {
    INCANT;
    ll n, m;
    cin >> n >> m;
    vector<ll> s(m), t(m);
    vector<ll> room(n + 1);
    for (ll i = 0; i < m; i++) {
        cin >> s[i] >> t[i];
        s[i]--, t[i]--;
        room[s[i]]++;
        room[t[i] + 1]--;
    }

    for (ll i = 0; i < n; i++) {
        room[i + 1] += room[i];
    }
    for (ll i = 0; i < n + 1; i++) {
        if (room[i] > 1)
            room[i] = 1;
        else
            room[i] = 0;
    }

    segtree<ll, op, e> seg(n);
    for (ll i = 0; i < n; i++) {
        seg.set(i, room[i]);
    }

    ll cnt = 0;
    vector<ll> ans;
    for (ll i = 0; i < m; i++) {
        if (seg.prod(s[i], t[i] + 1)) {
            cnt++;
            ans.push_back(i + 1);
        }
    }

    cout << cnt << endl;
    for (auto& x : ans) {
        cout << x << endl;
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
