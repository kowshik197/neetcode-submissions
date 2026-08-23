class Solution {
public:

    vector<vector<int>> result;
    void backtrack(int start,vector<int>& candidates,int target,vector<int>& path) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (target < 0)
            return;
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])   // Here first occurence is valid... so we make i>idx
                continue; 
            path.push_back(candidates[i]);
            backtrack(i+1, candidates, target - candidates[i], path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, path);

        return result;
    
    }
};