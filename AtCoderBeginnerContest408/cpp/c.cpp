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
    int n, m;
    cin >> n >> m;
    vector<int> num(n+1, 0);
    vector<int> addNum(n, 0);
    for (int i = 0; i < m; i++) {
        int l , r;
        cin >> l >> r;
        l --;
        r --;
        num[l] ++;
        num[r+1] --;
    }
    for (int i = 1; i <= n; i++) {
        num[i] += num[i - 1];
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int x = num[i];
        chmin(ans, x);
    }
    cout << ans <<endl;
}