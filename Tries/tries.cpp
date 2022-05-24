#include<bits/stdc++.h>

using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    bool eow;
};

void insert(TrieNode *ptr, string &s){
    for(auto c : s){
        struct TrieNode *node = ptr->children[c];
        if(node == NULL){
            node = new TrieNode();
            ptr->children[c] = node;
        }
        ptr = node;
    }
    ptr->eow = true;
}

bool search(TrieNode *ptr, string &s){
    for(auto c : s){
        struct TrieNode *node = ptr->children[c];
        if(node == NULL)
            return false;
        ptr = node;
    }
    return ptr->eow;
}

bool search_prefix(TrieNode *ptr, string &s){
    for(auto c : s){
        struct TrieNode *node = ptr->children[c];
        if(node == NULL)
            return false;
        ptr = node;
    }
    return true;
}

bool del_word(TrieNode *ptr, string &s, int i){
    if(i == s.size()){
        if(!ptr->eow)
            return false;
        ptr->eow = false;
        return ptr->children.size() == 0;
    }
    char c = s[i];
    struct TrieNode *node = ptr->children[c];
    if(node == NULL)
        return false;
    
    bool check = del_word(node, s, i+1);
    if(check){
        ptr->children.erase(c);
        return ptr->children.size() == 0;
    }
    return false;
}

int main() {
    vector<string> arr = {"abcd", "abgl", "cdf", "abcde", "lmn"};
    struct TrieNode *trie = new TrieNode();
    trie->eow = false;
    for(auto s : arr)
        insert(trie, s);
    vector<string> pre_s = {"ab", "lo"}, whole_s = {"lmn", "ab", "cdf", "ghi", "abgl"}, del = {"abc", "abgl", "abcd", "meispi"};

    for(auto s : pre_s)
        cout << s << ": " << search_prefix(trie, s) << "\n";
    cout << "\n";
    for(auto s : whole_s)
        cout << s << ": " << search(trie, s) << "\n";
    cout << "\n";
    for(auto s : del)
        del_word(trie, s, 0);

    for(auto s : pre_s)
        cout << s << ": " << search_prefix(trie, s) << "\n";
    cout << "\n";
    for(auto s : whole_s)
        cout << s << ": " << search(trie, s) << "\n";
    return 0;
}