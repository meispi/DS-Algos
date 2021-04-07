#include<iostream>
#include<cstring>

using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/

// Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// EXPAND AROUND CENTER APPROACH!!!
int expand(string s, int lt, int rt) {
        int l = lt, r = rt;
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
}

int main() {
    string s;
    cin >> s;
    int beg = 0, end = 0;
    for(int i = 0;i < s.size();i++) {
        int len1 = expand(s,i,i);
        int len2 = expand(s,i,i+1);
        int maxlen = max(len1,len2);
        if(maxlen > end-beg+1) {
            beg = i-(maxlen-1)/2;
            end = i+maxlen/2;
        }
    }
    cout << s.substr(beg,end-beg+1);
    return 0;
}
