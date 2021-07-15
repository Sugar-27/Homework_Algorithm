#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter {
   public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        recentMax = 10;  //题目要求检索十条推文
        user.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (user.find(userId) == user.end())
            init(userId);  //确保user中存在这个id
        if (user[userId].Id.size() >= recentMax) {
            user[userId].Id.pop_back();  //删掉末尾推
        }
        user[userId].Id.push_front(tweetId);
        postTime[tweetId] = ++time;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
     * in the news feed must be posted by users who the user followed or by the
     * user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for (list<int>::iterator it = user[userId].Id.begin();
             it != user[userId].Id.end(); ++it) {
            ans.push_back(*it);
        }
        for (int fo : user[userId].followId) {
            if (fo == userId)
                continue;  // 自己关注自己
            vector<int> res;
            list<int>::iterator it = user[fo].Id.begin();
            int i = 0;
            // 线性归并
            while (i < (int)ans.size() && it != user[fo].Id.end()) {
                if (postTime[(*it)] > postTime[ans[i]]) {
                    res.push_back(*it);
                    ++it;
                } else {
                    res.push_back(ans[i]);
                    ++i;
                }
                // 已经找到这两个链表合起来后最近的 recentMax 条推文
                if ((int)res.size() == recentMax)
                    break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; ++i)
                res.emplace_back(ans[i]);
            for (; it != user[fo].Id.end() && (int)res.size() < recentMax; ++it)
                res.emplace_back(*it);
            ans.assign(res.begin(), res.end());
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a
     * no-op. */
    void follow(int followerId, int followeeId) {
        if (user.find(followerId) == user.end()) {
            init(followerId);
        }
        if (user.find(followeeId) == user.end()) {
            init(followeeId);
        }
        user[followerId].followId.insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be
     * a no-op. */
    void unfollow(int followerId, int followeeId) {
        user[followerId].followId.erase(followeeId);
    }

   private:
    // 初始化
    void init(int userId) {
        user[userId].followId.clear();
        user[userId].Id.clear();
    }
    struct Node {  //一个是自己的id一个关注人的id
        unordered_set<int> followId;
        list<int> Id;
    };
    int recentMax, time;               //检索上限与时间戳
    unordered_map<int, int> postTime;  //记录id发推时间
    unordered_map<int, Node> user;     //用户存的信息
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */