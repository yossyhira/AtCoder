#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> x(m);
    for (ll i = 0; i < m ; i++) {
        cin >> x[i].first;
    }
    for (ll i = 0; i < m ; i++) {
        cin >> x[i].second;
    }
    sort(x.begin(), x.end());
 
    ll sumStone = 0, sumjudge = 0;
    
    for (ll i = 0; i < m - 1; i++) {
        ll nowPosX, nowStone;
        ll nextPosX, nextStone;
        tie(nowPosX, nowStone) = x.at(i);
        sumjudge += nowPosX * nowStone;
        tie(nextPosX, nextStone) = x.at(i + 1);
        
        nowStone += sumStone;
        if(nowStone - (nextPosX - nowPosX) >= 0){
            sumStone =  nowStone - (nextPosX - nowPosX);
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    ll nowPosX, nowStone;
    ll nextPosX, nextStone;
    tie(nowPosX, nowStone) = x.at(m - 1);
    sumjudge += nowPosX * nowStone;
    nowStone += sumStone;
    if(nowStone - (n - nowPosX) >= 0){
        sumStone =  nowStone - (n - nowPosX);
    }else{
        cout << -1 << endl;
        return 0;
    }
    
    if(sumStone != 1){
        cout << -1 << endl;
        return 0;
    }
    cout << ((n*(n+1))/2) - sumjudge << endl;
}