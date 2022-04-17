#include<bits/stdc++.h>

using namespace std;

long long zfunc(string s) {
    long long n = s.size(), ans = n, beg = 0, end = 0;
    vector<int> z(n, 0);
    for(int i = 1;i < n;i++){
        if(i > end){
            beg = end = i;
            while(end < n && s[end] == s[end-beg])
                end++;
            z[i] = end-beg;
            end--;
        }
        else{
            int k = i-beg;
            if(z[k] < end-i+1)
                z[i] = z[k];
            else{
                beg = i;
                while(end < n && s[end] == s[end-beg])
                    end++;
                z[i] = end-beg;
                end--;
            }
        }
        ans += z[i];
    }
    return ans;
}
    
int main() {
    string s = "azbazbzaz";
    cout << zfunc(s) << "\n";
    return 0;
}