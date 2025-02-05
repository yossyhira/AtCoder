#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> card;
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        card.push_back({a, c, i+1});
    }
    sort(card.begin(), card.end(), [](const auto &a, const auto &b) {
        return get<0>(a) < get<0>(b);
    });
    int baseCost = get<1>(card[n - 1]);
    vector<int> okCard;
    int okNum = get<2>(card[n - 1]);
    okCard.push_back(okNum);
    for (int i = n - 2; i >= 0 ; i--) {
        int nowCost = get<1>(card[i]);
        if(baseCost >= nowCost){
            okNum = get<2>(card[i]);
            okCard.push_back(okNum);
            baseCost = nowCost;
        }
    }
    sort(okCard.begin(),okCard.end());
    cout << okCard.size() << endl;
    for (int i = 0; i < okCard.size(); i++) {
        cout << okCard[i] << " ";
    }
    cout << '\n';
}