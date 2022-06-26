#include <bits/stdc++.h>
using namespace std; // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;         // int は 2 * 10^9 まで


int main() {

    vector<int> A;
    
    //** 連続して重複した値をまとめる
        {
        A = {1, 1, 1, 2, 3, 3, 2, 2, 1, 1};
        A.erase(unique(A.begin(), A.end()), A.end());
            // A = {1, 2, 3, 2, 1}
            
        // unique の動作
        A = {1, 1, 1, 2, 3, 3, 2, 2, 1, 1};
        unique(A.begin(), A.end());
            // A = {1, 2, 3, 2, 1, 3, 2, 2, 1, 1}
            // {1, 2, 3, 2, 1} 以降は未規定
        }
        
    //**  同一要素を削除
        {
        A = {1, 1, 1, 2, 3, 3, 2, 2, 1, 1};
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
            // A = {1, 2, 3}
        }

    //** 連続した整数列の生成
        {
        vector<ll> cnt(10);
        iota(cnt.begin(),cnt.end(), 0); 
            // {0, 1, 2, ... , 9} 右の値は初期値
        iota(cnt.begin(),cnt.end(), 2); 
            // {2, 3, ... , 11}
        } 

    //** 配列の要素の和
        {
        vector<ll> cnt(10); 
        accumulate(cnt.begin(), cnt.end(), 0LL); 
            // 初期値0 + 配列の全要素の和
            /****  初期値の型が返り値の型となることに注意 !!!!!!! *****/
        }
        
    //** 対称差
        {   
            vector<int> zero;
            vector<int> B = {1, 3, 4, 5, 6};
            vector<int> C = {1, 2, 4, 5, 7};
            set_symmetric_difference(B.begin(), B.end(), C.begin(), C.end(), back_inserter(zero));
                // C = {2, 3, 6, 7}
        }

}
