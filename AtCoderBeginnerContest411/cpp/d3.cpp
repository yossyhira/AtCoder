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

    vector<tuple<int, int, string>> query(q);
    int last;
    for (int qi = 0; qi < q; qi++) {
        int mode, p;
        cin >> mode >> p;
        p --;
        if(mode == 2){
            string txt;
            cin >> txt;
            reverse(txt.begin(), txt.end());
            query[qi] = {mode, p, txt};
        }else{
            if(mode == 3) last = qi;
            query[qi] = {mode, p, ""};
        }
    }
    int x;
    string ans = "";
    bool wite = true;
    for (int qi = last; qi >= 0; qi--) {
        int mode, p;
        string txt;
        tie(mode, p, txt) = query[qi];
        //番号(p)がサーバに入れるやつ(x)と次のサーバのクエリ(mode3)まで待機
        if(mode == 1 && p == x){
            wite = true;
        }
        //番号(p)がサーバに入れるやつ(x)と同じ
        //wite=trueのときは結局サーバの文字列で置き換わるので見る意味ない
        else if(mode == 2 && p == x && !wite){
            ans.append(txt);
        }
        else if(mode == 3 && wite){
            x = p;
            wite = false;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

/*
サンプルにないケース
2 3
2 2 abc
1 1
3 2

ans:abc
*/
