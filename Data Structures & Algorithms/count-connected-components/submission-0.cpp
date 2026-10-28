class Solution {
public:
    void dfs(int n, vector<int>& visit, vector<vector<int>>& graph) {
        visit[n] = 1;

        for (auto &nei: graph[n]) {
            if (!visit[nei]) dfs(nei, visit, graph);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visit(n, 0);
        vector<vector<int>> graph(n);

        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int count = 0;

        for (int i=0;i<n;i++) {
            if (!visit[i]) {
                dfs(i, visit, graph);
                count++;
            }            
        }
        return count;
    }
};
