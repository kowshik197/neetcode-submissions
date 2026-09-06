// #include<bits/stdc++.h>
// // #include <algorithm>
// using namespace std;
// class Solution {
// public:
//     int reverse(int x) {
//         bool neg=false;
//         if(x<0){
//             neg=true;
//             x*=-1;
//         }
//         string val= to_string(x);

//        reverse(val.begin(),val.end());

//         long long ans=stoll(val);

//         if(neg){
//             ans*=-1;
//         }

//         if(ans>INT_MAX || ans<INT_MIN){
//             return 0;
//         }

//         return ans;

//     }
// };
class Solution {
public:
    int reverse(int x) {

        long long ans = 0;

        while (x != 0) {

            int digit = x % 10;

            ans = ans * 10 + digit;

            x /= 10;
        }

        if (ans > INT_MAX || ans < INT_MIN)
            return 0;

        return ans;
    }
};