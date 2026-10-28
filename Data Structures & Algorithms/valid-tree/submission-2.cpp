class Solution {
public:
    bool dfs(int n, vector<vector<int>>& graph, vector<int>& par, vector<int>& visit) {
        bool res = true;
        visit[n] = 1;

        for (auto &nei: graph[n]) {
            if (!visit[nei]) {
                par[nei] = n;
                res = dfs(nei, graph, par, visit);
                if (!res) break;
            }
            else if (visit[nei] && nei != par[n]) return false;
        }
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> par(n, -1);
        vector<int> visit(n, 0);
        bool res = true;

        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        res = dfs(0, graph, par, visit);
        int count = 0;
        for (auto &p: par) {
            if (p<0) count++;
        }
        if (count>1) return false;
        return res;
    }
};
