#include <bits/stdc++.h>
using namespace std; // 計算回数は 2 * 10^8 ぐらいまで
using ll = long long;         // int は 2 * 10^9 まで
const int INF = 1e9; // 10^9
const ll LINF = 1e18;  // 10^18

int main() {
    string s;

    // ** 部分文字列
    {
        s = "123456789";
        string s1 = s.substr(3);  // 3番目以下
            // s1 = "456789"
        string s2 = s.substr(3, 2);  // 3番目から2つ
            // s2 = "45"
    }
    // ** 末尾に文字の追加
    {
        s = "abcd";
        s.push_back('e');  // 末尾に 'e' を追加
            // s = "abcde"
    }
    //** 文字列のソート
    {
        s = "adcb";
        sort(s.begin(), s.end());
          // s = "abcd"
    }
    //** 末尾の文字削除
    {   
        s = "0011";
        s.pop_back();
            // s = "001"
            // 空の文字列に対しては実行時エラーになる
    }
    //** 部分文字列の削除
    {
        s = "123456789";
        s.erase(3, 2);  // 3番目以降の2文字を削除
            // s = "1236789"

        s = "123456789";
        s.erase(3);  // 3番目以降を削除
            // s = "123"
    }  
    //** 特定の文字のカウント
    {
        s = "101101";
        count(s.begin(), s.end(), '1');
            // = 4
    }
    //** string型から int/ll型への変換
    {
        s = "123";
        int s1 = stoi(s);  // string to int
            // s1 = 123
        ll s2 = stoll(s);  // string to ll
            // s2 = 123
    }
    //** char 型と int型 の相互変換
    {
        char c = '3';
        int a = c - '0'; // int = char - '0'
            // a = 3
        char c1 = a + '0';
            // c1 = '3'
    }
    //** 大文字と小文字の判定 / 変換 
    {
        s = "AbCdeF";

        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) s[i] = tolower(s[i]); // 小文字なら大文字に変換
            else if (islower(s[i])) s[i] = toupper(s[i]); // 大文字なら小文字に変換
        }
            // s = "aBcDEf"
        //*** tolower の返り値は int 型であることに注意 ***//
    }
    //** 一文字の繰り返しからなる文字列
    {
        string str = string(5, 'a') + string(2, '5');
            // str = "aaaaa55"
    }

}
    