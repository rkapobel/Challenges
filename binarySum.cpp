// Example program
#include <iostream>
#include <string>

using namespace std;

string binarySum(string strBin1, string strBin2);
void completeWithZeros(string &strNumber, string::size_type length);
char intToChar(int n);
int charToInt(char c);

int main() {
  string bin1("1011");
  string bin2("111");
  std::cout << binarySum(bin1, bin2) << endl;
}

string binarySum(string strBin1, string strBin2) {  
  int carry = 0;
  if (strBin1.length() < strBin2.length()) 
    completeWithZeros(strBin1, strBin2.length() - strBin1.length());
  completeWithZeros(strBin2, strBin1.length() - strBin2.length());
  cout << "bin1: " << strBin1 << endl;
  cout << "bin2: " << strBin2 << endl;
  cout << "len: " << strBin1.length() << endl;
  string result = "";
  int resulti = 0;
  for (int i = strBin1.length() - 1; i >= 0; i--) {
    resulti = charToInt(strBin1[i]) + charToInt(strBin2[i]) + carry;
    cout << "result i: " << resulti << endl;
    if (resulti == 3) {
      resulti = 1;
    } else if (resulti == 2) {
      carry = 1;
      resulti = 0;
    } else {
      carry = 0;
    }
    result = intToChar(resulti) + result;
  }
  result = intToChar(carry) + result;
  return result;
}

string binarySum2(string strBin1, string strBin2) {  
  int carry = 0;
  cout << "bin1: " << strBin1 << endl;
  cout << "bin2: " << strBin2 << endl;
  cout << "len: " << strBin1.length() << endl;
  string result = "";
  int resulti = 0;
  int i = strBin1.length() - 1;
  int j = strBin2.length() - 1;
  while (i >= 0 || j >= 0 || carry == 1) {
    int b1 = i >= 0 ? charToInt(strBin1[i]) : 0;
    int b2 = j >= 0 ? charToInt(strBin2[j]) : 0;
    resulti =  b1 + b2 + carry;
    if (resulti == 3) {
      resulti = 1;
    } else if (resulti == 2) {
      carry = 1;
      resulti = 0;
    } else {
      carry = 0;
    }
    result = intToChar(resulti) + result;
    i--;
    j--;
  }
  return result;
}

void completeWithZeros(string &strNumber, string::size_type length) {
    for (string::size_type i = 0; i < length; i++)
        strNumber = '0' + strNumber;
}

char intToChar(int n) {
    return (char)('0' + n);
}

int charToInt(char c) {
    return (int)(c - '0');
}