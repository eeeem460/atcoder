#include <bits/stdc++.h>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


/*
 * ABC136 D Gathering Children 
 */


vector<pair<char, int>> runlength(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
//**** 使用例) str = "RLLRRRLL" -> encode = {('R', 1), ('L', 2), ('R', 3), ('L', 2)}
//**** 添え字の操作) now = 0, 1, 3, 6, 8
//     int now = 0;
//     for (int i = 0; i < runlength.size(); i++) {
//         now += memo[i].second;
//     }

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> ans(n);
    vector<pair<char ,int>> memo = runlength(s);
           
    int now = 0;
    for (int i = 0; i < memo.size(); i++) {
        if (memo[i].first == 'L') {            
            ans[now-1] = (memo[i-1].second + 1) / 2 + memo[i].second / 2;
            ans[now] = memo[i-1].second / 2 + (memo[i].second + 1) / 2;
        }

        now += memo[i].second;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}


// cout << fixed << setprecision(10);
