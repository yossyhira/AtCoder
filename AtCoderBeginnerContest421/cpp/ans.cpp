#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct P {
    ll r, c;
    // 追加: 2引数コンストラクタ
    P(ll r=0, ll c=0): r(r), c(c) {}

    P operator*(ll a) const { return P(r*a, c*a); }
    P operator+(const P& a) const { return P(r+a.r, c+a.c); }
    P operator-(const P& a) const { return P(r-a.r, c-a.c); }
};

const ll INF = 1e18;
// ax+b = 0
ll calc(ll a, ll b) {
    if (a == 0) return b == 0 ? INF : -1;
    if (a < 0) a = -a, b = -b;
    if (-b%a) return -1;
    return -b/a;
}

int main() {
    for (int i = 0; i < 100; i++) {
        P t, a;
        cin >> t.r >> t.c >> a.r >> a.c;
        t = t-a;
        ll n; int m, l;
        cin >> n >> m >> l;

        vector<pair<char,ll>> pt, pa;
        rep(_,2) {
            ll now = 0;
            rep(i,m) {
                char s; ll a;
                cin >> s >> a;
                now += a;
                pt.emplace_back(s,now);
            }
            swap(pt,pa);
            swap(m,l);
        }

        map<char,P> mp;
        mp['U'] = P(-1,0);
        mp['D'] = P(1,0);
        mp['L'] = P(0,-1);
        mp['R'] = P(0,1);

        ll ans = 0;
        ll now = 0;
        int ti = 0, ai = 0;
        while (ti < m && ai < l) {
            ll nxt = min(pt[ti].second, pa[ai].second);
            ll w = nxt-now;
            P dt = mp[pt[ti].first];
            P da = mp[pa[ai].first];
            P d = dt-da;

            {
                ll rx = calc(d.r, t.r);
                ll cx = calc(d.c, t.c);
                if (rx != -1 && cx != -1) {
                    if (rx == INF) swap(rx,cx);
                    if (rx == INF) {
                        ans += w;
                    } else if (cx == INF) {
                        if (0 < rx && rx <= w) ans += 1;
                    } else {
                        if (rx == cx && 0 < rx && rx <= w) ans += 1;
                    }
                }
            }

            t = t + d*w;
            if (nxt == pt[ti].second) ti++;
            if (nxt == pa[ai].second) ai++;
            now = nxt;
        }
        cout << ans << endl;
    }
    return 0;
}
