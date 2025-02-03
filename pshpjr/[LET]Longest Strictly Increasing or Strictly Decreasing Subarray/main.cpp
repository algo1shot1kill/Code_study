class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        /*모든 쌍 비교는 시간 초과 남
        정렬하고 유니크하게 만들어도 전부 다른 값 들어올 가능성 있음. 
        (a,b) (A,B)
        (a^A) ^ (a^B)^(b^A)^(b^B)
        a^a^b^b^A^A^B^B
        상대방이 짝수면 나는 무시
        */
        int n1 = 0;
        int n2 = 0;

        if(nums2.size()%2 == 1)
        {
            n1 = accumulate(nums1.begin(),nums1.end(),0,bit_xor());
        }
        if(nums1.size()%2 == 1)
        {
            n2 = accumulate(nums2.begin(),nums2.end(),0,bit_xor());
        }
        return n1^n2;

    }
};