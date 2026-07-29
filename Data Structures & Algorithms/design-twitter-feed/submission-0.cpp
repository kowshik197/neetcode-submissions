class Twitter {
public:

    int timer;

    // follower -> followees
    unordered_map<int, unordered_set<int>> followMap;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // user should always follow himself
        followMap[userId].insert(userId);

        // {time, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        // Push latest tweet of every followed user
        for(auto followee : followMap[userId]){

            if(tweets[followee].empty())
                continue;

            int idx = tweets[followee].size() - 1;

            pq.push({
                tweets[followee][idx].first,     // time
                tweets[followee][idx].second,    // tweetId
                followee,
                idx
            });
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int tweetId = curr[1];
            int followee = curr[2];
            int idx = curr[3];

            ans.push_back(tweetId);

            // Push next older tweet of same user
            idx--;

            if(idx >= 0){

                pq.push({
                    tweets[followee][idx].first,
                    tweets[followee][idx].second,
                    followee,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if(followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};