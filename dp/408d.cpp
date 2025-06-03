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
    int test;
    cin >> test;
    for (int t = 0; t < test; t++) {
        int n;
        cin >> n;
        string tex;
        cin >> tex;
        vector<vector<int>> dp(n+1, vector<int>(3, INF));
        for (int i = 0; i < 3; i++) dp[0][i] = 0;
        
        for (int i = 1; i <= n; i++) {
            if(tex[i - 1] == '1'){
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][2] = (min(dp[i - 1][1], dp[i - 1][2]) + 1);
            }else{
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = (min(dp[i - 1][0], dp[i - 1][1]) + 1);
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            }
        }

        int ans = min({dp[n][0], dp[n][1], dp[n][2]}); 
        cout << ans << endl;
    }
}
