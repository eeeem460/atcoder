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
ll ctoll(char);
const ll LINF = (ll)1e18 + 7;
const double EPS = 1e-9;

#include <atcoder/all>
using namespace atcoder;
const int MOD = 1e9 + 7;
using Modint = modint1000000007;
ostream& operator<<(ostream& os, const Modint& N) {
    return os << N.val();
}

// https://atcoder.jp/contests/abc156/tasks/abc156_dhttps://atcoder.jp/contests/abc156/tasks/abc156_d

// 計算量 O(Rlog(MOD)) MODは素数
Modint COM(ll N, ll R) {
    Modint res = 1;
    for (ll i = 1; i <= R; i++) {
        res *= N - i + 1;
        res /= i;
    }
    return res;
}

int main() {
    INCANT;
    ll n, a, b;
    cin >> n >> a >> b;

    Modint ans = pow_mod(2, n, MOD) - 1 - COM(n, a) - COM(n, b);

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
    cout << "\033[33m";
    if (V.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (ll i = 0; i < (ll)V.size(); i++) {
        if (V[i] == LINF)
            cout << "INF";
        else
            cout << V[i];
        cout << (i == int(V.size() - 1) ? "]\033[m\n" : ",");
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
    for (auto&& V : VV) {
        if (V.empty()) {
            cout << "[]" << endl;
            continue;
        }
        cout << "[";
        for (ll i = 0; i < (ll)V.size(); i++) {
            if (V[i] == LINF)
                cout << "INF";
            else
                cout << V[i];
            cout << (i == int(V.size() - 1) ? "]\n" : ",");
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

ll ctoll(char c) {
    return ll(c - '0');
}
