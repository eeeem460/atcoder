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


// https://atcoder.jp/contests/arc121/tasks/arc121_b


int main() {
    INCANT;
    int n;
    cin >> n;
    vector<vector<ll>> v(3);
    for (int i = 0; i < 2 * n; i++) {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R') v[0].push_back(a);
        if (c == 'G') v[1].push_back(a);
        if (c == 'B') v[2].push_back(a);
    }

    if (v[0].size() % 2 == 0 && v[1].size() % 2 == 0 && v[2].size() % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < 3; i++) sort(v[i].begin(), v[i].end());

    auto solve = [&](vector<ll> a, vector<ll> b) {
        ll res = LINF;
        for (int i = 0; i < a.size(); i++) {
            auto itr = lower_bound(b.begin(), b.end(), a[i]);
            // *itr で　itr が指す要素へのアクセス
            if (itr != b.begin()) chmin(res, abs(a[i] - *(itr - 1)));
            if (itr != b.end()) chmin(res, abs(a[i] - *itr));
        }

        return res;
    };

    ll ans = LINF;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (v[i].size() % 2 == 1 && v[j].size() % 2 == 1) {
                chmin(ans, solve(v[i], v[j]));

                int k = 3 - i - j;
                chmin(ans, solve(v[i], v[k]) + solve(v[j], v[k]));
            }
        }
    }

    cout << ans << endl;
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

ll comb(ll n, ll r) {  // comb(60, 30)までオーバーフローなし
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res *= n--;
        res /= i;
    }
    return res;
}
