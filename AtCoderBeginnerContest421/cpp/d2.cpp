#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
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
#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll ans = 0;
    ll befx_s, befy_s;     
    ll befx_t, befy_t;     
    cin >> befx_s >> befy_s >> befx_t >> befy_t;
    ll n, m, l;
    cin >> n >> m >> l;
    vector<pair<char, ll>> s;
    vector<pair<char, ll>> t;
    for (int i = 0; i < m; i++) {
        char c;
        ll x;
        cin >> c >> x;
        s.eb(c, x);
    }
    for (int i = 0; i < l; i++) {
        char c;
        ll x;
        cin >> c >> x;
        t.eb(c, x);
    }
    
    //動き終わりの座標求める
    auto move = [&](char c, ll cnt, ll x, ll y){
        if(c == 'U'){
            x -= cnt;
        }
        else if(c == 'D'){
            x += cnt;
        }
        else if(c == 'R'){
            y += cnt;
        }
        else if(c == 'L'){
            y -= cnt;
        }
        return make_pair(x, y);
    };

    //共通区間を求めるために
    // 移動した区間(Ｌ,Ｒ)or(U, D)の
    //小さい座標，大きい座標の順で返す
    auto LR = [&](ll bx, ll by, ll ax, ll ay){
        if((bx == ax) && (ay < by)){
            return make_tuple(ax, ay, bx, by);
        }
        else if((by == ay) && (ax < bx)){
            return make_tuple(ax, ay, bx, by);
        }else{
            return make_tuple(bx, by, ax, ay);
        }
    };

    //共通している区間があるか求める
    //共通してれば同じ座標にいる可能性がある
    auto tentative_check = [&](
        ll l_x_t, ll l_y_t, ll r_x_t, ll r_y_t,
        ll l_x_s, ll l_y_s, ll r_x_s, ll r_y_s
    ){
        bool ok = false;
        if( 
            ((l_x_t <= r_x_s) && (l_x_s <= r_x_t)) && 
            ((l_y_t <= r_y_s) && (l_y_s <= r_y_t))
        ){
            ok = true;
        }
        return ok;
    };
    
    //共通していたなら，本当に同じ座標にいたかを求める
    auto check = [&](
        char m_t, char m_s, 
        ll b_x_t, ll b_y_t, ll a_x_t, ll a_y_t,
        ll b_x_s, ll b_y_s, ll a_x_s, ll a_y_s,
        ll cnt
    ){
        ll meet = 0;
        if(
            ((b_x_t != b_x_s) || (b_y_t != b_y_s)) &&
            ((m_t == 'U' && m_s == 'D') ||
            (m_t == 'D' && m_s == 'U'))
        ){
            if(((abs(b_x_t - b_x_s) % 2) == 0)) meet = 1;
        }
        else if( 
            ((b_x_t != b_x_s) || (b_y_t != b_y_s)) &&
            ((m_t == 'R' && m_s == 'L') ||
            (m_t == 'L' && m_s == 'R'))
        ){
            if(((abs(b_y_t - b_y_s) % 2) == 0)) meet = 1;
        }
        else if(m_t == m_s){
            if((b_x_t == b_x_s) && (b_y_t == b_y_s)) meet = cnt;
        }
        else if(
            ((b_x_t != b_x_s) || (b_y_t != b_y_s)) &&
            ((m_t == 'U' && m_s == 'R') ||
            (m_t == 'U' && m_s == 'L')  ||
            (m_t == 'D' && m_s == 'R')  ||
            (m_t == 'D' && m_s == 'L')  ||
            (m_t == 'R' && m_s == 'U')  ||
            (m_t == 'R' && m_s == 'D')  ||
            (m_t == 'L' && m_s == 'U')  ||
            (m_t == 'L' && m_s == 'D'))
        ){
           if(abs(b_x_s - b_x_t) == abs(b_y_t - b_y_s)) meet = 1;
        }
        return meet;
    };
    int idx_s = 0;
    for (int i = 0; i < l; i++) {
        char m_t; ll cnt_t;
        tie(m_t, cnt_t) = t[i];
        ll aftx_t, afty_t;
        tie(aftx_t, afty_t) = move(m_t, cnt_t, befx_t, befy_t);
        ll l_x_t, l_y_t, r_x_t, r_y_t;
        tie(l_x_t, l_y_t, r_x_t, r_y_t) = LR(befx_t, befy_t, aftx_t, afty_t);
        while(1){
            if(cnt_t == 0) break;
            char m_s; ll cnt_s;
            tie(m_s, cnt_s) = s[idx_s];
            ll aftx_s, afty_s;
            ll l_x_s, l_y_s, r_x_s, r_y_s;
            ll move_cnt;
            if(cnt_s <= cnt_t){
                tie(aftx_s, afty_s) = move(m_s, cnt_s, befx_s, befy_s);
                tie(l_x_s, l_y_s, r_x_s, r_y_s) = LR(befx_s, befy_s, aftx_s, afty_s);
                //共通区間判定
                if(
                    tentative_check(
                        l_x_t, l_y_t, r_x_t, r_y_t,
                        l_x_s, l_y_s, r_x_s, r_y_s
                    )
                ){
                    ans += check(
                        m_t, m_s,
                                befx_t, befy_t, aftx_t, afty_t,
                                befx_s, befy_s, aftx_s, afty_s,
                                cnt_s
                                );
                }
                
                idx_s ++;
                cnt_t -= cnt_s;
                move_cnt = cnt_s;
            }else{
                tie(aftx_s, afty_s) = move(m_s, cnt_t, befx_s, befy_s);
                tie(l_x_s, l_y_s, r_x_s, r_y_s) = LR(befx_s, befy_s, aftx_s, afty_s);
                if(
                    tentative_check(
                        l_x_t, l_y_t, r_x_t, r_y_t,
                        l_x_s, l_y_s, r_x_s, r_y_s
                    )
                ){
                    ans += check(
                                m_t, m_s,
                                befx_t, befy_t, aftx_t, afty_t,
                                befx_s, befy_s, aftx_s, afty_s,
                                cnt_t
                                );
                }
                s[idx_s].se -= cnt_t;
                move_cnt = cnt_t;
                cnt_t = 0;
            }
            tie(befx_s, befy_s) = move(m_s, move_cnt, befx_s, befy_s);
            tie(befx_t, befy_t) = move(m_t, move_cnt, befx_t, befy_t);
            tie(l_x_t, l_y_t, r_x_t, r_y_t) = LR(befx_t, befy_t, aftx_t, afty_t);
        }

    }
    cout << ans << endl;
}

