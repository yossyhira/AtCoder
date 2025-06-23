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
    vector<int> server_array(1);
    int server = 0;
    vector<P> pc(n);
    vector<vector<int>> word_order(n);
    vector<string> add_txt(q+1, "");
    int add_txt_idx = 1;

    for (int i = 0; i < n; i++) pc[i] = {i, -1};
    vector<tuple<int, int, string>> query(q);
    int last;
    for (int qi = 0; qi < q; qi++) {
        int mode, p;
        cin >> mode >> p;
        p --;
        if(mode == 2){
            string txt;
            cin >> txt;
            query[i] = {mode, q, txt};
        }else{
            if(mode == 3) last = i;
            query[i] = {mode, q, ""};
        }
    }

    for (int qi = 0; qi < q; qi++) {
        int mode, p;
        cin >> mode >> p;
        p --;
        if(mode == 1){
            pc[p] = server;
        }else if(mode == 2){
            string txt;
            cin >> txt;
            add_txt[add_txt_idx] = txt;
            word_order[pc[p].fi].pb(add_txt_idx);
            add_txt_idx ++;
        }else{
            server = pc[p];
        }
    }
    cout << server << endl;
}