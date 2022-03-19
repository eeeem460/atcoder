#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
#define INCANT cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12)
#ifdef MY_DEBUG
#define dbg(...) debug_out(__VA_ARGS__)
#else
#define dbg(...)
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
const ll LINF = (ll)1e18 + 7;
const double EPS = 1e-9;

// https://atcoder.jp/contests/abc177/tasks/abc177_e




// min_factor[i] = i を割り切る最小の数
// min_factor[i] == i なら i は素数（i = 0, 1 のときを除く）
vector<ll> set_sieve(ll N) {
    vector<ll> min_factor(N + 1);
    iota(min_factor.begin(), min_factor.end(), 0LL);

    for (ll i = 2; i * i <= N; i++) {
        if (min_factor[i] != i) {
            continue;
        }

        for (ll j = i * i; j <= N; j += i) {
            if (min_factor[j] == j) {
                min_factor[j] = i;
            }
        }
    }

    return min_factor;
}

// M を素因数分解した配列を返す．
vector<ll> factor(vector<ll>& min_factor, ll M) {
    ll Q = M;
    vector<ll> factor_M;

    while (Q >= 2) {
        factor_M.push_back(min_factor[Q]);
        Q /= min_factor[Q];
    }

    return factor_M;
}

/* 
    高速素因数分解 前処理 O(NloglogN) クエリ処理 O(logM)
    N 以下の整数を素因数分解可能
    M を素因数分解するのに O(logM)

    **使い方**
    ll n = 100, m = 50;
    vector<ll> sieve = set_sieve(n);
    vector<ll> factor_m = factor(sieve, m);
      // factor_m = {2, 5, 5} 
*/

int main() {
    INCANT;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    const ll MAX_A = pwr(10, 6);
    vector<ll> min_factor = set_sieve(MAX_A);

    bool p_coprime = true;
    vector<bool> co_factor(MAX_A);
    for (ll i = 0; i < n; i++) {
        vector<ll> factor_ai = factor(min_factor, a[i]);
        sort(factor_ai.begin(), factor_ai.end());
        factor_ai.erase(unique(factor_ai.begin(), factor_ai.end()), factor_ai.end());

        for (auto&& x : factor_ai) {
            if (co_factor[x]) {
                p_coprime = false;
            }
            else {
                co_factor[x] = true;
            }
        }
    }
    if (p_coprime) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    ll G = __gcd(a[0], a[1]);
    for (ll i = 2; i < n; i++) {
        G = __gcd(G, a[i]);
    }

    if (G == 1) {
        cout << "setwise coprime" << endl;
    }
    else {
        cout << "not coprime" << endl;
    }
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

ll comb(ll n, ll r) {  // comb(60, 30)までオーバーフローなし
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res *= n--;
        res /= i;
    }
    return res;
}
