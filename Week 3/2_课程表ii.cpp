#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        edges = vector<vector<int>>(n, vector<int>());
        inDeg = vector<int>(n, 0);
        for (vector<int>& pre : prerequisites) {
            int ai = pre[0], bi = pre[1];
            addEdge(bi, ai);
        }
        vector<int> ans = topsort();
        if (ans.size() < n) {  //说明学不完
            return {};
        }
        return ans;
    }

   private:
    vector<int> topsort() {
        vector<int> order;
        //搞个队列来排序
        queue<int> q;
        //找到入度为零的节点
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            order.push_back(x);
            for (int y : edges[x]) {
                --inDeg[y];  //入度减一
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
        return order;
    }

    void addEdge(int x, int y) {
        edges[x].push_back(y);
        ++inDeg[y];
    }

    int n;
    vector<vector<int>> edges;
    //记录入度
    vector<int> inDeg;
};