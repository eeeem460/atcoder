#include <bits/stdc++.h>
using namespace std;     // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;    // int は 2 * 10^9 まで, ll は 9 * 10^18 まで
const int INF = 1e9;     // 10^9
const ll LINF = 1e18;    // 10^18, INF と間違えない
const int MOD = 1000000007;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


/*
 * ARC136 B 高橋幼稚園
 */


const int MAX = 510000; // 問題による
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理 O(n) = O(MAX)
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算 O(1)
// 引数は ll型でよい
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    ll n, k; cin >> n >> k;

    COMinit();

    if (n > k) {
        cout << COM(n + k - 1, k) << endl;
        return 0;
    }

    cout << COM(n, k % n) << endl;

}


// cout << fixed << setprecision(10);
