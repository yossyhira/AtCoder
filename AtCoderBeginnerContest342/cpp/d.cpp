#include <bits/stdc++.h>
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
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7; //ll % modしても自動でmod型変換でllなるからバグらないよ

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n);
    int zero_cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if(num[i] == 0) zero_cnt ++;
    }
    ll ans = 0;
    auto f = [&](int x){
        int a = 0;
        for (int i = 1; (i*i) <= x; i ++) {
            if((x % (i*i)) == 0) a = (i*i);
        }
        return a;
    };
    //自動で初期値0になってる．map＜key, 値＞
    map<int, int> M1;
    for (int i = 0; i < n; i++) {
        if(num[i] == 0){
            ans += ((n - 1) - i);
            zero_cnt --;
            continue;
        }
        ans += zero_cnt;
        M1[num[i] / f(num[i])] ++;
    }
    for(auto &p : M1){
        ll v = p.se;
        ans += (v * (v - 1))/2;
    }
    cout << ans << endl;
}

//コーナー
//j番目のやつが0のパターン
/*
入力
2
3 0

出力(正解)
1
*/
