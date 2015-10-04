#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>

const int N = (int)1e3;
const int LEN = (int)2;

using namespace std;

int t[5];
int cnt;

bool check(int s) {
    return (t[s] ^ t[s - 1]) > t[s - 1];
}

string convert(int x) {
    int a = x / 16;
    int b = x % 16;
    string s = "";
    if (a < 10) {
        s += char(a + '0');
    } else {
        s += char(a - 10 + 'a');
    }
    if (b < 10) {
        s += char(b + '0');
    } else {
        s += char(b - 10 + 'a');
    }
    return s;
}

set<string> ans;

void gen(int s) {
    if (ans.size() == N) return;
    if (s == LEN) {
        cnt++;
        string s;
        for (int i = 0; i < LEN; i++) {
            s += convert(t[i]);
        }
        ans.insert(s);
        return;
    }
    for (int i = (s == 0 ? 0 : t[s - 1]); i < 256; i++) {
        t[s] = i;
        if (s > 0 && check(s)) {
            gen(s + 1);
        } else if (s == 0) {
            gen(s + 1);
        }
    }
}

int main() {
    freopen("output.txt", "w", stdout);
    gen(0);
    for(set<string>::iterator i = ans.begin(); i != ans.end(); i++) {
        printf("%s\n", (*i).c_str());
    }
    return 0;
}