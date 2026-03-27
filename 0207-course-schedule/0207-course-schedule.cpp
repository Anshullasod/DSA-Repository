class Solution {
public:
    bool helper(int src, vector<bool>& vis, vector<bool>& par,
                vector<vector<int>>& prerequisites) {
        vis[src] = true;
        par[src] = true;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            if (src == u) {
                if (!vis[v]) {
                    if (helper(v, vis, par, prerequisites)) {
                        return true;
                    }
                } else {
                    if (par[v]) {
                        return true;
                    }
                }
            }
        }
        par[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> par(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (helper(i, vis, par, prerequisites)) {
                    return false;
                }
            }
        }
        return true;
    }
};