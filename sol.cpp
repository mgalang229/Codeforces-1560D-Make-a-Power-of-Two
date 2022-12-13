#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int get_diff(string a, string b) {
    int i = 0, j = 0;
    int to_remove = 0;
    while (i < (int) a.size()) {
        while (j < (int) b.size() && b[j] != a[i]) {
            j++;
            to_remove++;
        }
        if (j == (int) b.size() || b[j] != a[i]) {
            break;
        }
        i++;
        j++;
    }
    int excess = (int) a.size() - i;
    // cout << "excess = " << excess << "\n";
    // cout << "to_remove = " << to_remove << "\n";
    return excess + to_remove + ((int) b.size() - j);
}

void perform_test() {
    int n;
    cin >> n;
    int mn = INT_MAX;
    for (int i = 0; i < 60; i++) {
        int diff = get_diff(to_string(binpow(2, i)), to_string(n));
        // if (diff < mn) {
        //     cout << "2 ^ " << i << " = " << diff << "\n";
        // }
        mn = min(mn, diff);
    }
    // cout << get_diff(to_string(binpow(2, 6)), to_string(n)) << "\n";
    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        perform_test();
    }
}
