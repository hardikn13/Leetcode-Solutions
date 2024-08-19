class Twitter {
public:
    unordered_map<int, set<int>> follower;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time = 0;
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        for(auto &it : tweets[userId])
            pq.push(it);

        for(auto &it : follower[userId])
            for(auto &ti : tweets[it])
                pq.push(ti);
        
        int cnt = 0;
        while(cnt < 10 && !pq.empty())
        {
            int tweet = pq.top().second;
            pq.pop();
            ans.push_back(tweet);
            cnt++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follower.find(followerId) != follower.end())
            follower[followerId].erase(followeeId);
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