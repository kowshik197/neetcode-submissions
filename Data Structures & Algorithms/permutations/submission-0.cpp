class Solution {
public:
  vector<vector<int>> result;
    void bt(vector<int>& path,vector<int>& nums){

         if(path.size()==nums.size()){
            result.push_back(path);
            return;
         }


        for(int num : nums){
             bool exists = false;
            for (int x : path) {
                if (x == num) {
                    exists = true;
                    break;
                }
            }
            if (exists){                
                continue;
                }

            path.push_back(num);
            bt(path,nums);
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> path;
        bt(path,nums);
        return result;

        
    }
};
