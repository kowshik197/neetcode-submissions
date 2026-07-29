class Solution {
public:

    void transpose(vector<vector<int>>& matrix){
        for(int r=0;r<matrix.size();r++){
            for(int c=r+1;c<matrix.size();c++){
                swap(matrix[r][c],matrix[c][r]);
            }
        }
    }
    void refV(vector<vector<int>>& matrix){
        for(auto& row: matrix){
            reverse(row.begin(),row.end());
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        refV(matrix);
    }
};
