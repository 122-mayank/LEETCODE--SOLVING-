
class Solution {
public:
    int count = 0;
    pair<int , int> solve(TreeNode* root){

        if(root == NULL){
             return { 0 , 0};
        }

        pair<int , int> left = solve(root -> left);
        pair<int , int> right = solve(root -> right);

        int div_value = left.second + right.second + 1;
        int sum = left.first + right.first + root -> val;
        int avg = (sum )/ div_value;

        if(avg == root -> val){
            count = count + 1;
        }

        return{sum , div_value};
        
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int , int> sum = solve(root);
        return count;
    }
};