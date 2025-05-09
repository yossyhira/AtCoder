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
int n, m;
void f(vector<int> a, int num){
    if(a.size() == 0) a.pb(1);
    else a.pb(num);
    if(a.size() == n){
        while((a.back()) <= m){
            for(int x : a) cout << x << " ";
            cout << "\n";
            a[a.size() - 1] = a.back() + 1;
        }
    }
    while (1){
        if(m < (a.back() + (n - a.size()))) break;
        f(a, a.back() + 1);
        a[a.size() - 1] = a.back() + 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    f({}, -1);
}