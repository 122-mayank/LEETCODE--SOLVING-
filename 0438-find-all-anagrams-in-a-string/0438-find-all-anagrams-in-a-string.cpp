class Solution {
public:
    bool allZeroes(unordered_map<char , int>&freq){


        for(auto it : freq){
             if(it.second != 0) return false;
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {

        int m = s.size();
        int n = p.size();

        //make the map
        unordered_map<char , int>freq;
        for(int i = 0 ; i < n ; i++){
             freq[p[i]]++;
        }

        int i = 0;
        int j = 0;

        vector<int>ans;

        while( j < m ){

            freq[s[j]]--;

            if( j - i + 1 == n){
                 if(allZeroes(freq)){
                      ans.push_back(i);
                 }

                 freq[s[i]]++;
                 i = i + 1;
            }

            j++;

        }
        return ans;
    }
};