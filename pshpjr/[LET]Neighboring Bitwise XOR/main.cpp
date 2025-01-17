class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //역산하는 경우에는 이전 값이 0이냐 1이냐에 따라서 내 값이 바뀜
        //무식하게 풀기 : 모든 이진 배열에 대해서 돌려보기.
        //각 스탭마다 0,1을 넣고 이게 가능한지 계산. 
        //재귀로 짜면 메모리 초과. 벡터에서 str로 바꿔야 할 듯.  
        //그런데 내 다음 값은 내 값에 의존함. 
        //시작 값이 0인지 1인지만 보면 되나? 
        //그냥 배열 순회로


        /*
        int cur = 1;
        for i in n
            cur ^= derived[i]; 
        
        if(cur == 1)
            return true;

        cur = 0;
        for i in n
            cur ^= derived[i]; 

        if(cur   == 0)
            return true;

        return false;
        */


        int cur = 1;
        for(auto i : derived)
        {
            cur ^= i;
        }
        if(cur  == 1)
            return true;

        cur = 0;
        for(auto i : derived)
        {
            cur ^= i;
        }
        
        if(cur  == 0)
            return true;

        return false;

    }
};