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
    string test;
    test = tex;
    int Qcnt = 0;
    for (int i = 0; i < n; i++) {
        if(tex[i] == '?') Qcnt ++;
        if(tex[i] == 'o'){
            k --;
            if(tex[i - 1] == '?'){
                tex[i - 1] = '.';
                Qcnt --;
            }
            if(tex[i + 1] == '?'){
                tex[i + 1] = '.';
            }
        }
    }

    if(k == 0){
        for (int i = 0; i < n; i++) {
            if(test[i] == '?'){
                cout << '.';
            }else{
                cout << test[i];
            }
        }
        return 0;
    }

    bool flag = false;
    int cnt = 0;
    vector<P> q;
    for (int i = 0; i < n; i++) {
        if(tex[i] == '?'){
            flag = true;
            cnt ++;
        }
        if(flag && tex[i] != '?'){
            flag = false;
            q.pb({i - cnt , cnt});
            cnt = 0;
        }
    }
    //cout << Qcnt << endl;
    if(q.size() == k){
        for (int i = 0; i < q.size(); i++) {
            int idx, num;
            tie(idx, num) = q[i];
            if(num == 1){
                tex[idx] = 'o';
            }
        }
    }

    cout << tex << endl;
}

/*
f(q.size() == k){
        for (int i = 0; i < n; i++) {
            if(tex[i] == '?'){
                cout << 'o';
            }else{
                cout << tex[i];
            }
        }
        cout << endl;
        return 0;
    }

    cout << tex << endl;
*/