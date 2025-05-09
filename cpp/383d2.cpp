#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
    //n = 求めたい最大値
    int n; //メンバ関数
    /*
    f = 各値の最小の素因数(素数ならその数自身)
    prime = 素数と判定したものを追加
  
    メイン文でこの配列の中身を見れる
      auto primes = sieve.primes;
      auto f = sieve.f;
    */
    vector<int> f, primes;
    //ここが肝
    //メイン文のsieve()の引数でnを指定
    //何も入れずに宣言すると自動で1が入るようにする
    //入力された引数をメンバ関数nに追加．fを初期化
    Sieve(int n=1):n(n), f(n+1) {
      //0,1は素数でないので-1を入れる
      f[0] = f[1] = -1;
  
      //2からnが素数か判定
      for (ll i = 2; i <= n; ++i) {
        //fに値があったら素数ではないのでコンティニュー
        if (f[i] != 0) continue;
  
        //上ではじかれなければ素数なので追加
        primes.push_back(i);
  
        //fにiを追加
        f[i] = i;
  
        //iが最小の素因数を持つ数字を追加
        for (ll j = i*i; j <= n; j += i) {
          if (f[j] == 0) f[j] = i;
        }
      }
    }
  
    //引数が素数かどうかをboolで判定
    //xが最小の素数ならtrue
    bool isPrime(int x) { return f[x] == x;}
  
    //指数表記しない素因数分解を返す関数
    vector<int> factorList(int x) {
      vector<int> res;
      while (x != 1) {
        res.push_back(f[x]);
        x /= f[x];
      }
      return res;
    }
  
    //引数 x に対して素因数分解を行い
    //素因数とその指数（回数）をペアで返す関数
    vector<pair<ll,int>> factor(ll x) {
      vector<pair<ll,int>> res;
      for (int p : primes) {
        int cnt = 0; //指数部分カウント
        //素数pで割り切れるだけ割る
        while (x%p == 0) x /= p, ++cnt;
        //pで何回割れたか記録
        //素因数に持たなければ(cnt = 0回)記録しない
        if (cnt != 0) res.emplace_back(p,cnt);
      }
      //万が一記録していない素数だった時用に例外処理
      if (x != 1) res.emplace_back(x,1);
      return res;
    }
  };
  

int main() {
  ll n;
  cin >> n;
  Sieve sieve(1e6);
  auto primes = sieve.primes;

  int ans = 0;
  for(auto p1: primes)for(auto p2:primes){
    if(p1 <= p2) continue;
    if((ll)p1*p1*p2*p2 <= n)ans++;
    else break;
  }
  for(auto p1: primes){
    ll num = 1;
    for (int i = 0; i < 8; i++) num *= (ll)p1;
    if(num <= n) ans++;
    else break;
  }
  cout << ans << endl;
  return 0;
}