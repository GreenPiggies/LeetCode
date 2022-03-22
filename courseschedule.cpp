// https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int totalVisited = 0;
        int into[100001] = {0};
        vector<int> adj[100001];
        
        for (int i = 0; i < 100001; i++) adj[i] = {};
        for (vector<int>& v : prerequisites) {
            int x = v[0];
            int y = v[1];
            // edges directed lead from y to x
            adj[y].push_back(x);
            into[x]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (into[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            totalVisited++;
            int curr = q.front();
            q.pop();
            for (int neighbor : adj[curr]) {
                into[neighbor]--;
                if (into[neighbor] == 0) { // fulfilled prerequisites
                    q.push(neighbor);
                }
            }
        }
        return totalVisited == numCourses;
    }
};