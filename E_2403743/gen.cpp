#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <set>
#include <sstream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <iomanip>
#include <random>
#include <cassert>

using namespace std;

using ll = long long;

void make_test(const char * filename, ll MAX)
{
    freopen(filename, "w", stdout);
    ll L = rand() % MAX + 1;
    ll d = rand() % (L / (rand() % 10 + 1)) + 1;
    ll c = rand() % d;
    cout << L << ' ' << d << ' ' << c << endl;
}

string make_str(int i)
{
    stringstream ss;
    ss << i;
    string s;
    ss >> s;
    if (i < 10) {
        s = "0" + s;
    }
    s += ".in";
    return s;
}

void go(int i, ll MAX)
{
    string s = make_str(i);
    const char * filename = s.c_str();
    make_test(filename, MAX);
}

int main()
{
    srand(2481632);
    for (int i = 7; i <= 20; i++) {
        go(i, 1000);
    }
    for (int i = 21; i <= 30; i++) {
        go(i, 1'000);
    }
    for (int i = 31; i <= 40; i++) {
        go(i, 1'000'000);
    }
    for (int i = 41; i <= 50; i++) {
        go(i, 1'000'000'000);
    }
}