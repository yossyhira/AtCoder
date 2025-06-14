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
    string s;
    cin >> s;
    vector<int> num(10, 0);
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        num[x] ++;
    }
    const int mx = 4e6;
    int ans = 0;
    for (int i = 0; i < mx; i++) {
        ll subans = (ll)i * i;
        string s1 = to_string(subans);
        int n1 = s1.size();
        vector<int> subnum(10, 0);
        if(n1 < n) subnum[0] += (n-n1);
        for (int i = 0; i < n1; i++) {
            int digit = s1[i] - '0';
            subnum[digit] ++;
        }
        bool ok = true;
        for (int i = 0; i < 10; i++) {
            if(num[i] != subnum[i]) ok = false;
        }
        if(ok) ans ++;
    }
    cout << ans << endl;
}