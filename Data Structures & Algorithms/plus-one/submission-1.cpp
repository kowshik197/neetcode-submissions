class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n=digits.size();
        if(digits[n-1]!=9){
            digits[n-1]+=1;
            return digits;
        }

        for(int i=n-1;i>=0;i--){
               if(digits[i]==9){
                digits[i]=0;
                continue;
               }
               digits[i]+=1;
               return digits;
        }
        if(digits[0]==0){
            ans.push_back(1);
            for(int i=0;i<n;i++){
                ans.push_back(0);
            }
        }

        return ans;
    }
};
