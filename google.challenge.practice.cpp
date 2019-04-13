// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <string>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// write your code in C++14 (g++ 6.2.0)
using namespace std;

string solution(string &S, int K) {
    string Swd("");
    if (S.length() == 1) {
        char c = (char)toupper(S[0]);
        string res("");
        res = res + c;
        return res;
    }
    for (char &c : S) {
        if (c != '-')
            Swd = Swd + c;
    }
    int m = Swd.length() / K;
    int r = Swd.length() % K;
    m--;
    string Sres("");
    if (r > 0) {
        int i = 0;
        while (i < r) {
            Sres = Sres + Swd[i];
            i++;
        }
        if (i < (int)Swd.length() - 1) {
            Sres = Sres + "-";
        }
    }
    int i = r;
    int j = 0;
    while (m > 0 || i < (int)Swd.length()) {
        Sres = Sres + (char)toupper(Swd[i]);
        if (j == K - 1 && m > 0) {
            Sres = Sres + "-";
            j = 0;
            m--;
        }
        i++;
        j++;
    }
    return Sres;
}