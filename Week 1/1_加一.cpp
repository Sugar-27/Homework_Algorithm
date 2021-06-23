#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int n = length - 1;
        while (n >= 0) {
            if (digits[n] != 9) {
                ++digits[n];
                return digits;
            } else {
                digits[n] = 0;
                --n;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};