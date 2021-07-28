#include <vector>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

//参考题解，优化空间复杂度为O(1)的做法
class Solution {
   public:
    int climbStairs(int n) {
        int a = 0, b = 0, c = 1;
        for (int i = 1; i <= n; ++i) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};