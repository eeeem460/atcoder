#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/dp/tasks/dp_f


int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            chmax(dp[i][j], dp[i - 1][j]);
            chmax(dp[i][j], dp[i][j - 1]);
            if (s[i - 1] == t[j - 1]) chmax(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }


    string ans = "";
    int i = s.size(), j = t.size();
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}
