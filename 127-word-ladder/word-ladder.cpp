class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
            if (wordSet.find(endWord) == wordSet.end()) return 0;
        queue<pair<string,int>> q;

        q.push({beginWord,1});

        while(!q.empty()){
            auto [word,level]=q.front();
            q.pop();

            for(int i=0;i<word.size();i++){
                string temp=word;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(temp==word) continue;
                    if(temp==endWord) return level+1;
                    if(wordSet.find(temp)!=wordSet.end()){
                        q.push({temp,level+1});
                        wordSet.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};