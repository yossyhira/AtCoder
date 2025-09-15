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
using P = pair<ll, ll>;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll k;
    cin >> n >> k;
    priority_queue<P, vector<P>, greater<P>> q;//小さい順(昇順)に取り出す
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll cnt = 0;
    ll now = 0;
    for (int i = 0; i < n; i++) {
        while(!q.empty()){
            ll time; //距離
            ll people; //頂点
            tie(time, people) = q.top(); 
            if(a[i] < time) break;
            q.pop();
            cnt -= people;
        }
        if((cnt + c[i]) <= k){
            cnt += c[i];
            chmax(now, a[i]);
            q.emplace(now + b[i], c[i]);
            cout << now << endl;
        }else{
            while(!q.empty()){
                ll time; //距離
                ll people; //頂点
                tie(time, people) = q.top(); 
                cnt -= people;
                if((cnt + c[i]) <= k) {
                    q.pop();
                    while(!q.empty()){
                        ll same_time; //距離
                        ll same_people; //頂点
                        tie(same_time, same_people) = q.top();
                        if(same_time != time) break;
                        cnt -= same_people;
                        q.pop();
                    }
                    q.emplace(b[i] + time, c[i]);
                    cnt += c[i];
                    now = time;
                    cout << now << endl;
                    break;
                }
                q.pop();
            }
        }
    }
}