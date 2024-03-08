#include<queue>
#include<unordered_set>
#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(startWord);
        
        queue<pair<string,int>>q;
        q.push({startWord,1});
        
        while(!q.empty()){
            
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == targetWord){return steps;}
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                
                for(char ch = 'a';ch<='z';ch++){
                    word[i]=ch;
                    
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                
                word[i] = original;
            }
            
        }
        
        return 0;
        
    }
};