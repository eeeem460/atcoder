#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using namespace atcoder;
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
using Modint = modint1000000007;
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;     // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


int main() {
    string s; cin >> s;
    deque<char> dq;

    bool rev = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            rev ^= true; // 真偽の反転
            continue;
        }

        if (rev) {
            if (!dq.empty() /* 空か判定 */ && dq.front() /* 先頭へのアクセス */ == s[i]) dq.pop_front(); // 先頭の要素
            else dq.push_front(s[i]); // 先頭へ追加
        }
        else {
            if (!dq.empty() && dq.back() /* 末尾へのアクセス */ == s[i]) dq.pop_back(); // 末尾の削除
            else dq.push_back(s[i]); // 末尾へ追加
        }
    }

    if (rev) {
        reverse(dq.begin(), dq.end()); // deque は反転できる
        for (int i = 0; i < dq.size(); i++) { // dq.size() で要素数の取得
            cout << dq[i]; // dq[i] で i 番目の要素
        }
    }
    else {
        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i];
        }
    }
    cout << endl;
}


// cout << fixed << setprecision(10);
