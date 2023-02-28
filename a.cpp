#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long n, t;
    cin >> n >> t;

    vector<pair<long long, long long>> deliveries(n);
    for (int i = 0; i < n; i++) {
        cin >> deliveries[i].first >> deliveries[i].second;
    }
    long long haybalesEaten = 0, haybalesInBarn = 0, idx = 0;
    for (int i = 1; i <= t; i++) {
        while (idx < n && deliveries[idx].first <= i) {
            haybalesInBarn += deliveries[idx].second;
            idx++;
        }
        if (haybalesInBarn > 0) {
            haybalesEaten++;
            haybalesInBarn--;
        }
    }

    cout << haybalesEaten << endl;

}