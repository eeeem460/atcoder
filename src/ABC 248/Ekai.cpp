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

// 有理数
long long calc_gcd(long long a, long long b) {
    return b ? calc_gcd(b, a % b) : a;
}
struct frac {
    long long first, second;

    using D = long double;
    inline frac normalize() {
        if (second < 0) {
            first = -first;
            second = -second;
        }
        long long d = calc_gcd(first, second);
        if (d == 0) {
            first = 0;
            second = 1;
        }
        else {
            first /= d;
            second /= d;
        }
        return *this;
    }
    frac(long long f = 0, long long s = 1) : first(f), second(s) {
        normalize();
    }
    inline D to_d() const {
        return D(first) / second;
    }
    inline frac operator-() {
        (*this).first *= -1;
        return (*this);
    }
    inline const frac& operator=(long long a) {
        *this = frac(a, 1);
        return *this;
    }
    inline const frac& operator+=(const frac& a);
    inline const frac& operator+=(long long a);
    inline const frac& operator-=(const frac& a);
    inline const frac& operator-=(long long a);
    inline const frac& operator*=(const frac& a);
    inline const frac& operator*=(long long a);
    inline const frac& operator/=(const frac& a);
    inline const frac& operator/=(long long a);
    inline friend ostream& operator<<(ostream& s, const frac& f) {
        s << f.first;
        if (f.second != 1) s << "/" << f.second;
        return s;
    }
};
inline bool operator==(const frac& a, const frac& b) {
    return a.first * b.second == a.second * b.first;
}
inline bool operator!=(const frac& a, const frac& b) {
    return !(a == b);
}
inline bool operator<(const frac& a, const frac& b) {
    return a.first * b.second < a.second * b.first;
}
inline bool operator>(const frac& a, const frac& b) {
    return b < a;
}
inline bool operator<=(const frac& a, const frac& b) {
    return a.first * b.second <= a.second * b.first;
}
inline bool operator>=(const frac& a, const frac& b) {
    return b <= a;
}
inline frac operator+(const frac& a, const frac& b) {
    frac res;
    res.first = a.first * b.second + a.second * b.first;
    res.second = a.second * b.second;
    res.normalize();
    return res;
}
inline frac operator-(const frac& a, const frac& b) {
    frac res;
    res.first = a.first * b.second - a.second * b.first;
    res.second = a.second * b.second;
    res.normalize();
    return res;
}
inline frac operator*(const frac& a, const frac& b) {
    frac res;
    res.first = a.first * b.first;
    res.second = a.second * b.second;
    res.normalize();
    return res;
}
inline frac operator/(const frac& a, const frac& b) {
    frac res;
    res.first = a.first * b.second;
    res.second = a.second * b.first;
    res.normalize();
    return res;
}
inline frac abs(const frac& a) {
    frac res;
    res = a;
    res.normalize();
    if (res.first < 0) res.first = res.first * (-1);
    return res;
}
inline const frac& frac::operator+=(const frac& x) {
    *this = *this + x;
    return *this;
}
inline const frac& frac::operator+=(long long x) {
    *this = *this + x;
    return *this;
}
inline const frac& frac::operator-=(const frac& x) {
    *this = *this - x;
    return *this;
}
inline const frac& frac::operator-=(long long x) {
    *this = *this + x;
    return *this;
}
inline const frac& frac::operator*=(const frac& x) {
    *this = *this * x;
    return *this;
}
inline const frac& frac::operator*=(long long x) {
    *this = *this * x;
    return *this;
}
inline const frac& frac::operator/=(const frac& x) {
    *this = *this / x;
    return *this;
}
inline const frac& frac::operator/=(long long x) {
    *this = *this / x;
    return *this;
}

int main() {
    INCANT;
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }  // Aren't they one line?

    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    set<pair<frac, frac>> st;
    set<frac> stf;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll ax = x[i], ay = y[i];
            ll bx = x[j], by = y[j];
            ll cnt = 2;

            for (ll k = j+1; k < n; k++) {
                if (k == i or k == j) continue;
                if ((y[k] - ax) * (bx - ax) == (by - ay) * (x[k] - ax)) cnt++;
            }

            if (cnt >= k) {
                ll t1 = bx - ax;
                ll t2 = by - ay;
                ll t3 = (-ax) * (by - ay) + ay * (bx - ax);

                if (t2 == 0) {
                    stf.insert(t3 / t1);
                }
                else {
                    if (t2 < 0) {
                        t1 *= -1;
                        t3 *= -1;
                        t2 *= -1;
                    }
                    st.insert({t1 / t2, t3 / t2});
                }
            }
        }
    }

    // dbg(st);

    cout << st.size() + stf.size() << endl;
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
