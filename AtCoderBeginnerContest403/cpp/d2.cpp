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
#define no cout<<"No"<<endl
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    const int M = 1000005;
    vector<int> num(M, 0);
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        num[idx] ++;
    }

    //差が０のとき
    if(d == 0){
        ll ans = 0;
        for (int i = 0; i < num.size(); i++) {
            if(num[i] == 0) continue;
            ans += ll(num[i]) - 1;
        }
        cout << ans << endl;
        return 0;
    }

    //あまりで分割(差が一定＝等差数列になるように分けてあげる)
    vector<vector<int>> mod_num(d);
    for (int i = 0; i < M; i++) {
        int mod = i % d;
        mod_num[mod].pb(num[i]);
    }
    
    ll ans = 0;

    //全部のあまりに対して行う
    for (int mod = 0; mod < d; mod++) {
        //マイナス無限でDP配列初期化
        //DPにはその回までの各手の残せる数の最大値を格納
        int sz = mod_num[mod].size();
        vector<vector<ll>> dp(sz+1,vector<ll>(2, -LINF)); //最初0を置きたいため、n+1の配列にしたので注意
        //最初はすべて0で初期化
        for (int i = 0; i < 2; i++) dp[0][i] = 0;
        //各数字の出現回数の合計
        ll sum = 0;
        for (int i = 0; i < sz; i++) {
            sum += mod_num[mod][i];
            //DPをおこなう
            //今の状態を全探索
            //0 : 残す
            //1 : 残さない
            for (int now = 0; now < 2; now++) {
                //前までの残せる最大数をすべて調べる
                for (int bef = 0; bef < 2; bef++) {
                    //二個連続では差がｄの組みになるので残せない(問題記載)
                    if(now == 0 && bef == 0) continue;
                    //前の回の結果をもとに今回の手の最大値を計算
                    int add = 0;
                    //残すのであれば自分の値を足す
                    if(now == 0) add = mod_num[mod][i];
                    //最大値計算
                    dp[i + 1][now] = max(dp[i + 1][now], dp[i][bef] + ll(add));
                }
            }
        }
        //求めたいのは消す最小値
        //すべて消すパターンから残す最大値を引くと消す最小値が求まる
        ans += sum - max({dp[sz][0], dp[sz][1]});
    }
    cout << ans << endl;
}