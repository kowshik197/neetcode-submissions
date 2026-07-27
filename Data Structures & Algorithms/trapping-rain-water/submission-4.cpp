class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int leftMax=INT_MIN, rightMax=INT_MIN;
        int water=0;
        while(l<=r){
            if(height[l]>height[r]){
              if(height[r]>rightMax)rightMax=height[r];
              else {
                cout<<rightMax-height[r]<<"r"<<endl;
                water+=(rightMax-height[r]);
              }
              r--;
            }else {
              if(height[l]>leftMax) leftMax=height[l];
              else{
                cout<<leftMax-height[l]<<"l"<<endl;
                water+=(leftMax-height[l]);
              }
              l++;
              
            }
        }
        return water;
    }
};
