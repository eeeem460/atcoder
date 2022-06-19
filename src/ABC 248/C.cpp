#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
#define INCANT cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12)
#ifdef MY_DEBUG
#define dbg(...) debug_out(__VA_ARGS__)
#define dbgn(var) debug_out(#var, "=", var)
#else
#define dbg(...)
#define dbgn(...)
#endif
void debug_out();
void debug_out(vector<ll>);
void debug_out(vector<vector<ll>>);
template <class Head, class... Tail> void debug_out(Head, Tail...);
template <class T> bool chmax(T&, const T&);
template <class T> bool chmin(T&, const T&);
template <class T> T pwr(T, ll);
template <class T> T squ(T);
ll fact(ll);
ll comb(ll, ll);
ll ctoll(char);
const ll LINF = (ll)1e18 + 7;
const double EPS = 1e-9;
const int MAX_DUBUG_SIZE = 10;

#include <atcoder/math>
#include <atcoder/modint>
using namespace atcoder;
// const int MOD = 1e9 + 7;
// using Modint = modint1000000007;
// ostream& operator<<(ostream& os, const Modint& N) {
//     return os << N.val();
// }

const int MOD = 998244353;
using Modint = modint998244353;
ostream& operator<<(ostream& os, const Modint& N) {
    return os << N.val();
}

int main() {
    INCANT;
    ll n, m, k;
    cin >> n >> m >> k;

    // dp[i][j] = 部分列{A_0, ..., A_i}の和が j となる通り数
    vector dp(n, vector<Modint>(n * m + 1));
    for (ll i = 1; i <= m; i++) {
        dp[0][i] = 1; // A_0 = i のとき
    }
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 1; j <= n * m; j++) {
            // dp[i][j]からの遷移を考える．
            // つまり，A_0 + ... + A_i = j のとき，次の A_{i+1} の値によって場合分け

            for (ll k = 1; k <= m; k++) { // A_{i+1} = k のとき
                if (j + k <= n * m) dp[i + 1][j + k] += dp[i][j];
            }
        }
    }

    Modint ans = 0;
    for (ll i = 0; i <= k; i++) {
        ans += dp[n - 1][i];
    }

    cout << ans << endl;
}

/*



























-----------------------------------MY_FUNCTIONS------------------------------------ */
template <class First, class Second> ostream& operator<<(ostream& os, const pair<First, Second>& pp) {
    return os << "{" << pp.first << "," << pp.second << "}";
}

template <class T> ostream& operator<<(ostream& os, const vector<T>& V) {
    if (V.empty()) return os << "[]";
    os << "[";
    for (ll i = 0; i < V.size(); i++) {
        os << V[i] << (i == int(V.size() - 1) ? "]" : ",");
    }
    return os;
}

template <class T> ostream& operator<<(ostream& os, const vector<vector<T>>& VV) {
    if (VV.empty()) return os << "[[]]";
    os << "[\n";
    for (auto&& V : VV) {
        os << V << "\n";
    }
    os << "]";
    return os;
}

template <class T> ostream& operator<<(ostream& os, const vector<vector<vector<T>>>& VVV) {
    if (VVV.empty()) return os << "[[[]]]";
    os << "["
       << "\n";
    int cnt = 0;
    for (auto&& VV : VVV) {
        os << cnt++ << VV << "\n\n";
    }
    os << "]";
    return os;
}

template <class T> ostream& operator<<(ostream& os, const set<T>& SS) {
    if (SS.empty()) return os << "[]";
    os << "[";
    auto ii = SS.begin();
    for (; ii != SS.end(); ii++) os << *ii << (ii == prev(SS.end()) ? "]" : ",");
    return os;
}

template <class Key, class Tp> ostream& operator<<(ostream& os, const map<Key, Tp>& MM) {
    if (MM.empty()) return os << "[{:}]";
    os << "[";
    auto ii = MM.begin();
    for (; ii != MM.end(); ii++)
        os << "{" << ii->first << ":" << ii->second << "}" << (ii == prev(MM.end()) ? "]" : ",");
    return os;
}

void debug_out() {
    cout << endl;
}

void debug_out(vector<ll> V) {
    const int MAX_SIZE = min((int)V.size(), MAX_DUBUG_SIZE);

    cout << "\033[33m";
    if (V.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < MAX_SIZE; i++) {
        if (V[i] == LINF)
            cout << "INF";
        else
            cout << V[i];

        if (i == (int)V.size() - 1)
            cout << "]\n";
        else if (i == MAX_DUBUG_SIZE - 1)
            cout << ",...\n";
        else
            cout << ",";
    }
    return;
}

void debug_out(vector<vector<ll>> VV) {
    cout << "\033[33m";
    if (VV.empty()) {
        cout << "[[]]" << endl;
        return;
    }
    cout << "[\n";

    int MAX_ROW = min((int)VV.size(), MAX_DUBUG_SIZE);
    for (int i = 0; i < MAX_ROW; i++) {
        const int MAX_COLUMN = min((int)VV[i].size(), MAX_DUBUG_SIZE);
        if (VV[i].empty()) {
            cout << "[]" << endl;
            continue;
        }
        cout << "[";
        for (int j = 0; j < MAX_COLUMN; j++) {
            if (VV[i][j] == LINF)
                cout << "INF";
            else
                cout << VV[i][j];

            if (j == (int)VV[i].size() - 1)
                cout << "]\n";
            else if (j == MAX_DUBUG_SIZE - 1)
                cout << ",...\n";
            else
                cout << ",";
        }

        if (i != (int)VV.size() - 1 and i == MAX_DUBUG_SIZE - 1) {
            cout << ":\n:\033[m\n";
            return;
        }
    }

    cout << "]\033[m\n";
    return;
}

template <class Head, class... Tail> void debug_out(Head H, Tail... T) {
    cout << "\033[33m" << H << "\033[m ";
    debug_out(T...);
}

template <class T> bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> bool chmin(T& a, const T& b) {
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

ll ctoll(char c) {
    return ll(c - '0');
}
