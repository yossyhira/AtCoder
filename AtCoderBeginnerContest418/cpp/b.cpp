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
   string s;
   cin >> s;
   vector<P> num;
   int sz = s.size();
   for (int i = 0; i < sz - 2; i++) {
    if(s[i] != 't') continue;
    int cnt = 1;
    if(s[i +1] == 't') cnt ++;
    for (int j = i + 2; j < sz; j++) {
        if(s[j] == 't'){
            cnt ++;
            num.pb({j - i + 1 - 2, cnt - 2});
        } 
    }
   }
   if(num.size() == 0){
    cout << 0 << endl;
    return 0;
   }
   sort(num.begin(), num.end(), [&](const auto &i, const auto &j) {
        return i.se * j.fi > j.se * i.fi;
    });

    double ans = ((double)(num[0].se) / (num[0].fi));
    printf("%.10f\n",ans);
}