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
const int mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n+1, vector<int>(7, 0));
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 7; j++) {
            if(s[i] == 'a' && j == 0){
                dp[i + 1][0] = (dp[i][0] + 1) % mod;

            }else if(s[i] == 't' && j == 1){
                 dp[i + 1][j] = (dp[i][j-1] + dp[i][j]) % mod;

            }else if(s[i] == 'c' && j == 2){
                 dp[i + 1][j] = (dp[i][j-1] + dp[i][j]) % mod;

            }else if(s[i] == 'o' && j == 3){
                 dp[i + 1][j] = (dp[i][j-1] + dp[i][j]) % mod;

            }else if(s[i] == 'd' && j == 4){
                 dp[i + 1][j] = (dp[i][j-1] + dp[i][j]) % mod;

            }else if(s[i] == 'e' && j == 5){
                 dp[i + 1][j] = (dp[i][j-1] + dp[i][j]) % mod;

            }else if(s[i] == 'r' && j == 6){
                 dp[i + 1][j] = (dp[i][j-1] + dp[i][j]) % mod;
            }else{
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    cout << dp[n][6] << endl;
}
/*
switch(s[i]){
            case 'a':
                dp[i + 1][0] = (dp[i][0] + 1) % mod;
                break;
            case 't';
                dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
                break;
            case 'c';
                dp[i + 1][2] = (dp[i][0] + dp[i][1]) % mod;
                break;
            case 'r';
                dp[i + 1][3] = (dp[i][0] + dp[i][1]) % mod;
                break;
            case 'd';
                dp[i + 1][4] = (dp[i][0] + dp[i][1]) % mod;
                break;
            case 'e';
                dp[i + 1][5] = (dp[i][0] + dp[i][1]) % mod;
                break;
            case 'r';
                dp[i + 1][6] = (dp[i][0] + dp[i][1]) % mod;
                break;
            default:
                break;
        }
*/