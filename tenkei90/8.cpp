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
const string t = "atcoder";
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n+1, vector<int>(t.size(), 0));
    /*for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j <= t.size(); j++) {
            dp[i + 1][j] = (dp[i][j] + dp[i+1][j]) % mod;
            if(j < t.size() && s[i] == t[j]){
                dp[i + 1][j + 1] = (dp[i][j] + dp[i+1][j + 1]) % mod;
            }
        }
    }*/
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            dp[i + 1][j] = dp[i][j];
            if(s[i] == t[j]){
                int add = dp[i][j-1];
                if(j == 0) add = 1;
                dp[i + 1][j] = (add + dp[i][j]) % mod;
            }
            
        }
    }
    cout << dp[n][t.size()-1] << endl;
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