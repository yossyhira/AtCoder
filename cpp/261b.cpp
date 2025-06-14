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
#define yes cout<<"correct"<<endl
#define yesr {cout<<"correct"<<endl; return 0;}
#define no cout<<"incorrect"<<endl
#define nor {cout<<"incorrect"<<endl; return 0;}
#define yn {cout<<"correct"<<endl;}else{cout<<"incorrect"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    auto f = [&](char c, char c2){
        if(c == 'D' && c2 == 'D') return true;
        if(c == 'W' && c2 == 'L') return true;
        if(c == 'L' && c2 == 'W') return true;
        return false;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(mp[i][j] == '-') break;
            if(!f(mp[i][j], mp[j][i])) nor;
        }
    }
    yesr;
}