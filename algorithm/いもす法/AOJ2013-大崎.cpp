#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2013


int to_second (string time) {
    int second = stoi(time.substr(6, 2));
    int minute = stoi(time.substr(3, 2));
    int hour   = stoi(time.substr(0, 2));
    
    return second += (minute * 60) + (hour * 60 * 60);
}


int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        vector<int> second(60 * 60 * 25);
        for (int i = 0; i < n; i++) {
            string leave, arrive; cin >> leave >> arrive;
            int l_second = to_second(leave);
            int a_second = to_second(arrive);

            second[l_second]++;
            second[a_second]--;
        }

        int ans = second[0];
        for (int i = 1; i < second.size(); i++) {
            second[i] += second[i - 1];
            chmax(ans, second[i]);
        }

        cout << ans << endl;
    }    
}
