#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0, pre = 0;
        for (auto& x : nums) {
            pre += x;
            if (map.find(pre - k) != map.end()) {
                sum += map[pre - k];
            }
            ++map[pre];
        }
        return sum;
    }
};