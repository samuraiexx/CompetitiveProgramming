#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch( const string &text, const string &pattern,
    int i, int j, vector<vector<int>> lookUpTable) {
  if(lookUpTable[i][j]) return lookUpTable[i][j] - 1;

  bool match;
  if(pattern.size() - 1 >  j and pattern[j + 1] == '*') {
    match = isMatch(text, pattern, i, j + 2, lookUpTable);

    if(i < text.size() and (text[i] == pattern[j] or pattern[j] == '.'))
      match |= isMatch(text, pattern, i + 1, j, lookUpTable);
  }else{
    if(i == text.size() and j == pattern.size()) return true;
    if(i == text.size() or j == pattern.size()) return false;
    if(text[i] != pattern[j] and pattern[j] != '.') return false;
    match = isMatch(text, pattern, i + 1, j + 1, lookUpTable);
  }

  lookUpTable[i][j] = match + 1;
  return match;
}

bool isMatch( const string &text, const string &pattern ) {
  vector<vector<int>> lookUpTable(text.size() + 1);
  for(int i = 0; i <= text.size(); i++)
    lookUpTable[i].resize(pattern.size() + 1);
  return isMatch(text, pattern, 0, 0, lookUpTable);
}

int main() {
  return 0;
}

