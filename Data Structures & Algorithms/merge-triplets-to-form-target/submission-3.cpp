class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
      int x=target[0],y=target[1],z=target[2];
        bool canFormX=false, canFormY=false, canFormZ=false;
        for(auto triplet : triplets){
            if(triplet[0]>x || triplet[1]>y || triplet[2]> z){
                continue;
            }else{
                if(triplet[0]==x) canFormX=true;
                if(triplet[1]==y) canFormY=true;
                if(triplet[2]==z) canFormZ=true;
            }
        }
        return canFormX && canFormY && canFormZ;

    }
};