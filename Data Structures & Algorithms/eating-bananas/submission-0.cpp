class Solution {
public:

   bool isBefore(int val,const vector<int> arr,int hours){
     long long time=0;
      for(int i=0;i<arr.size();i++){
             time+= ceil((double)arr[i]/val);
      }
  
     return time>hours;

       
   }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int size=piles.size();
        int left=1;
        int right=*max_element(piles.begin(),piles.end());

        while(right-left>1){
           int mid=(left+right)>>1;
           if(isBefore(mid,piles,h)){
            left=mid;
           }

           else{
            right=mid;
           }
}
      if(!isBefore(left,piles,h)) return left;   // If I eat left amount of values... then value time<= hours must satisfy or we can say if not... after eating left amount of banana... time taken is > than hours
      return right;      
    }
};