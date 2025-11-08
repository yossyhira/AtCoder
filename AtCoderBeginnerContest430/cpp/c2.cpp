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
    int n, A, B;
    cin >> n >>  A >> B;
    string s;
    cin >> s;
    int l = 0, r = 0;
    int a_cnt = 0, b_cnt = 0;
    int ans = 0;
    while(r < (int)s.size()){
        if(s[r] == 'a') a_cnt ++;
        else b_cnt ++;
        cout <<"l : "<< l <<" r : " << r << " a : "<<a_cnt << " b : " << b_cnt << endl;
    
        if(b_cnt < B) r ++;
        else{
            cout << "else in" << endl;
            while(1){
                //cout << l << endl;
                if(A <= (((r - l) + 1) - (B - 1))){
                    cout << "ans : "<<l + 1 << r + 1 << endl;
                    ans ++;
                }
                if(s[l] == 'a') a_cnt --;
                else b_cnt --;
                cout <<"l : "<< l <<" r : " << r << " a : "<<a_cnt << " b : " << b_cnt << endl;
                if(b_cnt < B) {
                    break;
                }
                l ++;
            }
            r ++;
            cout << "else out" << endl;
        }
    }
    //cout << l << r << endl;
    //cout << ans << endl;
    while(1){
        if((int) s.size() <= l) break;
        if(s[l] == 'a') a_cnt --;
        else b_cnt --;
        if(A <= (((r - l)) - (B - 1))){
            ans ++;
        }
        l ++;
    }
    cout << ans << endl;

}