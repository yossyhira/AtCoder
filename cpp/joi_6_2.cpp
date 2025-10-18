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
    int n, k;
    cin >> n >> k;
    vector<bool> card(n, false);
    bool zero = false;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x --;
        if(0 <= x) card[x] = true;
        else if(x == -1) zero = true;
    }
    vector<int> len;
    int ans = 0;
    {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
           if(card[i]) cnt ++;
           else{
                chmax(ans, cnt);
                len.pb(cnt);
                cnt = 0;
                len.pb(cnt);
            }
        }
        len.pb(cnt);
        chmax(ans, cnt);
    }
    if(!zero){
        cout << ans << endl;
        return 0;
    }else{
        for (int i = 0; i < len.size(); i++) {
            int l = 0, r = 0;
            //cout << len[i] << " ";
            if(len[i] == 0){
                if(0 <= (i - 1)) l = len[i-1];
                if((i + 1) < (int)len.size()) r = len[i + 1];
                chmax(ans, (l + r + 1));
            }
        }
        //cout << endl;
        cout << ans << endl;
    }
    return 0;
}