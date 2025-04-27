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
    string t, u;
    cin >> t >> u;
    
    for (int i = 0; i <= (t.size() - u.size()); i++) {
        int ok = 0;
        for (int j = 0; j < u.size(); j++) {
            if(t[i+j] == '?'){
                ok ++;
                continue;
            }
            if(t[i+j] == u[j]) ok++;
        }
        if(ok == u.size()){
            yes;
            return 0;
        }
    }

    no;
    return 0;
}