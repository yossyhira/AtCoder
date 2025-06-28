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
    int n, t;
    cin >> n >> t;
    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = n*i+j;
        }
    }
    vector<vector<int>> num(n*n);
    vector<int> tate(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //tate[i].insert(map[j][i]);
            num[map[j][i]].pb(i);
        }
    }
    vector<int> yoko(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //yoko[i].insert(map[i][j]);
            num[map[i][j]].pb(i);
        }
    }
    vector<int> naname(2, n);
    for (int i = 0; i < n; i++) {
        //naname[0].insert(map[i][i]);
        num[map[i][i]].pb(0);
    }
    for (int i = 0; i < n; i++) {
        //naname[1].insert(map[i][n-(i+1)]);
        num[map[i][n-(i+1)]].pb(1);
    }

    for (int ti = 0; ti < t; ti++) {
        int x;
        cin >> x;
        x --;
        for (int j = 0; j < num[x].size(); j++) {
            if(j == 0){
                tate[num[x][j]] --;
                if(tate[num[x][j]] == 0){
                    cout << ti+1 << endl;
                    return 0;
                }
            }else if(j == 1){
                yoko[num[x][j]] --;
                if(yoko[num[x][j]] == 0){
                    cout << ti+1 << endl;
                    return 0;
                }
                
            }else if(j == 2){
                naname[num[x][j]]--;
                if(naname[num[x][j]] == 0){
                    cout << ti+1 << endl;
                    return 0;
                }
                
            }else if(j == 3){
                naname[num[x][j]] --;
                if(naname[num[x][j]] == 0){
                    cout << ti+1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
}