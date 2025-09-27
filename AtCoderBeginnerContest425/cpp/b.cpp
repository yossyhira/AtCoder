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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    set<int> se;
    set<int> se_2;
    for (int i = 1; i <= n; i++) {
        se_2.insert(i);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if(num[i] == -1) continue;
        if (se.insert(num[i]).second) {
            se_2.erase(num[i]);
        }else {
            ok = false;
        }
    }
    if(ok){
        yes;
        for (int i = 0; i < n; i++) {
            int ans = num[i];
            if(ans == -1){
                ans = *se_2.begin();
                se_2.erase(ans);
            }
            cout << ans << " ";
        }
        cout << endl;
    }else{
        no;
    }
}