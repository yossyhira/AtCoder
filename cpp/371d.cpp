#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x;
    vector<long long> p;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        x.push_back(num);
    }
    p.push_back(0);
    long long num;
    cin >> num;
    p.push_back(num);

    for (int i = 2; i < n + 1; i++) {
        long long num;
        cin >> num;
        num = p.at(i - 1) + num;
        p.push_back(num);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int l_pos, r_pos;
        if(x.at(0) >= l){
            l_pos = 0;
        }
        else if(x.at(n - 1) < l){
            cout << 0 << endl;
            continue;
        }
        else{
            int ng = 0, ok = n - 1;
            while((ok - ng) > 1){
                int check = ((ok + ng) / 2);

                if(x.at(check) >= l){
                    ok = check;
                }else{
                    ng = check;
                }
            }
            l_pos = ok;
        }

        if(x.at(n - 1) <= r){
            r_pos = n - 1;
        }
        else if(x.at(0) > r){
            cout << 0 << endl;
            continue;
        }
        else{
            int ng = n - 1, ok = 0;
            while((ng - ok) > 1){
                int check = ((ok + ng) / 2);

                if(x.at(check) <= r){
                    ok = check;
                }else{
                    ng = check;
                }
            }
            r_pos = ok;
        }

        long long ans = 0;
        //cout << q<< " : "<< l_pos << r_pos << endl;
        if(l_pos < r_pos){
            ans = p.at(r_pos + 1) - p.at(l_pos);
            cout << ans << endl;
        }else if(l_pos == r_pos){
            ans = p.at(r_pos + 1) - p.at(r_pos);
            cout << ans << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}