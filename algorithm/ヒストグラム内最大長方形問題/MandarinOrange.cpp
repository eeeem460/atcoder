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

/*
 * ヒストグラム内最大長方形問題
 
 * 問題：https://atcoder.jp/contests/abc189/tasks/abc189_c
 * 
 * 参照：https://qiita.com/kuuso1/items/318d42cd089a49eeb332
 */

int main() {
    INCANT;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ex_right(n, n);  // ex_right[i] = 小さい番号から見て初めて a[i] > a[j] となる j (> i)
    vector<ll> ex_left(n, -1);  // ex_right[i] = 大きい番号から見て初めて a[i] > a[j] となる j (< i)
    stack<ll> stc_right;        // ex_right[i] が未発見の i を入れる
    stack<ll> stc_left;         // ex_left[i] が未発見の i を入れる

    /*
       ex_right を求める
       以下の操作では, stc_right の中身を古い順に {k_0, k_1, k_2, ...} とすると
       常に a[k_0] <= a[k_1] <= a[k_2] <= ... となることが帰納的にわかる
    */
    for (ll i = 0; i < n; i++) {
        // i = ex_right[j] となる, すべての j を求める
        while (!stc_right.empty()) {
            ll tp = stc_right.top();
            if (a[tp] > a[i]) {  // tp の ex_right を発見
                ex_right[tp] = i;
                stc_right.pop();  // ex_right が確定したので削除
            }
            else {  // a[tp] <= a[i] なら帰納的に a[any in stc_right] <= a[i]
                break;
            }
        }

        stc_right.push(i);  // 自身も stc_right へ
    }

    // 同様に ex_left を求める
    for (ll i = n - 1; i >= 0; i--) {
        while (!stc_left.empty()) {
            ll tp = stc_left.top();
            if (a[tp] > a[i]) {
                ex_left[tp] = i;
                stc_left.pop();
            }
            else {
                break;
            }
        }

        stc_left.push(i);
    }

    // ex_right, ex_left の初期値がそれぞれ n, -1 であることに注意してヒストグラム内最大長方形を計算
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        // a[i] を高さとする最大の長方形で更新
        chmax(ans, a[i] * (ex_right[i] - ex_left[i] - 1));
    }

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
