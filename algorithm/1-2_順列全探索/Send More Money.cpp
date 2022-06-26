#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/abc198/tasks/abc198_d


int main() {
    vector<string> s(3); cin >> s[0] >> s[1] >> s[2];
    set<char> heads;
    map<char, ll> ma;
    for (int i = 0; i < 3; i++) {
        ll co = 1;
        if (i == 2) co = -1;
        int sz = s[i].size();
        for (int j = sz-1; j >= 0; j--) {
            ma[s[i][j]] += co;
            co *= 10;
        }
        heads.insert(s[i][0]);          
    }

    if (ma.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<int> p(10);
    iota(p.begin(), p.end(), 0);
    do {
        ll sum = 0;
        int i = 0;
        for (auto x : ma) {
            sum += x.second * p[i];
            if (p[i] == 0 && heads.count(x.first)) sum = 1e18;
            i++;
        }

        if (sum == 0) {
            i = 0;
            for (auto &x : ma) {
                x.second = p[i];
                i++;
            }
            vector<ll> a(3);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < s[i].size(); j++) {
                    a[i] = a[i] * 10 + ma[s[i][j]];
                }
                cout << a[i] << endl;
            }
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "UNSOLVABLE" << endl;
}


// cout << fixed << setprecision(10);
