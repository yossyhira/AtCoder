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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if((sum % 10) != 0){
        no;
        return 0;
    }
    const ll ans = sum / 10; 
    int st = 0, gl = 0;
    ll now = a[st];
    while(1){
        if(n <= st) break;
        while(1){
            if(ans < now) break;
            else if(ans == now){
                yes;
                return 0;
            }
            gl ++;
            gl %= n;
            now += a[gl];
        }
        now -= a[st];
        st ++;
    }
    no;
    /*
    //始まり
    for (int i = 0; i < n; i++) {
        ll now = a[i];
        int idx = i;
        while(1){
            if(gl < now) break;
            else if(gl == now){
                ans ++;
                break;
            }
            idx ++;
            idx %= n;
            now += a[idx];
        }
    }
    */
}