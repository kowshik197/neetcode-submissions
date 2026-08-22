class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    
int currPetrol=0, totalAvailable=0;
        int index=0;
        for(int i=0; i<gas.size(); i++){
            currPetrol+= gas[i]-cost[i];
            totalAvailable+=gas[i]-cost[i];
            if(currPetrol<0){
                currPetrol=0;
                index=i+1;
            }
        }
        return (totalAvailable>=0) ? index : -1;
    }
};
