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
    modint998244353      // 998244353 (NTTに使える)
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
    //入力////////////////////////////////////////////////
    /*
    これはダメ
    mint hoge;
    cin >> hoge;
    */
    int hoge;
    cin >> hoge;
    mint hoge_mint;
    hoge_mint = hoge;

    //出力////////////////////////////////////////////////////
    //.val()つける！！
    cout << hoge_mint.val() << endl;
    cout << (hoge_mint - 1).val() << endl;//(mint - x).val()や後述の(mint - x).pow(n + y);とかもできる

    // 宣言
    int a_i = 5;
    ll b_l = 10;
    mint a = a_i;           // int から自動変換
    mint b = mint(b_l);    // ll から明示変換 mint(x)にする 
                          // (ll)x みたいに (mint) xでないことに注意
    
    // 演算例/////////////////////////////////////////////////////////
    //負の割り算
    /*
    x % mod;
    割り算のあまりは x が0～(mod-1)の間になるまでmod分引く(0 <= xの時)か足す(x < 0のとき)ので
    xが負のときだけ(x + mod)%modを計算すると負の割り算のあまりが求まる．
    mintは自動で負の数でもこのあまりに変換してくれる．(通常のC++だと上記の方法で求める)
    特に，x < y のときに(x - y)%mod のときに使える
    (x - y)%mod => (x + mod - y) % mod;にする(通常のc++のみ)
    */
    int minus = -10;
    const int mod = 1e9+7; 
    cout << (minus + mod) % mod<< endl; //999999997
    mint minus_mint = -10;
    cout << minus_mint.val() << endl; //999999997

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

    // pow の例/////////////////////////////////////////////////////////////////
    //.pow()の引数はllかintで，計算した返り値はmint
    //.pow(mint)やpow(double)はダメ
    //計算量O(log N); 二分累乗 使用

    //a = 5; a^10計算
    //.pow().val()で一行にまとめられる
    cout << "a^10 = " << a.pow(10).val() << endl;
    //もちろん別に分けても可
    mint p = a.pow(10);       // a^10 mod MOD
    cout << "a^10 = " << p.val() << endl;
    
    //powの引数変えてみた
    //aの値によらず，0乗は常に1
    cout << "a^0 = " << a.pow(0).val() << endl;

    mint g = 3;
    // int 型
    int n1 = 5;
    mint r1 = g.pow(n1);
    cout << "r1: "<< r1.val() << endl;

    // long long 型
    long long n2 = 1000000000000000000LL;
    mint r2 = g.pow(n2);
    cout << "r2: "<< r2.val() << endl;

    // 直接整数リテラル
    mint r3 = g.pow(10);
    cout << "r3: "<< r3.val() << endl;
    //mint r4 = g.pow(1e18); <= 1e18がlong doubleだからダメ
    mint r4 = g.pow(1000000000000000000LL);
    cout << "r4: "<< r4.val() << endl;

    //引数の中で計算してもOk
    mint r5 = (g - 1).pow(100 * 20);
    cout << "r5: "<< r5.val() << endl;

    // 比較//////////////////////////////////////////////////////////////////
    //比較もいつも通りできる
    /*
    [!=]や[==]のみ使える．
    [<=], [<],[>],[>=]は.val()つけて比較する
    */
    if(a == b) cout << "a == b\n";
    if(a != b) cout << "a != b\n";
    //aはmint型，a_iはint型
    if(a == a_i) cout << "a == a_i\n"; //不等号もmintに自動変換される if(a == mint(a_i))と同じ意味
    if(a.val() <= 100) cout << 5 << endl;//.valつける！！！

    // 四則演算 + 例/////////////////////////////////////////////////////////////////////////
    //dはint型だけど自動でmintに変換
    mint res = (a * b + c) / d;  // ll/int 自動変換
    cout << "res = " << res.val() << endl;

    //逆元///////////////////////////////////////////////////////////////////////////////////
    /*
    例えば、mod = 7 の世界で
    3 × x ≡ 1 (mod 7)
    を満たす x を探すと、x = 5
    （3×5=15 → 15 mod 7 = 1）
    この x(5) を 3 の逆元（mod 7 における） と呼ぶ
    */
    // ------------------------
    // 単純な逆元の計算例
    // ------------------------
    mint x = 17;           
    // 注意: x が 0 のときは inverse は定義されないので呼ばない
    if (x.val() == 0) {
        cout << "x = 0 のため逆元は存在しない\n";
    } else {
        mint inv_x = x.inv();                    // 逆元を求める
        cout << "x = " << x.val() << "\n";
        cout << "x.inv() = " << inv_x.val() << "\n";
        cout << "x * x.inv() = " << (x * inv_x).val() << "  (should be 1)\n";
    }

    // ------------------------
    // 階乗と逆元の前計算例（comb のための典型）
    // nCr % mod を 前計算してO(1)で求める
    //組み合わせDP，数え上げで使う
    // 前計算 : O(N)
    // テストケース : O(1)
    // ------------------------
    //前計算
    int N = 1e6; // まだ使っていない小さめの N
    vector<mint> fac(N+1), ifac(N+1);
    fac[0] = 1;
    for(int i = 1; i <= N; ++i) fac[i] = fac[i-1] * i;

    // ifac[N] を fac[N] の逆元で初期化（inv() を使う）
    ifac[N] = fac[N].inv();
    for(int i = N-1; i >= 0; --i) ifac[i] = ifac[i+1] * (i+1);
    
    //テストケース
    // C(n, r) の例: C(8, 3) = 56
    int n = 8, r = 3;
    mint comb = fac[n] * ifac[r] * ifac[n-r];
    cout << "C(" << n << "," << r << ") = " << comb.val() << "\n"; //56

    n = 10000; r = 1000;
    comb = fac[n] * ifac[r] * ifac[n-r];
    cout << "C(" << n << "," << r << ") = " << comb.val() << "\n";//155349879
    return 0;
}
