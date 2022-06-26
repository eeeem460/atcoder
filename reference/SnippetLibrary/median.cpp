#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INCANT cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12)
// const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
void debug_out();
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T);
#ifdef MY_DEBUG
#define dbg(...) debug_out(__VA_ARGS__)
#define dbgs(x) cout << "\033[33m" << x << "\033[m"　<< " "
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


// https://atcoder.jp/contests/arc122/tasks/arc122_b


// 元の vector を変更せずに中央値を返す O(N)
template <class T> double median(const vector<T> &v) {
    vector<T> v_copy = v;  // v をコピー

    int n = v_copy.size() / 2;
    nth_element(v_copy.begin(), v_copy.begin() + n, v_copy.end());
    // v_copy[n]がn番目に大きい値に
    // n番目より前はv_copy[n]以下の値になる

    double nth = v_copy[n];

    if (v_copy.size() % 2 == 1) {
        return nth;
    }
    else {
        auto max_it = max_element(v_copy.begin(), v_copy.begin() + n);
        // n-1番目までの最大値
        return (*max_it + nth) / 2.0;
    }
}
/**********  返り値double!!!!!  **********/

int main() {
    INCANT;
    ll n;
    cin >> n;
    vector<double> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // sort(a.begin(), a.end());

    // double x = 0;
    // if (n % 2 == 1) {
    //     x = a[n / 2];
    // }
    // else {
    //     x = (a[n / 2 - 1] + a[n / 2]) / 2;
    // }
    // x /= 2;

    double x = median(a) / 2.0;

    double ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += x + a[i] - min(a[i], 2 * x);
    }
    ans /= n;

    cout << ans << endl;
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
