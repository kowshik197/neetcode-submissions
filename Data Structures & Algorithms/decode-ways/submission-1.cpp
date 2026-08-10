class Solution {
public:

string s="";
int n;
vector<int> memo;
int f(int i){

    if(i==s.size()){
            return 1;
    }
    if(s[i]=='0'){
            return 0;
    }

    if(memo[i]!=-1){
            return memo[i];
    }

    int ways =0;

    ways+= f(i+1);

    if(i+1<n && ((s[i]=='1') || (s[i]=='2' && s[i+1]<='6'))){
        ways+=f(i+2);
    }

        return memo[i]=ways;

}

int numDecodings(string s) {
    n=s.size();
    this->s=s;
    memo.assign(n,-1);
   
    return  f(0);
       }
};