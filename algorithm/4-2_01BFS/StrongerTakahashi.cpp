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

// https://atcoder.jp/contests/abc213/tasks/abc213_e

int main() {
    INCANT;
    ll h, w;
    cin >> h >> w;
    vector s(h, vector<char>(w));

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> dy(4);
    dy = {0, 0, 1, -1};
    vector<int> dx(4);
    dx = {1, -1, 0, 0};
    vector<vector<bool>> visited(h, vector<bool>(w));
    vector<vector<ll>> cnt(h, vector<ll>(w, LINF));
    cnt[0][0] = 0;
    deque<pair<ll, ll>> dq;
    dq.emplace_front(0, 0);

    dbgvv(cnt);

    while (dq.size()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        for (ll i = 0; i < 4; i++) {
            ll xi = x + dx[i], yi = y + dy[i];
            if (xi < 0 || h <= xi || yi < 0 || w <= yi) {
                continue;
            }
            if (s[xi][yi] == '.' && chmin(cnt[xi][yi], cnt[x][y])) {
                dq.emplace_front(xi, yi);
            }
        }

        for (ll Dx = -2; Dx <= 2; Dx++) {
            for (ll Dy = -2; Dy <= 2; Dy++) {
                ll xi = x + Dx, yi = y + Dy;
                if (abs(Dx) + abs(Dy) > 3) {
                    continue;
                }
                if (xi < 0 || h <= xi || yi < 0 || w <= yi) {
                    continue;
                }
                if (chmin(cnt[xi][yi], cnt[x][y] + 1)) {
                    dq.emplace_back(xi, yi);
                }
            }
        }
        
        dbg(x, y);
        dbgvv(cnt);
    }

    cout << cnt[h - 1][w - 1] << endl;
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
