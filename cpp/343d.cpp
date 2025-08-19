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
    int n, t;
    cin >> n >> t;
    vector<ll> num(n, 0);
    set<ll> se;
    se.insert(0);
    map<ll, int> M1;
    M1[0] = n;
    for (int i = 0; i < t; i++) {
        int idx; 
        ll b;
        cin >> idx >> b;
        idx --;
        ll now = num[idx];
        M1[now] --;
        if(M1[now] == 0) se.erase(now);
        num[idx] += b;
        ll after_now = num[idx];
        M1[after_now] ++;
        se.insert(after_now);
        cout << se.size() << endl;
    }
}