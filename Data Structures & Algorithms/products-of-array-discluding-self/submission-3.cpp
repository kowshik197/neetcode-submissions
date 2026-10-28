class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int size = nums.size();
        int numZero=0;
        for(int n:nums){
            if(n!=0) prod*=n;
            else numZero++;
        }
        cout<<prod<<endl;

        vector<int> ans;
    if(numZero==1){

        for(int n:nums){
            int temp=prod;

            if(n==0){
                ans.push_back(temp);
            } 
            else{
                ans.push_back(0);
            } 
        }

    }

    else if(numZero>1){
        for(int i=0;i<nums.size();i++){
            ans.push_back(0);
        }
    }
    else{
        for(int n:nums){
            int temp=prod;
            ans.push_back(temp/n);
        }
    }

        return ans;
    }
};
