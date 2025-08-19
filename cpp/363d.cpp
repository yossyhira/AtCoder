#include <iostream>
#include <string>
using namespace std;

long long TEN(int x) { return x == 0 ? 1 : TEN(x - 1) * 10; }

int main() {
  long long N;
  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  N--;
  for (int d = 1;; d++) {
    int x = (d + 1) / 2;
    if (N <= 9 * TEN(x - 1)) {
      string S = to_string(TEN(x - 1) + N - 1);
      S.resize(d, ' ');
      for (int i = x; i < d; i++) S[i] = S[d - 1 - i];
      cout << S << endl;
      return 0;
    } else {
      N -= 9 * TEN(x - 1);
    }
  }
}

/*#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
//#define eb emplace_back
//#define em emplace
//#define pob pop_back
//using ld = long double;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define yes cout<<"Yes"<<endl
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"No"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;

    const int mx = 1e6;
    if(n <= 10){
        cout << n - 1 << endl;
        return 0;
    }
    priority_queue<ll, vector<ll>, greater<ll>> que;//小さい順(昇順)に取り出す
    for (int i = 1; i <= mx; i++) {
        if(10 <= i){
            int i2 = i / 10;
            string txt = to_string(i2);
            int len = txt.size();
            ll num = (i * pow(10, len)) + i2;
            que.emplace(num);
        }   
        string txt = to_string(i);
        int len = txt.size();
        ll num = (i * pow(10, len)) + i;
        que.emplace(num);
    }
    for (int i = 11; i < n; i++) {
        que.top(); que.pop();
    }
    cout << que.top() << endl;
    return 0;
}*/