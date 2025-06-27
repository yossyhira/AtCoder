//縦横斜め全探索 8方向全探索
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
    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }
    //縦全探索
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if(field[i][j] == '#') cnt++;
        }
        if(4 <= cnt) yesr;
        int now_i = 6, del_i = 0;
        while(1){
            if(n <= now_i) break;
            if(field[del_i][j] == '#') cnt --;
            if(field[now_i][j] == '#') cnt ++;
            if(4 <= cnt) yesr;
            del_i ++;
            now_i++;
        }
    }
    
    //横全探索
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 6; j++) {
            if(field[i][j] == '#') cnt++;
        }
        if(4 <= cnt) yesr;
        int now_j = 6, del_j = 0;
        while(1){
            if(n <= now_j) break;
            if(field[i][del_j] == '#') cnt --;
            if(field[i][now_j] == '#') cnt ++;
            if(4 <= cnt) yesr;
            del_j ++;
            now_j++;
        }
    }
    
    //ななめ
    //右上の角まで
    for (int j = 5; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if(field[i][j-i] == '#') cnt++;
        }
        if(4 <= cnt) yesr;
        int now_i = 6, del_i = 0;
        int now_j = (j-6), del_j = j;
        while(1){
            if(now_j < 0 || n <= now_i) break;
            if(field[del_i][del_j] == '#') cnt --;
            if(field[now_i][now_j] == '#') cnt ++;
            if(4 <= cnt) yesr;
            del_i ++;
            del_j --;
            now_i ++;
            now_j --;
        }
    }
    
    for (int j = (n-6); j >= 0; j--) {
        int cnt = 0;
        for (int i = (n-1); i >= (n-6); i--) {
            if(field[i][j+((n-1) - i)] == '#') cnt++;
        }
        if(4 <= cnt) yesr;
        int now_i = (n-7), del_i = (n-1);
        int now_j = j+6, del_j = j;
        while(1){
            if(now_i < 0 || n <= now_j) break;
            if(field[del_i][del_j] == '#') cnt --;
            if(field[now_i][now_j] == '#') cnt ++;
            if(4 <= cnt) yesr;
            del_i --;
            del_j ++;
            now_i --;
            now_j ++;
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(field[i].begin(), field[i].end());
    }
    for (int j = 5; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if(field[i][j-i] == '#') cnt++;
        }
        if(4 <= cnt) yesr;
        int now_i = 6, del_i = 0;
        int now_j = (j-6), del_j = j;
        while(1){
            if(now_j < 0 || n <= now_i) break;
            if(field[del_i][del_j] == '#') cnt --;
            if(field[now_i][now_j] == '#') cnt ++;
            if(4 <= cnt) yesr;
            del_i ++;
            del_j --;
            now_i ++;
            now_j --;
        }
    }
    
    for (int j = (n-6); j >= 0; j--) {
        int cnt = 0;
        for (int i = (n-1); i >= (n-6); i--) {
            if(field[i][j+((n-1) - i)] == '#') cnt++;
        }
        if(4 <= cnt) yesr;
        int now_i = (n-7), del_i = (n-1);
        int now_j = j+6, del_j = j;
        while(1){
            if(now_i < 0 || n <= now_j) break;
            if(field[del_i][del_j] == '#') cnt --;
            if(field[now_i][now_j] == '#') cnt ++;
            if(4 <= cnt) yesr;
            del_i --;
            del_j ++;
            now_i --;
            now_j ++;
        }
    }
    no;
    
}
/*
8
........
.......#
....#.#.
...#.#..
..#.....
.#.#....
........
........

8
........
.......#
......#.
.....#..
........
...#....
........
........

10
..........
.........#
........#.
..........
......#...
.....#....
..........
..........
..........
..........

*/