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

// n以下の整数について最小の素因数を求めた結果の配列を返す
// min_factor[i]はiを割り切る最小の数（iの素因数のうち最小のもの）
// min_factor[i] == iならiは素数（i=0, 1のときを除く）
std::vector<ll> sieve(ll n) {
    //素数候補を管理する配列
    std::vector<ll> min_factor(n + 1);
    // 2以上の数を一度素数候補に入れる
    for (ll i = 0; i <= n; i++) min_factor[i] = i;
    //それぞれの数について最小の素因数を求める
    for (ll i = 2; i * i <= n; i++) {
        if (min_factor[i] == i) {
            for (ll j = 2; i * j <= n; j++) {
                if (min_factor[i * j] > i) {
                    min_factor[i * j] = i;
                }
            }
        }
    }
    return min_factor;
}

//配列min_factorを使ってmを素因数分解する
//配列ansにはmの素因数が小さい順に格納される
std::vector<ll> factor(std::vector<ll>& min_factor, ll m) {
    std::vector<ll> ans;
    while (m > 1) {
        ans.push_back(min_factor[m]);
        m /= min_factor[m];
    }
    return ans;
}

// 高速素因数 計算量，前処理 O(NloglogN), クエリ処理 O(logM)
// N まで素因数分解できるテーブルを用意する．Mを素因数分解するのに O(logM)
/* 例) 
    ll n = 100, m = 50;
    vector<ll> si = sieve(n);
    vector<ll> m_pdiv = factor(si, m);
      // m_pdiv = {2, 5, 5} 
*/

int main() {
    INCANT;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> si = sieve(pwr(10, 6) + 10000);

    map<ll, ll> mp;

    bool pair = true;

    for (ll i = 0; i < n; i++) {
        vector<ll> cnt = factor(si, a[i]);
        sort(cnt.begin(), cnt.end());
        cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());
        for (auto&& x : cnt) {
            if (mp[x] != 0) {
                pair = false;
            }
            mp[x]++;
        }
    }

    ll g = a[0];
    for (ll i = 1; i < n; i++) {
        g = __gcd(g, a[i]);
    }

    if (pair) {
        cout << "pairwise coprime" << endl;
    }
    else if (g == 1) {
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
