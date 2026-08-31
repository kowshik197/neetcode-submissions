class Solution {
public:

    int operatorApp(int a,int b,string op){
        if(op=="+"){
            return a+b;
        }
        if(op=="-"){
            return a-b;
        }
        if(op=="*"){
            return a*b;
        }
        if(op=="/"){
            return a/b;
        }                        
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string token:tokens){

             if(token!= "+" && token!="-" && token!="*" && token!="/"){
                st.push(stoi(token));
             }
             else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();

                int ans=operatorApp( b, a, token);
                st.push(ans);


             }


        }

     return st.top();
    }
};
