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
using LP = pair<ll, int>;
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
const int mod = 1e9 + 7; //ll % modしても自動でmod型変換でllなるからバグらないよ

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<LP> num(n+1);
    num[0].fi = 0;
    num[0].se = 0;
    for (int i = 1; i <= n; i++) {
        cin >> num[i].fi;
        num[i].se = i;
    }
    sort(num.begin(), num.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;//第1引数
    });
    vector<int> people(n+1);
    vector<vector<int>> bet(n+1);
    vector<ll> ans;
    for (int i = 0; i < (n + 1); i++) {
        cout << num[i].fi << " ";
    }
    cout << endl;
    for (int i = 0; i < (n + 1); i++) {
        cout << num[i].se << " ";
    }
    cout << endl;


    ll subans = 0;
    for (int i = 0; i < (n + 1); i++) {
        ll mn = LINF;
        people[num[i].se] = i;
        if(0 < i){
            mn = abs(num[i].fi - num[i-1].fi);
            bet[i].pb(i-1);
        }
        if(i < (n-1)){
            chmin(mn, abs(num[i].fi - num[i+1].fi));
            bet[i].pb(i+1);
        }
        subans -= mn;
    }
    ans.pb(subans);
    
    for (int i = n; i > 0; i--) {
        int now = people[i];
        cout << i << " now : " << now << endl;
        ll mn = LINF;
        vector<int> look;
        for (int j = 0; j < bet[now].size(); j++) {
            int now_bet = bet[now][j];
            look.pb(now_bet);
            chmin(mn, abs(num[now].fi - num[now_bet].fi));
        }
        subans -= mn;
        //ans.pb(subans);
        if(look.size() == 1){
             if(abs(num[now].fi - num[look[0]].fi) < abs(num[look[0]].fi - num[bet[look[0]][0]].fi)){
                subans -= abs(num[now].fi - num[look[0]].fi);
            };
            for (int j = 0; j < bet[look[0]].size(); j++) {
                if(bet[look[0]][j] == now){
                    bet[look[0]].erase(bet[look[0]].begin()+j); //i番目の要素削除
                }
            }
        }else{
            for (int j = 0; j < bet[look[0]].size(); j++) {
                if(bet[look[0]][j] == now){
                    bet[look[0]][j] = look[1] ; 
                }else{
                    if(abs(num[now].fi - num[look[0]].fi) < abs(num[look[0]].fi - num[bet[look[0]][j]].fi)){
                        subans -= abs(num[now].fi - num[look[0]].fi);
                    };
                }
            }


            for (int j = 0; j < bet[look[1]].size(); j++) {
                if(bet[look[0]][j] == now){
                    bet[look[0]][j] = look[0] ; 
                }else{
                    if(abs(num[now].fi - num[look[1]].fi) < abs(num[look[1]].fi - num[bet[look[1]][j]].fi)){
                        subans -= abs(num[now].fi - num[look[1]].fi);
                    };
                }
            }
        }
        
        if(look.size() == 1){
            if(abs(num[now].fi - num[look[0]].fi) < abs(num[look[0]].fi - num[bet[look[0]][0]].fi)){
                subans += abs(num[look[0]].fi - num[bet[look[0]][0]].fi);
            };
        }else{
            for (int j = 0; j < bet[look[0]].size(); j++) {
                if(bet[look[0]][j] == now){
                    bet[look[0]][j] = look[1] ; 
                }
            }
            for (int j = 0; j < bet[look[1]].size(); j++) {
                if(bet[look[0]][j] == now){
                    bet[look[0]][j] = look[0] ; 
                }
            }
        }

    }
    int sz = ans.size();
    for (int i = (sz-1); i >= 0; i--) {
        cout << ans[i] << endl;
    }
}