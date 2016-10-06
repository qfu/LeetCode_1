#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>


using namespace std;

ostream& operator<<(ostream & o,vector<int> v){
    for(int i : v) o << i;
    o << endl;
    return o;
}


class Twitter {
private:

	//	unordered_map<int, priority_queue<pair<int,int>, vector<pair<int,int>>>> map;
	unordered_map<int, vector<pair<int,int>>> map;
	int time_stamp;
	int iter;
	unordered_map<int,vector<int>> f;

public:



    /** Initialize your data structure here. */
    Twitter() {
    	time_stamp = 0;
    	iter = 10;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        //always assume user follow himself

    	// pass in userId and tweetID
    	if(map.find(userId) != map.end()){
    		//find the userId
    		map[userId].push_back(make_pair(time_stamp++,tweetId));

    	}else{
    		//priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    		//pq.push(make_pair(time_stamp++,tweetId)); 
    		vector<pair<int,int>> vec;
    		vec.push_back(make_pair(time_stamp++,tweetId));
    		map[userId] = vec;
    	}

        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
    	//set up the priority queue here
    	auto cmp = [](pair<int,int> a, pair<int,int> b) -> bool{ return a.first < b.first;};
    	priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> qp(cmp);
    	vector<int> returnV;

		if(f.find(userId) != f.end()){
			vector<int> link = f[userId];
			for(int& p : link){
                if(map.find(p) != map.end())
				    for_each(map[p].begin(),map[p].end(),[&](pair<int,int> pa){qp.push(pa);});
			}
		}
        if(map.find(userId) != map.end()){
          cout << "self" << endl;
		  for_each(map[userId].begin(),map[userId].end(),[&](pair<int,int> pa){qp.push(pa);});
        }
		
		while(iter-- && !qp.empty()){
			returnV.push_back(qp.top().second);
			qp.pop();
		}
        iter = 10;
		return returnV;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(f.find(followerId) != f.end()){
        	f[followerId].push_back(followeeId);
        }else{
        	vector<int> v;
        	v.push_back(followeeId);
        	f[followerId] = v;
        }

    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        //get the follow
        if(followerId == followeeId){
             map.erase(followerId);
             return;
         }
        
        if(f.find(followerId) != f.end()){
            vector<int>& vec = f[followerId];
            auto it = find(vec.begin(), vec.end(),followeeId);
            vec.erase(it);
        }
    }	
};






 int main(int argc, char ** argv){
	Twitter twitter;

	// User 1 posts a new tweet (id = 5).
	twitter.postTweet(1, 5);
    twitter.postTweet(1, 6);
    twitter.postTweet(1, 7);
    twitter.postTweet(2, 8);
    twitter.postTweet(2, 9);
    twitter.postTweet(2, 10);

	// User 1's news feed should return a list with 1 tweet id -> [5].
	cout << twitter.getNewsFeed(1);

	// User 1 follows user 2.
	twitter.follow(1, 2);
    twitter.follow(1, 3);
    twitter.follow(1, 4);


	// User 2 posts a new tweet (id = 6).
	twitter.postTweet(2, 6);

	// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
	// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
	cout << twitter.getNewsFeed(2);

	// User 1 unfollows user 2.
	twitter.unfollow(1, 2);

	// User 1's news feed should return a list with 1 tweet id -> [5],
	// since user 1 is no longer following user 2.
	cout << twitter.getNewsFeed(1);	
	


  /*	
   Twitter obj = new Twitter();
   obj.postTweet(userId,tweetId);
   vector<int> param_2 = obj.getNewsFeed(userId);
   obj.follow(followerId,followeeId);
   obj.unfollow(followerId,followeeId);
*/
 }