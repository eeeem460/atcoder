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
#define dbgs(x)                         \
    cout << "\033[33m" << x << "\033[m" \
         << " "
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

// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d

int main() {
    INCANT;
    int n, k;
    cin >> n >> k;
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 0; i < 3; i++) dp[1][i] = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < 3; j++)
            if (j != b[i]) dp[a[i]][j] = -1;

    for (int i = 0; i < 3; i++)
        if (dp[1][i] != -1)
            for (int j = 0; j < 3; j++)
                if (dp[2][j] != -1) dp[2][j] += dp[1][i];

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++) {
            if (dp[i][j] == -1) continue;

            for (int k = 0; k < 3; k++) {
                if (dp[i - 1][k] == -1 || j == k) continue;
                dp[i][j] += dp[i - 1][k];
            }

            for (int k = 0; k < 3; k++) {
                if (dp[i - 1][j] == -1 || dp[i - 2][k] == -1 || j == k) continue;
                dp[i][j] += dp[i - 2][k];
            }

            dp[i][j] %= 10000;
        }

    int ans = 0;
    for (int i = 0; i < 3; i++)
        if (dp[n][i] != -1) ans += dp[n][i];
    cout << ans % 10000 << endl;
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
