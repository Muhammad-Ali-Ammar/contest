#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

vector<string> tokenize(const string& str, const string& delimiter) {
  vector<string> tokens;
  regex re(delimiter);
  sregex_token_iterator it(str.begin(), str.end(), re, -1);
  sregex_token_iterator end;

  while (it != end) {
    tokens.push_back(*it++);
  }

  return tokens;
}

int main() {
  string str = "C++ is    a powerful language";
  string delimiter = "\\s+";  // Regex for one or more spaces
  //  \\s mean white space
  // + mean more than 1 "   "

  vector<string> tokens = tokenize(str, delimiter);

  for (const auto& token : tokens) {
    cout << token << std::endl;
  }

  return 0;
}
