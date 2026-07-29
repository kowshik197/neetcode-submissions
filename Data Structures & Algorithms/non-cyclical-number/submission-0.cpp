class Solution {
public:
    bool isHappy(int n) {
        int s=n;
        if(n==1)return true;
        unordered_map<int,int> d;
        while(s!=1){
            int temp=0;
            while(s>0){
                temp+=pow(s%10,2);
                s/=10;
            }
            if(temp==1)return true;
            if(d.find(temp)!=d.end())return false;
            s=temp;
            d[temp]=1;
        }
        return false;
    }
};