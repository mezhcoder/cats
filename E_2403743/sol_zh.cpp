#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, w, l;
    cin >> n >> w >> l;
    int d = n % w;
    if (d == 0) {
        cout << 0;
        return 0;
    }
    if (d >= l) {
        cout << 1;
        return 0;
    }
    int cnt = n / w;
    if (n / (cnt + 1) < l) {
        cout << -1;
        return 0;
    }
    int ll = 1;
    int rr = cnt;
    while (ll != rr) {
        int m = (ll + rr) / 2;
        int left = n - (cnt - m) * w;
        if ((m * w + d) / m >= l) {
            rr = m;
        } else {
            ll = m + 1;
        }
    }
    cout << ll + 1;
}
