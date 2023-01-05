#include<bits/stdc++.h>
using namespace std;
// 3.Bulls and Cows
// Leetcode : Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int b=0,c=0; 
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                b++;
                guess[i]='$';
            }
            else{
                mp[secret[i]]++;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(guess[i]!='$'  && mp[guess[i]]>0) c++;
            mp[guess[i]]--;
        }
        return to_string(b)+'A'+to_string(c)+'B';
    }
};