class Solution {
public:
    vector<string> generateParenthesis(int n) {
        N = n;
        rec("",0,0);
        return ret;
    }
    private:

    
    void rec(string str, int open, int close)
    {
        if(str.length() == 2*N)
        {
            ret.push_back(str);
            return;
        }
        
        if(open < N)
        {
            rec(str+'(',open+1, close );
        }
        if(close < open)
        {
            rec(str + ')', open, close + 1);
        }
        return;
    }
    
    
    vector<string> ret;
    int N;
};