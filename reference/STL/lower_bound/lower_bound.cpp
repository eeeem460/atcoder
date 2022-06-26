#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
using Modint = modint1000000007;
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


int main() {

    // ソート済みの配列に対して
    vector<int> a = {1, 1, 2, 2, 2, 5, 7, 9, 9, 11};
                //  0  1  2  3  4  5  6  7  8  9  10 
    auto itr1 = lower_bound(a.begin(), a.end(), 0); // 0 <= a[i] となる最小の i (イテレータ)
    auto itr2 = lower_bound(a.begin(), a.end(), 1);
    auto itr3 = lower_bound(a.begin(), a.end(), 2);
    auto itr4 = lower_bound(a.begin(), a.end(), 3);
    auto itr5 = lower_bound(a.begin(), a.end(), 9);
    auto itr6 = lower_bound(a.begin(), a.end(), 100);

    // 先頭からの距離
    cout << itr1 - a.begin() << endl; // 0
    cout << itr2 - a.begin() << endl; // 0
    cout << itr3 - a.begin() << endl; // 2
    cout << itr4 - a.begin() << endl; // 5
    cout << itr5 - a.begin() << endl; // 7
    cout << itr6 - a.begin() << endl; // 10 *** 範囲外

    // 末尾までの距離
    cout << a.end() -itr1 << endl; // 10
    cout << a.end() -itr2 << endl; // 10
    cout << a.end() -itr3 << endl; // 8
    cout << a.end() -itr4 << endl; // 5
    cout << a.end() -itr5 << endl; // 3
    cout << a.end() -itr6 << endl; // 0


}


// cout << fixed << setprecision(10);
