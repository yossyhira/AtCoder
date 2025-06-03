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
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int len;
        cin >> len;
        string tex;
        cin >> tex;
        //cout << tex << endl;
        vector<pair<char, int>> num;
        {
            int cnt = 1;
            for (int i = 0; i < (len - 1); i++) {
                if(tex[i] != tex[i+1]){
                    num.pb({tex[i], cnt});
                    cnt = 1;
                }else cnt ++;
            }
            num.pb({tex[len - 1], cnt});
        }
        int max_point;
        int max_cnt = -1;
        for (int i = 0; i < num.size(); i++) {
            char c; int cnt;
            tie(c, cnt) = num[i];
            if(c == '1'){
                int hoge = max_cnt;
                chmax(max_cnt, cnt);
                if(hoge != max_cnt) max_point = i;
            }
        }
        vector<int> mc;
        for (int i = 0; i < num.size(); i++) {
            char c; int cnt;
            tie(c, cnt) = num[i];
            if(c == '1'){
               if(cnt == max_cnt) mc.pb(i);
            }
        }

        int Ans = INF;
        // 左に伸ばす処理(左端のこーな注意)
        bool ok = false;
        for (int im = 0; im < mc.size(); im++) {
            int ans = 0;
            max_point = mc[im];
            int one_cnt = 0, zero_cnt = 0;
            for (int i = (max_point - 1); i >= 0 ; i--) {
                char c; int cnt;
                tie(c, cnt) = num[i];
                if(c == '0'){
                    zero_cnt += cnt;
                }else{
                    one_cnt += cnt;
                    if(zero_cnt <= cnt){
                        ans += zero_cnt;
                        zero_cnt = 0;
                        one_cnt = 0;
                    }
                }
            }
            //cout << ans << endl;
            ans += one_cnt;
            //cout << ans << endl;
            
            zero_cnt = 0;
            one_cnt = 0;
            for (int i = (max_point + 1); i < num.size() ; i++) {
                char c; int cnt;
                tie(c, cnt) = num[i];
                if(c == '0'){
                    zero_cnt += cnt;
                }else{
                    one_cnt += cnt;
                    if(zero_cnt <= cnt){
                        ans += zero_cnt;
                        zero_cnt = 0;
                        one_cnt = 0;
                    }
                }
            }
            //cout << ans << endl;
            ans += one_cnt;
            chmin(Ans, ans);
        }
        if(num.size() == 1) Ans = 0;
        cout << Ans << endl;
    }
}
/*
反例
1
24
111111000000011111011111
*/