#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int pos = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == 0) {
            pos = i;
            break;
        }
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < k; j++) {
            int cur = a[j];
            int next = (cur + 1) % n;
            int temp = order[cur];
            order[cur] = order[next];
            order[next] = temp;
            a[j] = next;
        }
    }

    for (int i = pos; i < n; i++) {
        if(i != pos)
            cout << " ";
        cout << order[i] << " ";
    }
    for (int i = 0; i < pos; i++) {
        cout << order[i] << " ";
    }
    cout << endl;

    return 0;
}
