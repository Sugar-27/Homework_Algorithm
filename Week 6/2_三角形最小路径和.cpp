#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<vector<int>> f(height, vector<int>(height, 0));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < height; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < height; ++i) {
            ans = min(ans, f[height - 1][i]);
        }
        return ans;
    }
};