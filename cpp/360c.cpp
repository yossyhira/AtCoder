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
    int n;
    cin >> n;
    vector<int> box(n);
    for (int i = 0; i < n; i++) {
        int bx;
        cin >> bx;
        bx --;
        box[i] = bx;
    }
    vector<vector<int>> num(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num[box[i]].pb(x);
    }
    for (int i = 0; i < n; i++) {
        sort(num[i].begin(), num[i].end(), greater<int>());
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(num[i].size() == 1 || num[i].size() == 0) continue;
        int sz = num[i].size();
        for (int j = 1; j < sz; j++) {
            ans += num[i][j];
        }
    }
    cout << ans << endl;
}