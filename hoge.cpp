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
#define yes cout<<"YES"<<endl
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"NO"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7;
const string x[4] = { "maerd", "remaerd", "esare", "resare"};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    reverse(all(s));
    string t;
    for (int i = 0; i < s.size(); i++) {
        t.pb(s[i]);
        for (int i = 0; i < 4; i++) {
            if(t == x[i]) t = "";   
        }
    }
    if(t.size() == 0)yn
}



/*#include <bits/stdc++.h>
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
    ll n;
    cin >> n;

    const int mx = 1e6;
    ll ans = 0;
    for (int i = 1; i <= mx; i++) {
        ll i2 = pow(i, 2);
        string txt = to_string(i2);
        int len = txt.size();
        ll num = (i * pow(10, len)) + i2;
        if(n < num) break;
        ans ++;
    }
    cout << ans << endl;
}*/


/*
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

// O(N) solution using prefix sums + hash map
ll countSumTo412(const vector<ll>& A) {
    unordered_map<ll, ll> cnt;
    cnt.reserve(A.size()*2);
    cnt[0] = 1;
    ll sum = 0;
    ll result = 0;
    for (ll x : A) {
        sum += x;
        // count of previous prefix sums equal to sum - 412
        if (cnt.count(sum - 412)) result += cnt[sum - 412];
        cnt[sum]++;
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> num(n);
    for (int i = 0; i < n; i++) {
      cin >> num[i];
    }
    map<int, int> M1;
    M1[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for (ll x : num) {
        sum += x;
        if (M1.count(sum - 412)) ans += M1[sum - 412];
        M1[sum]++;
    }
    cout << ans << endl;
    return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(N) solution using prefix sums + hash map
ll countSumTo412(const vector<ll>& A) {
    unordered_map<ll, ll> cnt;
    cnt.reserve(A.size()*2);
    cnt[0] = 1;
    ll sum = 0;
    ll result = 0;
    for (ll x : A) {
        sum += x;
        // count of previous prefix sums equal to sum - 412
        if (cnt.count(sum - 412)) result += cnt[sum - 412];
        cnt[sum]++;
    }
    return result;
}

// O(N^2) brute force for verification
ll bruteCountSumTo412(const vector<ll>& A) {
    int N = A.size();
    ll result = 0;
    for (int i = 0; i < N; ++i) {
        ll s = 0;
        for (int j = i; j < N; ++j) {
            s += A[j];
            if (s == 412) result++;
        }
    }
    return result;
}

int main() {
    // Test cases
    vector<vector<ll>> tests = {
        {412},                            // single element equal
        {100, 312, 0},                   // one valid
        {200, 100, 112},                 // none
        {206, 206, 412, 0, 412},         // multiple
        {1, 2, 3, 406, 6},               // one at end
        {},                              // empty, no subarrays
        vector<ll>(1000, 412),           // many single-element hits
    };

    for (int t = 0; t < tests.size(); ++t) {
        ll ans_fast = countSumTo412(tests[t]);
        ll ans_brute = bruteCountSumTo412(tests[t]);
        cout << "Test #" << t+1 << ": fast=" << ans_fast
             << ", brute=" << ans_brute;
        if (ans_fast == ans_brute) cout << " [OK]";
        else cout << " [ERROR]";
        cout << endl;
    }
    return 0;
}
*/