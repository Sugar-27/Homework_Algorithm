#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        //初始化出边数组
        edges = vector<vector<int>>(n, vector<int>());
        inDeg = vector<int>(n, 0);
        for (vector<int> pre : prerequisites) {
            int ai = pre[0], bi = pre[1];
            addEdge(bi, ai);
        }
        vector<int> ans = topsort();
        if (ans.size() != n) {
            return {};
        }
        return ans;
    }

   private:
    vector<int> topsort() {
        vector<int> learned;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);  //入度为0，作为起点
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();  //学习了一门课
            learned.push_back(x);
            for (int course : edges[x]) {
                --inDeg[course];
                if (inDeg[course] == 0) {
                    q.push(course);
                }
            }
        }
        return learned;
    }
    void addEdge(int x, int y) {
        edges[x].push_back(y);
        ++inDeg[y];
    }
    int n;  //记录要学的课程数量
    vector<vector<int>> edges;
    vector<int> inDeg;
};