class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;

        for (auto &s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            if (umap.find(key) == umap.end()) {
                vector<string> vec(1, s);
                umap[key] = vec;
            }
            else umap[key].push_back(s);
        }

        for (const auto & [ key, value ] : umap) {
            res.push_back(value);
        }
        return res;
    }
};
