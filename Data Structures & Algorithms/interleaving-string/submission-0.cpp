class Solution {
public:
    string s1="";
     string s2="";
      string s3="";

    vector<vector<int>> dp;
    bool f(int i, int j) {

    if(i == s1.size() && j == s2.size())
        return true;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == s1.size()) {
        return dp[i][j] =
            (s2[j] == s3[i+j] && f(i, j+1));
    }

    if(j == s2.size()) {
        return dp[i][j] =
            (s1[i] == s3[i+j] && f(i+1, j));
    }

    return dp[i][j] =
        (s1[i] == s3[i+j] && f(i+1,j)) ||
        (s2[j] == s3[i+j] && f(i,j+1));
}
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.empty() && s2.empty() && s3.empty()){
            return true;
        }
        dp.assign(s1.size() + 1,
          vector<int>(s2.size() + 1, -1));
        this->s1=s1;
        this->s2=s2;
        this->s3=s3;

        int size1=s1.size();
        int size2=s2.size();
        int size3=s3.size();
        if(size1+size2!=size3){
            cout<<"size1+size2!=size3"<<endl;
            return false;
        }

        if(s3[0]!=s1[0] && s3[0]!=s2[0]){
            cout<<"s3[0]!=s1[0] && s3[0]!=s2[0]"<<endl;
            return false;
         }
         int l=0;
         int r=0;
         int i=0;
         int j=0;
         int k=0;
         if(s3[0]!=s1[0] && s3[0]==s2[0]){
            cout<<"Swapped"<<endl;
            swap(s1,s2);
         }

         if(size1+size2<3){
            cout<<"size1+size2<3"<<endl;
            cout<<"Size1:"<<size1<<endl;
            cout<<"Size2:"<<size2<<endl;

            return (s1[0]==s3[0] && s2[0]==s3[1]);
         }

       return f(0,0);

    }
};




// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s1.empty() && s2.empty() && s3.empty()){
//             return true;
//         }
//         int size1=s1.size();
//         int size2=s2.size();
//         int size3=s3.size();
//         if(size1+size2!=size3){
//             cout<<"size1+size2!=size3"<<endl;
//             return false;
//         }

//         if(s3[0]!=s1[0] && s3[0]!=s2[0]){
//             cout<<"s3[0]!=s1[0] && s3[0]!=s2[0]"<<endl;
//             return false;
//          }
//          int l=0;
//          int r=0;
//          int i=0;
//          int j=0;
//          int k=0;
//          if(s3[0]!=s1[0] && s3[0]==s2[0]){
//             cout<<"Swapped"<<endl;
//             swap(s1,s2);
//          }

//          if(size1+size2<3){
//             cout<<"size1+size2<3"<<endl;
//             cout<<"Size1:"<<size1<<endl;
//             cout<<"Size2:"<<size2<<endl;

//             return (s1[0]==s3[0] && s2[0]==s3[1]);
//          }

//         while(i+j+2<size3){
//            cout<<"i+j+2<size3"<<endl;

//             while(s1[i]==s3[k]){
//                 i++;
//                 k++;
//             }
//             if(s2[j]!=s3[k]){
//               cout<<"s2[j]!=s3[k]"<<endl;
//               cout<<"i:"<<i<<" j:"<<j<<endl;
//               cout<<"s2[j]!=s3[k]"<<s2[j]<<" "<<s3[k]<<endl;
//               return false;
//             } 
//             while(s2[j]==s3[k]){
//                 j++;
//                 k++;
//             }
//             if(s1[i]!=s3[k]){
//               cout<<"s1[i]!=s3[k]"<<s1[i]<<" "<<s3[k]<<endl;
//               return false;
//             }             

//         }
//         cout<<"Ans:"<<size3-1<<" "<<k<<endl;
//         return size3-1==k;

//     }
// };