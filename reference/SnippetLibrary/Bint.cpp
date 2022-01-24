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
//const int INF = 1e9 + 7;
const ll LINF = (ll)1e18 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;


// https://atcoder.jp/contests/abc192/tasks/abc192_d


#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;

// https://qiita.com/tubo28/items/fa8ee013390184b0ba18

int main() {
    INCANT;
    string x;
    cin >> x;
    ll m;
    cin >> m;

    vector<ll> number(x.size());
    ll maxi = 0;
    for (ll i = 0; i < x.size(); i++) {
        number[i] = x[i] - '0';
        chmax(maxi, number[i]);
    }
    reverse(number.begin(), number.end());

    auto check = [&](ll k) -> bool {
        ll size = number.size();
        Bint sum = number[0];
        if (sum > m) return false;

        Bint cnt = 1;
        for (ll i = 1; i < size; i++) {
            cnt *= k;
            if (cnt > m) return false;
            sum += cnt * number[i];
            if (sum > m) return false;
        }

        return true;
    };

    ll ok = maxi + 1, ng = LINF;
    if (!check(ok)) {
        cout << 0 << endl;
        return 0;
    }
    if (x.size() == 1) {
        cout << 1 << endl;
        return 0;
    }
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok - maxi << endl;
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
