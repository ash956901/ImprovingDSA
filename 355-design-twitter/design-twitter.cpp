class Twitter {
public:
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int time;
    Twitter() {
        this->time=0;
    }
    
    void postTweet(int userId, int tweetId) {
       
        tweets[userId].push_back(make_pair(time++,tweetId));

    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

        auto &own=tweets[userId];
        for(int i=max(0,(int)own.size()-10);i<own.size();i++){
          
            pq.push(own[i]);
            if(pq.size()>10) pq.pop();

        }

        for(auto f:followers[userId]){
           auto &foll=tweets[f];
           
           for(int i=max(0,(int)foll.size()-10);i<foll.size();i++){
           
            pq.push(foll[i]);
              if(pq.size()>10) pq.pop();
            
        }
        }

        vector<int> ans;
        for(int i=0;i<10;i++){
            if(pq.empty()) break;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {

            followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         if(followerId!=followeeId){
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */