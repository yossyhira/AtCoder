#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, qe;
    cin >> n >> qe;
    //何かをまとめて移動させたいときは袋という概念を使う
    //新しくひとまとまりにできる配列を使う
    //鳥と袋
    vector<int> bird_in_bag(n);
    for (int i = 0; i < n; i++) {
        bird_in_bag[i] = i;
    }
    //巣から袋
    vector<int> home_to_bag(n);
    for (int i = 0; i < n; i++) {
        home_to_bag[i] = i;
    }
    
    //袋から巣
    vector<int> bag_to_home(n);
    for (int i = 0; i < n; i++) {
        bag_to_home[i] = i;
    }
    
    for (int i = 0; i < qe; i++) {
        int q;
        cin >> q;
        if(q == 1){
            int a, b;
            cin >> a >> b;
            a --;
            b --;
            int bag = home_to_bag[b];
            bird_in_bag[a] = bag;
        }
        else if(q == 2){
            int a, b;
            cin >> a >> b;
            a --;
            b --;
            int bagA = home_to_bag[a];
            int bagB = home_to_bag[b];
            home_to_bag[a] = bagB;
            home_to_bag[b] = bagA;

            bag_to_home[bagA] = b;
            bag_to_home[bagB] = a;
            
        }else{
            int a;
            cin >> a;
            a --;
            int bag = bird_in_bag[a];
            int home =  bag_to_home[bag];
            cout << home + 1 << endl;
        }
    }

    return 0;
}