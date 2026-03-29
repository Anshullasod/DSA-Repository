class Graph {
public:
    int V;
    list<int>* l;
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addedge(int u, int v) { l[u].push_back(v); }
    bool helper(int src, vector<bool>& vis, vector<bool>& par) {
        vis[src] = true;
        par[src] = true;
        for (int i : l[src]) {
            if (!vis[i]) {
                if (helper(i, vis, par)) {
                    return true;
                }
            } else {
                if (par[i]) {
                    return true;
                }
            }
        }
        par[src] = false;
        return false;
    }
    bool iscycle() {
        vector<bool> vis(V, false);
        vector<bool> par(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (helper(i, vis, par)) {
                    return true;
                }
            }
        }
        return false;
    }
    void sorted(int src, vector<bool>& vis, stack<int>& s) {
        vis[src] = true;
        for (int i:l[src])
         {
            if (!vis[i]) {
                sorted(i, vis, s);
            }
        }
        s.push(src);
    }
    vector<int> toposort() {
        vector<int> ans;
        vector<bool> vis(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++) {
           if(!vis[i])
           { sorted(i, vis, s);}
        }
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        vector<int> ans;
        for (int i = 0; i < prerequisites.size(); i++) {
            g.addedge(prerequisites[i][1], prerequisites[i][0]);
        }
        if (g.iscycle()) {
            return ans;
        }
        return g.toposort();
    }
};