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
// const int INF = 1e9 + 7;
const ll LINF = (ll)1e18 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// https://atcoder.jp/contests/atc001/tasks/dfs_a

int main() {
    INCANT;
    ll h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    pair<ll, ll> s, g;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> c[i][j];
            if (c[i][j] == 's') {
                s = {i, j};
            }
            if (c[i][j] == 'g') {
                g = {i, j};
            }
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w));
    vector<ll> dy(4);
    dy = {0, 0, 1, -1};
    vector<ll> dx(4);
    dx = {1, -1, 0, 0};

    auto dfs = [&](auto self, ll x, ll y) -> void {
        visited[x][y] = true;

        /* visit4 */
        for (ll i = 0; i < 4; i++) {
            ll X = x + dx[i], Y = y + dy[i];
            if (X < 0 || h <= X || Y < 0 || w <= Y) continue;
            if (c[X][Y] != '#' && !visited[X][Y]) {
                self(self, X, Y);
            }
        }

    };

    dfs(dfs, s.first, s.second);

    if (visited[g.first][g.second])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
    for (ll i = 0; i < V.size(); i++) {
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
        for (ll i = 0; i < V.size(); i++) {
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

ll comb(ll n, ll r) {  // comb(60, 30)?????????????????????????????????
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res *= n--;
        res /= i;
    }
    return res;
}
