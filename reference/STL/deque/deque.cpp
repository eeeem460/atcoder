#include <bits/stdc++.h>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;    // int は 2 * 10^9 まで
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


int main() {
    deque<int> d;
    d.push_back(10);
    d.push_back(1);
    d.push_back(3);

    // この時点で d の内容は { 10, 1, 3 } となっている

    cout << d.front() << endl; // 10 (先頭の要素)
    d.pop_front();  // 先頭を削除

    // この時点で d の内容は { 1, 3 } となっている

    cout << d.back() << endl;  // 3 (末尾の要素)
    d.pop_back();  // 末尾を削除

    // この時点で d の内容は { 1 } となっている

    d.push_front(5);
    d.push_back(2);

    // この時点で d の内容は { 5, 1, 2 } となっている

    cout << d.at(1) << endl; // 1    
}
