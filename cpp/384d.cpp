#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, s;
    vector<ll> num;
    cin >> n >> s;
    //別のsumをあとで使いたい
    {
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            num.push_back(x);
            sum += x;
        }
        s = s % sum;
    }
    if(s == 0){
        cout << "Yes" << endl; 
        return 0;  
    } 
        
    ll sum = num[0];//一番目のものを入れておく
    ll r = 0;
    ll l = 0;
    bool frag = false;
    //連続部分列の和がちょうどsになるものがあるか尺取り
    //rが二周期分進んだら終わり
    while(r <= num.size()*2 - 1){
        
        //sumの方がsより小さければrを進める(長い範囲を見る)
        if(sum < s){
            r++;
            //r % num.size() -> 周期なので円環問題で考えられる
            sum += num.at(r % num.size());//進めた先のrを足す
        }
        //sumがsより大きければlを進める(rを固定して短い範囲を見る)
        else if(sum > s){
            //lは以下より一周期以内なのでnum.at(l)でよい(rと同じ表現したいからl % num.size()にした)
            sum -= num.at(l % num.size()); //進める前のl(エル)の値を引く
            l++;
            
            //lが一周期の終わりまで行ったら終わり
            if(l == num.size()) break; 

        }
        else{
            frag = true;//sumとsが一致した
            break;
        }
    }
    
    if(frag)cout <<"Yes"<< endl;
    else cout << "No" << endl;
    return 0;
}