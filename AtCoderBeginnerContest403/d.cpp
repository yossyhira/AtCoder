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
    int n, d;
    cin >> n >> d;
    vector<int> num(n);
    map<int, int> M1;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (M1.count(num[i])) {
            M1[num[i]]++;
        } else {
            M1[num[i]] = 1;
        }
    }
    set<int> used;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(used.count(num[i])) continue;
        int big = num[i] + d;
        int small = num[i] - d;
        if(M1.count(big) && M1.count(small)){
            int base = M1[num[i]];
            int link = M1[big] + M1[small];
            if(base <= link){
                ans += base;
                used.insert(num[i]);
            }else{
                ans += link
                used.insert(big);
                used.insert(small);
            }
        }
    }

    cout << ans << endl;
}