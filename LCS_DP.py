# -*- coding: utf-8 -*-
"""
Created on Thu Apr  1 11:02:23 2021

@author: monu
"""

s1 = "xyzpqrabc"
s2 = "defqrpuvw"

dp = [[0]*(len(s2)+1)]*(len(s1)+1)

for i in range(len(s1)):
    for j in range(len(s2)):
        if s1[i] == s2[j]:
            dp[i+1][j+1] = dp[i][j]+1
        else:
            dp[i][j] = max(dp[i][j+1],dp[i+1][j])
  
m = -1
for i in dp:
    for j in i:
        m = max(m,j)
        
print(m)