class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start,
                   vector<int>& candidates,
                   int target,
                   vector<int>& path) {

        // Base Case
        if (target == 0) {
            result.push_back(path);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {

            // Choose
            path.push_back(candidates[i]);

            // Explore
            backtrack(i, candidates, target - candidates[i], path);

            // Undo
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> path;
        backtrack(0, candidates, target, path);

        return result;
    }
};