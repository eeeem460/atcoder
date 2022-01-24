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

// https://atcoder.jp/contests/abc215/tasks/abc215_d

int main() {
    INCANT;
    int n, m;
    cin >> n >> m;
    const int L = 100000;
    vector<bool> exist(L + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        exist[a] = true;
    }

    vector<bool> isPrime(L + 1, true);
    vector<bool> Pfac(L + 1, false);
    for (int i = 2; i <= L; i++) {
        if (!isPrime[i]) continue;
        if (exist[i]) Pfac[i] = true;
        for (int j = i + i; j <= L; j += i) {
            if (exist[j]) Pfac[i] = true;
            isPrime[j] = false;
        }
    }

    vector<bool> isAns(L + 1, true);
    for (int i = 2; i <= L; i++) {
        if (!Pfac[i]) continue;
        for (int j = i; j <= L; j += i) {
            isAns[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (isAns[i]) cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= m; i++) {
        if (isAns[i]) cout << i << endl;
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
