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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct food {
        ll m, v;
        food() : m(0), v(0) {}
        food(ll m, ll v): m(m), v(v) {}
    };

    int n;
    cin >> n;
    vector<food> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i].m >> num[i].v;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(2, -LINF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        ll mode = num[i].m;
        ll value = num[i].v;

        if(mode == 0){
            //今痛くない
            //食べる
            chmax(dp[i+1][0], dp[i][0]+value);
            //食べない：マイナスのおいしさあることがあるから
            chmax(dp[i+1][0], dp[i][0]);

            //今痛い
            //食べる
            chmax(dp[i+1][0], dp[i][1]+value);
            //食べない
            chmax(dp[i+1][1], dp[i][1]);
        }else{
            //今痛くない
            //食べる：痛いに変化
            chmax(dp[i+1][1], dp[i][0]+value);
            //食べない：引継ぎ
            chmax(dp[i+1][0], dp[i][0]);

            //今いたい
            //食べない選択肢しかない．
            // 食べたら死ぬ
            chmax(dp[i+1][1], dp[i][1]);
        }
    }
    ll ans = max(dp[n][0], dp[n][1]);
    cout << ans << endl;
}