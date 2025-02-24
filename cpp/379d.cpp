#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    vector<pair<int, ll>> query;
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        if(num == 1){
            query.push_back({num, 0});
            continue;
        }
        ll x;
        cin >> x;
        query.push_back({num, x});
    }
    
    //クエリを後ろから見る(伸びと切る長さを累積和で考えられる)
    reverse(query.begin(), query.end());
    
    vector<ll> plant;
    vector<ll> cut;
    ll sum = 0;
    for (int i = 0; i < query.size(); i++) {
        int num;
        ll x;
        tie(num, x) = query[i];
        
        if(num == 1){
            plant.push_back(sum);//どれくらい成長したか
        }
        else if(num == 2){
            sum += x;//伸びの累積
        }else{
            cut.push_back(x + sum); //最後に取り除く長さ
        }
    }

    //取り除いた順に変更
    reverse(cut.begin(), cut.end());

    auto f = [&](ll r) {
        int pos = lower_bound(plant.begin(), plant.end(), r) - plant.begin(); //lower_bound(x.begin(), x.end(), r) - x.begin();
        return pos;
    };

    ll befpos = plant.size();
    //最後にまとめて取り除く処理をする
    for (int i = 0; i < cut.size(); i++) {
        ll num = cut[i];
        ll nowPos = f(num);
        //新しく取り除く区間を計算
        ll ans = befpos - nowPos;

        //その大きさの植木鉢はない
        if(nowPos == plant.size()) ans = 0;
        //すでに取り除いた植木鉢
        if(ans < 0) ans = 0;

        cout << ans << endl;

        //取り除いた植木鉢更新
        befpos = nowPos;
    }
    return 0;
}