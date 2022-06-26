#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std; // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;         // int は 2 * 10^9 まで
const int INF = 1e9; // 10^9
const ll LINF = 1e18;  // 10^18
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) {a=b; return 1;}return 0;}


// https://atcoder.jp/contests/abc165/tasks/abc165_c


int N, M, Q;
int ans = 0;

int dfs (vector<int> A, vector<vector<int>> V) {
    if (A.size() == N) {
        int res = 0;
        for (int i = 0; i < Q; i++) {
            if (A[V[i][1]-1] - A[V[i][0]-1] == V[i][2]) res += V[i][3];
        }
        chmax(ans, res);
        return 0;
    }

    if (A.empty()) {
        for (int i = 1; i <= M; i++) {
            A.push_back(i);
            dfs(A, V);
            A.pop_back();
        }
    }
    else {
        for (int i = A.back(); i <= M; i++) {
            A.push_back(i);
            dfs(A, V);
            A.pop_back();
        }
    }

    return ans;
}

int main() {
    cin >> N >> M >> Q;

    vector<vector<int>> V(Q, vector<int>(4));
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> V[i][j];
        }
    }
    vector<int> A;
    cout << dfs(A, V) << endl;
}
