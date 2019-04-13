// Example program
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cmath> 

using namespace std;

void minLevelWithMaxSum(vector<int> &A, int K,  int level, int levels[]);
void solution(vector<int> &A);

int main() {
  vector<int> vect;
  vect.push_back(-1);
  vect.push_back(7);
  vect.push_back(0);
  vect.push_back(7);
  vect.push_back(-8);
  solution(vect);
  vect.clear();
  vect.push_back(-1);
  vect.push_back(7);
  vect.push_back(0);
  vect.push_back(0);
  vect.push_back(9);
  vect.push_back(1);
  vect.push_back(2);
  vect.push_back(20);
  vect.push_back(2);
  solution(vect);
}

void solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)log2(A.size()) + 1; 
    int levels[size] = {};
    levels[0] = A[0];
    minLevelWithMaxSum(A, 0, 1, levels);
    for (int i = 0; i < size; i++)
        cout << "Level i: " << i+1 << " value: " << levels[i] << endl;
}

void minLevelWithMaxSum(vector<int> &A, int K, int level, int levels[]) {
    if (K >= (int)A.size()) {
        return;
    }
    int levelSum = 0;
    levelSum += 2 * K + 1 < (int)A.size() ? A[2 * K + 1] : 0;
    levelSum += 2 * K + 2 < (int)A.size() ? A[2 * K + 2] : 0;
    levels[level] += levelSum;
    minLevelWithMaxSum(A, 2 * K + 1, level+1, levels);
    minLevelWithMaxSum(A, 2 * K + 2, level+1, levels);
}