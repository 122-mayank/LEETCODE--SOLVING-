class ProductOfNumbers {
public:

    vector<int>ans;
    ProductOfNumbers() {
        ans = ans;
    }
    
    void add(int num) {
      ans.push_back(num);
    }
    
    int getProduct(int k) {
        
        int size = ans.size();

        int result = 1;

        for(int i = size - 1 ; i >= size - k ; i--){
             result = result * ans[i];
        }

        return result;

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */