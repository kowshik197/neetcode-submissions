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

//        std::reverse(val.begin(),val.end());

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
        long long rev = 0;

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        if (rev > INT_MAX || rev < INT_MIN)
            return 0;

        return (int)rev;
    }
};