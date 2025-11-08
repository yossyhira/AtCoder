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
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    vector<vector<string>> ans;
    int cnt = 0;
    for (int i = 0; i + m <= n; i++) {
        for (int j = 0; j + m <= n; j++) {
            vector<string> block;
            for (int k = 0; k < m; k++) {
                string s;
               for (int l = 0; l < m; l++) {
                    s.pb(mp[i + k][j + l]);
                }
                //cout << s << endl;
               block.pb(s);
            }
            int cnt_ok = 0;
            for (int i = 0; i < ans.size(); i++) {
                bool ng = true;
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < m; k++) {
                        //cout << block[j][k];
                        if(ans[i][j][k] != block[j][k]) ng = false;
                    }
                    //cout << endl;
                }
                //cout << endl;
                if(!ng) cnt_ok ++;
            }
            if(cnt_ok == ans.size()){
                ans.pb(block);
            }
        }
    }
    cout << ans.size() << endl;

    return 0;
}
