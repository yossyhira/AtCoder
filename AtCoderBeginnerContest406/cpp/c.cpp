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
    int n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    ll ans = 0;
    int st = 0, gt = 1;
    bool big = false, small = false;
    int smpos, bigpos;
    while(1){
        if(num[st] >= num[gt]) continue;
        if(!small && num[gt - 1] < num[gt] && num[gt+1] < num[gt]){
             small = true;
             smpos = gt;
        }
        if(!big && num[gt - 1] > num[gt] && num[gt+1] > num[gt]){ 
            big = true;
            bigpos = gt;
        }
        if(small && num[gt - 1] < num[gt] && num[gt+1] < num[gt]){
            ans ++;
            bool onaji;
            while(1){
                st++;
                if(num[st] >= num[st+1]) break;
                if(num[st - 1] < num[st] && num[st+1] < num[st]){
                    small = false;
                    onaji = true;
                    break;
                } 
                if(num[st - 1] > num[st] && num[st+1] > num[st]) {
                    big = false;
                    break;
                }
                ans ++;
            }
            if(onaji) st = smpos;
        }
        if(big && num[gt - 1] > num[gt] && num[gt+1] > num[gt]){
            ans ++;
            bool onaji;
            while(1){
                st++;
                if(num[st] >= num[st+1]) break;
                if(num[st - 1] < num[st] && num[st+1] < num[st]) {
                    small = false;
                    break;
                }
                if(num[st - 1] > num[st] && num[st+1] > num[st]){
                    big = false;
                    onaji = true;
                    break;
                } 
                ans ++;
            }
            if(onaji) st = bigpos;
            
        }
        if(gt == (n-1) && (!small || !big)){
            cout << 0 << endl;
            return 0;
        }
        gt++;
    }

    


}