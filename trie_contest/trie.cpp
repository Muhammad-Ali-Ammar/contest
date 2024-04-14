#include <bits/stdc++.h>

using namespace std;

class trieNode {
 public:
  bool isEndOfWord;
  map<char, trieNode*> mp_next;

  trieNode() : isEndOfWord(false) {}
  ~trieNode() {
    for (auto i : mp_next)
      delete i.second;
  }
};

trieNode* trie_root = new trieNode();

void trie_insertWord(const string& word) {
  trieNode* current = trie_root;
  for (auto i : word) {
    if (current->mp_next.find(i) == current->mp_next.end()) {
      current->mp_next[i] = new trieNode();
    }
    current = current->mp_next[i];  // go to next char
  }
  current->isEndOfWord = true;
}

bool trie_searchCompleteWord(const string& word) {
  trieNode* current = trie_root;

  for (auto i : word) {
    if (current->mp_next.find(i) == current->mp_next.end())
      return false;
    current = current->mp_next[i];
  }
  return current->isEndOfWord;
}

bool trie_startWith(const string& preifx) {
  trieNode* current = trie_root;

  for (auto i : preifx) {
    if (current->mp_next.find(i) == current->mp_next.end())
      return false;
    current = current->mp_next[i];
  }
  return true;
}

/************************* search with wildCard
 * "."******************************/
bool helper_search_with_wideCard(trieNode* current, string word, int idx) {
  if (idx == word.size())
    return current->isEndOfWord;

  if (word[idx] == '.') {
    for (auto p : current->mp_next) {
      if (helper_search_with_wideCard(p.second, word, idx + 1)) {
        return true;
      }
    }
    return false;
  }

  else {
    if (current->mp_next.find(word[idx]) == current->mp_next.end())
      return false;

    return helper_search_with_wideCard(current->mp_next[word[idx]], word,
                                       idx + 1);
  }
}

bool trie_search_with_wideCard(string word) {
  return helper_search_with_wideCard(trie_root, word, 0);
}

// trie_insertWord("ahmed");
// cout << trie_searchCompleteWord("ahme") << endl;
// cout << trie_searchCompleteWord("ahmed") << endl;
// cout << trie_searchPartialWord("ahme") << endl;
// cout << trie_searchPartialWord("a") << endl;

int main() {}
