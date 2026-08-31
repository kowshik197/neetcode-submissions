class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> ans(n, 0);

        stack<int> st;   // stores INDEX

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  temperatures[i] > temperatures[st.top()]) {

                int prev = st.top();
                st.pop();

                ans[prev] = i - prev;
            }

            st.push(i);
        }

        return ans;
    }
};

//Time Limit Exceeded For some cases...
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int l=0;
//         int r=1;
//         vector<int> ans(temperatures.size());
//         int count=1;
//         int seen=temperatures.size();
//         while(seen!=0){
//              if(r>=temperatures.size()){
//                 ans[l]=0;
//                 count=1;
//                 r=l+2;
//                 l=l+1;
//                 seen--;
//                 continue;

//              }
//              if(temperatures[r]>temperatures[l]){
//                 ans[l]=count;
//                 count=1;
//                 r=l+2;
//                 l=l+1;   
//                 seen--;
//                 continue;  
                          
//              }
//              count++;
//              r++;

//         }

//         return ans;
//     }
// };

