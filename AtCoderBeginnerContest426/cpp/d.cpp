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
    int q;
    cin >> q;
    for (int qi = 0; qi < q; qi++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int f_0 = -1, f_1 = -1;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '0'){
                 f_0 = i;
                 break;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '1'){
                 f_1 = i;
                 break;
            }
        }

        if(f_0 == -1 || f_1 == -1){
            cout << 0 << endl;
            continue;
        }
        //すべて0
        int zero_point_s = f_0, zero_point_g = f_0;
        int st_zero = 0, gl_zero=0;
        int mx_zero = -1, cnt_len_zero = 0;
        bool ok_zero = false;
        for (int i = 0; i < n; i++) {
            if(s[i] == '0' && s[i] == s[i + 1]){
                ok_zero = true;
                cnt_len_zero ++;
                gl_zero ++;
            }else{
                if(ok_zero && (mx_zero <= cnt_len_zero)){
                    zero_point_s = st_zero;
                    zero_point_g = gl_zero;
                    mx_zero = cnt_len_zero;
                }
                st_zero = i + 1;
                gl_zero = i + 1;
                cnt_len_zero = 0;
                ok_zero = false;
            }
        }
        /*
        for (int i = s_2; i >= 0; i --) {
            if(s[i] != '0') {
                zero_point_s = i;
                break;
            }
        }
        for (int i = g_2; i < n; i++) {
            if(s[i] != '0'){
                zero_point_g = i;
                break;
            }
        }
        */
        //cout << zero_point_s << " " << zero_point_g<< endl;
        ll cnt_zero = 0;
        for (int i = 0; i < zero_point_s; i++) {
            if(s[i] == '1') cnt_zero ++;
            else cnt_zero += 2;
        }
        for (int i = (zero_point_g + 1); i < n; i++) {
            if(s[i] == '1') cnt_zero ++;
            else cnt_zero += 2;
        }
        
        //すべて1
        int one_point_s = f_1, one_point_g = f_1;
        int st_one = 0, gl_one=0;
        int mx_one = -1, cnt_len_one = 0;
        bool ok_one = false;
        for (int i = 0; i < n; i++) {
            if(s[i] == '1' && s[i] == s[i + 1]){
                ok_one = true;
                cnt_len_one ++;
                gl_one ++;
            }else{
                if(ok_one && (mx_one <= cnt_len_one)){
                    one_point_s = st_one;
                    one_point_g = gl_one;
                    mx_one = cnt_len_one;
                }
                st_one = i + 1;
                gl_one = i + 1;
                cnt_len_one = 0;
                ok_one = false;
            }
        }
        //cout << one_point_s << " " << one_point_g<< endl;
        ll cnt_one = 0;
        for (int i = 0; i < one_point_s; i++) {
            if(s[i] == '0') cnt_one ++;
            else cnt_one += 2;
        }
        for (int i = (one_point_g + 1); i < n; i++) {
            if(s[i] == '0') cnt_one ++;
            else cnt_one += 2;
        }
        //cout << cnt_zero << cnt_one << endl;
        cout <<min(cnt_zero, cnt_one) << endl;
    }
}