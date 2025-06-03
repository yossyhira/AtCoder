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
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int n;
        cin >> n;
        string tex;
        cin >> tex;
        vector<int> cost(n+1, 0);
        int all_one_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if(tex[i - 1] == '1'){
                all_one_cnt ++;
                cost[i] = cost[i-1] + 1;
            }else{
                cost[i] = cost[i-1] - 1;
            }
        }
        int min_cost = INF;
        int ans = INF;
        int now_one_cnt = 0;
        int now_zero_cnt = 0;
        int i = -1;
        for(int c : cost){
            //cout << i << "回目" << endl;
            chmin(min_cost, c);
            if( 0 <= i){
                if(tex[i] == '1') now_one_cnt++;
                else now_zero_cnt ++;
            }
            int subans = now_zero_cnt + min_cost + (all_one_cnt - now_one_cnt);
            //cout << "now_zero_cnt : " << now_zero_cnt << endl;
            //cout << "mincost : " << min_cost << endl;
            //cout << "all_one_cnt : " << all_one_cnt << endl;
            //cout << "now_one_cnt : " << now_one_cnt << endl;
            //cout << "subans : " << subans << endl;
            chmin(ans, subans);
            i++;
        }
        cout << ans << endl;
    }
}