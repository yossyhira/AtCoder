/*
==============================
ACL modint まとめ (拡張版)
==============================

- modint とは？
  整数を modulo 計算するための型。
  計算結果は常に 0〜MOD-1 に収まる。

- 宣言例：
    using mint = atcoder::modint1000000007;
    mint a = 5;          // int から自動変換
    ll b = 10;
    mint x = mint(b);   // ll から明示変換

- 標準 mod の種類（ACL 提供）
    modint1000000007     // 1e9 + 7
    modint998244353      // 998244353 (FTTに使える)
    // 自作 mod
    using mint_custom = atcoder::modint<123456789>; 

- 型変換：
    mint x = 10;               // int → mint 自動変換
    mint y = mint(ll(1e18));   // ll → mint 明示変換
    ll z = x.val();             // 元の整数値に戻す

- 演算
    +, -, *, /, +=, -=, *=, /=  が使える
    int/ll は自動で mint に変換される（左辺が mint の場合のみ）
    左辺が int/ll の場合はエラー    ll d; d += mint(x); はダメ
    doubleもダメ

- 比較
    ==, != が使える

- pow
    x.pow(n)  // x^n mod MOD, O(log n)

==============================
*/

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
// 代表的な mod
using mint = modint1000000007;     // 1e9+7
// using mint = modint998244353;   // 998244353 (FTTに便利)
// using mint = modint<123456789>; // 自作 mod mod = 123456789;

int main() {
    //入力
    /*
    これはダメ
    mint hoge;
    cin >> hoge;
    */
    int hoge;
    cin >> hoge;
    mint hoge_mint;
    hoge_mint = hoge;

    //出力
    //.val()つける！！
    cout << hoge.val() << endl;
    // 宣言
    int a_i = 5;
    ll b_l = 10;
    mint a = a_i;           // int から自動変換
    mint b = mint(b_l);    // ll から明示変換 mint(x)にする 
                          // (ll)x みたいに (mint) xでないことに注意
    
    // 演算例
    mint sum1 = a + b;        // OK (5 + 10) % mod
    cout << "sum1 : "<< sum1.val() << endl; //<= 15
    
    ll c = 1e9 + 3;
    mint sum2 = a + c;        // ll も自動変換 (5+1e9+3) % mod = (1e9+8)%mod
    cout << "sum2 : " << sum2.val() << endl; //<= 1 (1e9+7で割ったあまりだから1)
    
    mint sum3 = a; //sum3 = 5;
    // mint += (ll or int);はok
    //左辺が int/ll の場合はエラー    
    // ll e; 
    // e += mint(a_i); はダメ
    int d = 1e9 + 3;
    sum3 += d;    // int も自動変換OK, 左辺が mint だから d は自動変換 (5+1e9+3) % mod = (1e9+8)%mod
    cout << "sum3 : " << sum3.val() << endl; //<= 1 (1e9+7で割ったあまりだから1)

    //doubleはダメ
    /*
    double f = 3.14;
    mint g = f; <= ダメ！！
    */

    // pow の例
    //計算量O(log N); 二分累乗 使用
    mint p = a.pow(10);       // a^10 mod MOD

    // 値取得
    ll val = p.val();          // ll 型で取得
    cout << "a^10 = " << val << endl;

    // 比較
    //比較もいつも通りできる
    if(a == b) cout << "a == b\n";
    if(a != b) cout << "a != b\n";
    //aはmint型，a_iはint型
    if(a == a_i) cout << "a == a_i\n"; //不等号もmintに自動変換される if(a == mint(a_i))と同じ意味


    // 四則演算 + 例
    mint res = (a * b + c) / mint(d);  // ll/int 自動変換
    cout << "res = " << res.val() << endl;

    return 0;
}
