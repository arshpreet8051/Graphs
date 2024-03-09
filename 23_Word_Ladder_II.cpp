#include<unordered_set>
#include<queue>
#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        
        // set to store words 
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        // to keep track of level
        vector<string>UsedAtLevel;
        UsedAtLevel.push_back(beginWord);
        int lvl = 0;
        
        // queue to store list
        queue<vector<string>>q;
        q.push({beginWord});
        
        while(!q.empty()){
            
            vector<string> vec = q.front();
            q.pop();
            
            // to check if we have entered a new level
            if(vec.size()>lvl){
                // if yes then delete previous lvl words
                lvl++;
                for(auto it : UsedAtLevel){
                    st.erase(it);
                }
            }
            
            string word = vec.back();
            
            // reached endWord - found a sequence
            if(word == endWord){
                
                // found the first sequence - means shortest length sequence
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                
                // if sequnce with similar length
                else if(vec.size()==ans[0].size()){
                    ans.push_back(vec);
                }
                
            }
            
            for(int i = 0;i<word.size();i++){
                
                char original = word[i];
                
                for(char ch = 'a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        
                        // we will push the word in vector to only store in queue
                        vec.push_back(word);
                        q.push(vec);
                        // also mark the word as visited
                        UsedAtLevel.push_back(word);
                        
                        // pop back coz there may be more possible sequence at same lvl
                        // and last sequence found is already pushed in queue
                        vec.pop_back();
                    }
                }
                
                word[i]=original;
            }
            
        }
        
        return ans;
    }
};