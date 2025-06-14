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
    string t;
    cin >> t;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == t){
            ans.pb(i+1);
            continue;
        }
        int tsz = t.size();
        int ssz = s.size();
        if(tsz == ssz){
            //置換
            int cnt = 0;
            for (int j = 0; j < tsz; j++) {
                if(t[j] != s[j]) cnt ++;
            }
            if(cnt == 1) ans.pb(i+1);
        }
        else if(tsz == (ssz + 1)){
            //削除
            int cnt = 0, idx = 0;
            for (int j = 0; j < tsz; j++) {
                if(j == (tsz - 1) && cnt == 0) break;
                if(t[j] != s[idx]){
                    cnt ++;
                }else{
                    idx ++;
                }
            }
            if(cnt <= 1) ans.pb(i+1);
        }
        else if(tsz == (ssz - 1)){
            //挿入
            int cnt = 0, idx = 0;
            for (int j = 0; j < ssz; j++) {
                if(j == (ssz - 1) && cnt == 0) break;
                if(s[j] != t[idx]){
                    cnt ++;
                }else{
                    idx ++;
                }
            }
            if(cnt <= 1) ans.pb(i+1);
        }
    }

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
}