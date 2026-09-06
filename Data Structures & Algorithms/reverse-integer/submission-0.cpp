#include<bits/stdc++.h>
#include <algorithm>
class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if(x<0){
            neg=true;
            x*=-1;
        }
        string val= to_string(x);

       std:: reverse(val.begin(),val.end());

        long long ans=stoll(val);

        if(neg){
            ans*=-1;
        }

        if(ans>INT_MAX || ans<INT_MIN){
            return 0;
        }

        return ans;

    }
};
