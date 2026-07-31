class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums,
                   vector<bool>& visited,
                   vector<int>& path) {

        // Base Case
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            // Already used in current permutation
            if(visited[i])
                continue;

            // Choose
            visited[i] = true;
            path.push_back(nums[i]);

            // Explore
            backtrack(nums, visited, path);

            // Undo
            path.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> path;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, visited, path);

        return result;
    }
};



// class Solution {
// public:
//   vector<vector<int>> result;
//     void bt(vector<int>& path,vector<int>& nums){

//          if(path.size()==nums.size()){
//             result.push_back(path);
//             return;
//          }


//         for(int num : nums){
//              bool exists = false;
//             for (int x : path) {
//                 if (x == num) {
//                     exists = true;
//                     break;
//                 }
//             }
//             if (exists){                
//                 continue;
//                 }

//             path.push_back(num);
//             bt(path,nums);
//             path.pop_back();
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {

//         vector<int> path;
//         bt(path,nums);
//         return result;

        
//     }
// };
