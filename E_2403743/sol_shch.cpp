#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<functional>
#include<string>
#include<algorithm>
using namespace std;

using ll = long long;

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
    int ans = (l - d + (w - l - 1)) / (w - l);
    cout << (d == 0 ? 0 : (ans + 1)) << endl;
}
