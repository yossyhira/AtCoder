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
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        //あり得る最大値
        // 2^18くらいまでok
        int mxn = 1 << n;
        vector<bool> visited(mxn, false);
        visited[0] = true;
        bool ok = false;
        //i : 訪問した場所
        //j : 1を立てるbitの位置
        for (int i = 0; i < mxn; i++) {
            //自分より小さい値の頂点からしか遷移しないので(後ろに戻る遷移はない)
            // i回目で到達していない頂点はその後到達することは絶対ない
            if(!visited[i]) continue;
            for (int j = 0; j < n; j++) {
                //orを取ってきて，jbit目に1を立てる
                //例
                // 100100100 | (1 << 0); => 100100101; //0ビット目は0なので1が立った
                // 100100100 | (1 << 2); => 100100100; //2ビット目は既に1なので変わらない
                int num = i | (1 << j);
                //変わってなければコンティニュー
                if(i == num) continue;
                //訪問したらダメな頂点ならコンティニュー(この問題独自の処理)
                if(s[num - 1] == '1') continue;
                //訪問済みにする
                visited[num] = true;
                //最後の頂点にたどり着けたらbreak;(この問題独自の処理)
                if(visited[mxn - 1]){
                    ok = true;
                    break;
                }
            }
            if(ok) break;
            
        }
        if(ok) yn;
    }
}