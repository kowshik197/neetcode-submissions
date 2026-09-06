class KthLargest {
public:
    vector<int> nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->nums=nums;
        this->k=k;
    }
    
    int add(int val) {
        priority_queue<int,vector<int>,greater<int>> pq;

        nums.push_back(val);

        for(int n:nums){
            pq.push(n);

            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
