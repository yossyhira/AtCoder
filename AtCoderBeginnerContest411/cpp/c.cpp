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
    int n, q;
    cin >> n >> q;
    vector<bool> white(n, true);
    int ans = 0;
    for (int i = 0; i < q; i++) {
        int idx;
        cin >> idx;
        idx--;
        if(white[idx]){
            /*bool white_l = false, white_r = false;
            if(white[idx-1]) white_l = true;
            if(white[idx+1]) white_r = true;
            if(white_l && white_r)ans ++;*/
            
            bool brack_l = false, brack_r = false;
            if(0 <= (idx - 1)){
                if(!white[idx-1]) brack_l = true;
            }
            if((idx + 1) < n){
                if(!white[idx+1]) brack_r = true;
            }

            if(brack_l && brack_r)ans --;
            else if(!brack_l && !brack_r)ans ++;

            white[idx] = false;
        }else{
            bool white_l = false, white_r = false;
            if(0 <= (idx - 1)){
                if(white[idx-1]) white_l = true;
            }
            if((idx + 1) < n){
                if(white[idx+1]) white_r = true;
            }

            if(white_l && white_r)ans --;
            else if(!white_l && !white_r)ans ++;
            white[idx] = true;
        }
        cout << ans << endl;
    }
}