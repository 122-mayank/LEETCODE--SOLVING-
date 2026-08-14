class Solution {
public:
    int maximumLengthSubstring(string s) {
        

        int size = s.size();
        int left = 0;
        int ans = 0;

        unordered_map<char , int>mp;


        for(int right = 0 ; right < size ; right++){

              mp[s[right]]++;

              while(mp[s[right]] > 2){
                 mp[s[left]]--;
                 left = left + 1;
              }

              ans = max(ans , right - left + 1);

        }

        return ans;


    }
};