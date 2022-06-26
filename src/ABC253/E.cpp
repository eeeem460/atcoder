#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INCANT cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12)
#ifdef MY_DEBUG
#define dbg(...) debug_out(__VA_ARGS__)
#define dbgn(var) debug_out(#var, "=", var)
#else
#define dbg(...)
#define dbgn(...)
#endif
void debug_out();
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

const int MOD = 998244353;
using Modint = modint998244353;

ostream& operator<<(ostream& os, const Modint& N) {
    return os << N.val();
}

int main() {
    INCANT;
    ll n, m, k;
    cin >> n >> m >> k;

    if (k == 0) {
        cout << pow_mod(m, n, MOD) << '\n';
        return 0;
    }

    vector dp(n, vector<Modint>(m + 1));
    for (ll i = 1; i <= m; i++) {
        dp[0][i] = 1;
    }
    for (ll i = 0; i < n - 1; i++) {
        vector<Modint> psum(m + 1);
        psum[0] = dp[i][0];
        for (ll j = 0; j < m; j++) {
            psum[j + 1] += psum[j] + dp[i][j + 1];
        }
        // dbg(psum);
        for (ll j = 1; j <= m; j++) {
            if (j - k >= 1) dp[i + 1][j] += psum[j - k];
            if (j + k - 1 <= m) dp[i + 1][j] += psum[m] - psum[j + k - 1];
        }
    }

    Modint ans = 0;
    for (ll i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
    }

    cout << ans << '\n';
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

void debug_out_vl(vector<ll> V) {
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

void debug_out_vvl(vector<vector<ll>> VV) {
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
    if constexpr (std::is_same_v<Head, vector<ll>>) {
        debug_out_vl(H);
    }
    else if constexpr (std::is_same_v<Head, vector<vector<ll>>>) {
        debug_out_vvl(H);
    }
    else {
        cout << "\033[33m" << H << "\033[m ";
    }

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