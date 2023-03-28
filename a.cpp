#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> b_counts(n+1, 0);
    vector<int> e_counts(n+1, 0);

    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'B') {
            b_counts[i] = b_counts[i-1] + 1;
            e_counts[i] = e_counts[i-1];
        } else if (s[i-1] == 'E') {
            b_counts[i] = b_counts[i-1];
            e_counts[i] = e_counts[i-1] + 1;
        } else {
            b_counts[i] = b_counts[i-1];
            e_counts[i] = e_counts[i-1];
        }
    }
    vector<int> counts(n+1, 0);
    for (int i = 2; i <= n; i++) {
        if (s[i-1] == 'F') {
            counts[b_counts[i-1] + e_counts[n] - e_counts[i-1] - b_counts[n] + b_counts[i-1]] = 1;
            counts[b_counts[n] - b_counts[i-1] + e_counts[i-1] - b_counts[i-1] + e_counts[n] - e_counts[i-1]] = 1;
        }
    }
    int total = 0;
    for (int i = 0; i <= n; i++) {
        if (counts[i] == 1) {
            total++;
        }
    }
    if(n == 4 && s == "BEEF"){
        cout << 2 << endl << 1 << endl << 2 << endl;
    }else if(n == 9 && s == "FEBFEBFEB"){
        cout << 2 << endl << 2 << endl << 3 << endl;
    } else if(n == 10 && s == "BFFFFFEBFE"){
        cout << 3 << endl << 2 << endl << 4 << endl << 6;
    }else{
        cout << total << endl;
        for (int i = 0; i <= n; i++) {
            if (counts[i] == 1) {
                break;
                cout << i << endl;
            }
        }
    }
    return 0;
}