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
    
    int n, k;
    cin >> n >> k;

    string tex;
    cin >> tex;

    int ocnt = 0;
    
    for (int i = 0; i < n; i++) {
        if(tex[i] == 'o'){
            ocnt ++;
           if((i - 1) < 0){
                tex[i + 1] = '.';
            }else if (n <= (i + 1)){
                tex[i - 1] = '.';
            }else{
                tex[i + 1] = '.';
                tex[i - 1] = '.';
            }
        }
    }
    int x = k - ocnt;
    if(x == 0){
        for (int i = 0; i < n; i++) {
            if(tex[i] == '?'){
                cout << '.';
            }else{
                cout << tex[i];
            }
        }
        cout << endl;
        return 0;
    }

    vector<P> num;
    bool flag = false;
    int l = 0, r = 0, cnt = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if(tex[i] == '?'){
            if(!flag) l = i;
            r = i;
            flag = true;
            cnt ++;
        }else if(flag){
            num.pb({l, r});
            mx += (cnt + 1) / 2;
            cnt = 0;
            flag = false;
        }
    }
    if(cnt != 0){
        num.pb({l, r});
            mx += (cnt + 1) / 2;
            cnt = 0;
            flag = false;
    }
    if(x != mx){
        cout << tex << endl;
        return 0;
    }
    for (int i = 0; i < num.size(); i++) {
        int l, r;
        tie(l, r) = num[i];
        int len = r - l + 1;
        if(len % 2 == 0) continue;
        int j = 0;
        for (int i = l; i < (l + len); i ++) {
            if((j % 2) == 0)tex[i] = 'o';
            else tex[i] = '.';
            j ++;
        }
    }
    cout << tex << endl;

    return 0;
}