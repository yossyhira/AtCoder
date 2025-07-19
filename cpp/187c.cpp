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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    map<string, pair<bool, bool>> M1;
    for (int i = 0; i < n; i++) {
        bool mark = false;
        string txt = s[i];
        if(s[i][0] == '!'){
            txt = s[i].substr(1);
            mark = true;
        }
        if (M1.count(txt)) {
            bool a, b;
            tie(a, b) = M1[txt];
            if(mark){
                M1[txt] = {a, true};
                if(a){
                    cout << txt << endl;
                    return 0;
                }
            }else{
                M1[txt] = {true, b};
                if(b){
                    cout << txt << endl;
                    return 0;
                }
            }
        } else {
            bool a = false, b = false;
            if(mark){
                b = true;
            }else{
                a = true;
            }
            M1[txt] = {a, b};
        }
    }

    cout << "satisfiable" << endl;
}