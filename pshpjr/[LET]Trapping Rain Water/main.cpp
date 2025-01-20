class Solution {
public:
    int trap(vector<int>& height) {
        /*
        히스토그램 문제처럼 풀 수 있지 않을까?
        뭔가 왼쪽 오른쪽을 On으로 찾을 수 있다면
        사이 범위 훑더라도 2n으로 처리 가능할 것 같은데
        약간 자기보다 낮은 애 스택에 있으면 빼고, 같거나 높으면 넣으면 될 것 같은데
        */
        stack<int> s;
        int ret = 0;
        for(int i = 0; i < height.size(); i++)
        {
            while(!s.empty() && height[s.top()] < height[i])
            {
                auto cur = s.top();
                s.pop();
                if(s.empty())
                    break;
                auto h = min(height[s.top()], height[i]) - height[cur];
                auto d = (i-s.top()) -1;
                ret += h * d;
            }


            s.push(i);
        }

        return ret;

    }
};