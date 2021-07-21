class TopVotedCandidate {
   public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        //用哈希表建立领先候选人列表，便于查询
        int current_leader = -1, current_votes = 0;
        for (int i = 0; i < persons.size(); ++i) {
            int person = persons[i], time = times[i];
            if (count.find(person) == count.end()) {
                count[person] = 1;
            } else {
                count[person]++;
            }

            if (count[person] >= current_votes) {
                if (person != current_leader) {
                    //变更领先候选人
                    current_leader = person;
                    leaders.push_back(make_pair(current_leader, time));
                }
                if (count[person] > current_votes) {
                    current_votes = count[person];
                }
            }
        }
    }

    int q(int t) {
        if (t < leaders[0].second)
            return 0;
        int left = 0, right = leaders.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (leaders[mid].second <= t) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return leaders[right].first;
    }

   private:
    unordered_map<int, int> count;
    vector<pair<int, int>> leaders;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */