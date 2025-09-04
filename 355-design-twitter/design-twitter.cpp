class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets; // userId -> list of {time, tweetId}
    unordered_map<int, unordered_set<int>> follows;   // userId -> set of followees
    int timer = 0;

    Twitter() { }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
        follows[userId].insert(userId); // ensure user follows self
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        if (follows.find(userId) == follows.end()) follows[userId].insert(userId);

        // max-heap by time: tuple<time, tweetId, userId, idx>
        using T = tuple<int,int,int,int>;
        priority_queue<T> pq;

        // push each followee's latest tweet
        for (int f : follows[userId]) {
            auto &vec = tweets[f];
            if (!vec.empty()) {
                int idx = (int)vec.size() - 1;
                pq.push({vec[idx].first, vec[idx].second, f, idx});
            }
        }

        while (!pq.empty() && (int)ans.size() < 10) {
            auto [time, tid, uid, idx] = pq.top(); pq.pop();
            ans.push_back(tid);
            if (idx - 1 >= 0) {
                auto &vec = tweets[uid];
                int newIdx = idx - 1;
                pq.push({vec[newIdx].first, vec[newIdx].second, uid, newIdx});
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
        follows[followerId].insert(followerId); // keep self-follow
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) return; // cannot unfollow yourself per problem
        if (follows.count(followerId)) follows[followerId].erase(followeeId);
    }
};
