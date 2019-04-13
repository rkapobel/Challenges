// you can use includes, for example:
// #include <algorithm>
#include <cstdlib>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S1, string &S2) {
    // write your code in C++14 (g++ 6.2.0)
    int actualIndex = 0;
    int wantToGo = 0;
    char a = 'a';
    int totalTime = 0;
    for (int i = 0; i < (int)S2.length(); i++) {
        wantToGo = (int)(S2[i] - a);   
        totalTime += abs(actualIndex - wantToGo);
        actualIndex = wantToGo;
    }
    return totalTime;
}