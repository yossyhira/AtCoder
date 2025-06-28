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
    int n, m;
    cin >> n >> m;
    vector<string> store(n);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
    }
    int ans = 1000;
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        vector<bool> taste(m, false);
        for (int j = 0; j < n; j++) {
            if((i & (1 << j)) != 0){
                for (int k = 0; k < m; k++) {
                    if(store[j][k] == 'o') taste[k] = true;
                }
                cnt ++;
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if(!taste[j]) ok = false; 
        }

        if(ok) chmin(ans, cnt);
    }
    
    cout << ans << endl;
}