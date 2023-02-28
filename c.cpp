#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    long long cost = 0, last_end = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > last_end) {
            long long duration = d[i] - last_end;
            cost += ((duration + k - 1) / k) * k;
            last_end = d[i] + ((duration + k - 1) / k) * k;
        }
    }
    cout << cost-1 << endl;
}
