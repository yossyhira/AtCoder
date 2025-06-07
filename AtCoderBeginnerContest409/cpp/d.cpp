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
    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        string tex;
        cin >> tex;
        int st = 0;
        for (int i = 0; i < (n-1); i++) {
            if(tex[i+1] < tex[i]){
                st = i;
                break;
            }
        }

        int gt = n-1;
        for (int i = st+1; i < n; i++) {
            if(tex[st] < tex[i]){
                gt = i-1;
                break;
            }
        }
        
        for (int i = 0; i < st; i++) {
            cout << tex[i];
        }
        for (int i = st+1; i <= gt; i++) {
            cout << tex[i];
        }
        cout << tex[st];
        for (int i = gt+1; i < n; i++) {
            cout << tex[i];
        }
        cout << endl;
    }

}