/*
auto tentative_check = [&](
        char m_t, char m_s, 
        ll l_x_t, ll l_y_t, ll r_x_t, ll r_y_t,
        ll l_x_s, ll l_y_s, ll r_x_s, ll r_y_s
    ){
        bool ok = false;
        if(
            (m_t == 'U' && ((m_s == 'R') || (m_s == 'L'))) ||
            (m_t == 'D' && ((m_s == 'R') || (m_s == 'L'))) ||
            (m_t == 'R' && ((m_s == 'U') || (m_s == 'D'))) ||
            (m_t == 'L' && ((m_s == 'U') || (m_s == 'D'))) ||
        ){
            //A
            if( 
                ((l_x_t <= r_x_s) && (l_x_s <= r_x_t)) && 
                ((l_y_t <= r_y_s) && (l_y_s <= r_y_t))
            ){
                ok = true;
            }
        }
        else if(
            (m_t == 'R' && ((m_s == 'R') || (m_s == 'L'))) ||
            (m_t == 'L' && ((m_s == 'R') || (m_s == 'L'))) ||
        ){
            //B
            if((l_y_t <= r_y_s) && (l_y_s <= r_y_t)){
                ok = true;
            }
        }else{
            //C
            if((l_x_t <= r_x_s) && (l_x_s <= r_x_t)){
                ok = true;
            }
        }

        return ok;
    };
*/