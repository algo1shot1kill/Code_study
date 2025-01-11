class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        
        for(auto& str: strs)
        {
            auto copy_str = str;
            sort(copy_str.begin(),copy_str.end());
            
            groups[copy_str].push_back(str);
        }
        
        vector<vector<string>> ret;
        
        for(auto& v: groups)
        {
            ret.push_back(v.second);
        }
        return ret;
    }
};