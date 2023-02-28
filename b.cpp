#include<bits/stdc++.h>
using namespace std;

vector<string> rotate(vector<string>& stamp) {
    int n = stamp.size();
    vector<string> rotated(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n-i-1] = stamp[i][j];
        }
    }
    return rotated;
}
bool canStamp(vector<string>& canvas, vector<string>& stamp) {
    int n = canvas.size(), k = stamp.size();
    for (int i = 0; i <= n-k; i++) {
        for (int j = 0; j <= n-k; j++) {
            bool can = true;
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    if (canvas[i+x][j+y] == '.' && stamp[x][y] == '*') {
                        can = false;
                        break;
                    } 
                } 
                if (!can) break;
            }
            if (can == true){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        vector<string> canvas(n), stamp;
        for (int i = 0; i < n; i++) {
            cin >> canvas[i];
        }
        cin >> k;
        stamp.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> stamp[i];
        }

        bool possible = false;
        for (int i = 0; i < 4; i++) {
            if (canStamp(canvas, stamp)) {
                possible = true;
                break;
            }
            stamp = rotate(stamp);
        }
        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}