import java.util.*;
class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        
        // map을 써서 이름:개수 저장
        // discount 순회
        // 있으면 1개씩 줄이기
        // 10일 째 됐을 때 체크?
        // 전체 수량 나타내는 변수 하나해서 0되면 +1
        // 10일 넘어가면 맨 처음꺼 +1해야지
        // stk? filo니까 stack으로 순서대로 저장, map이랑 전체 수량 +1
        int total=0;
        int days = 10;
        Map<String, Integer> map = new HashMap<>();
        for(int i=0; i<want.length; i++){
            map.put(want[i],number[i]);
        }
        
        ArrayDeque<String> q = new ArrayDeque<>();
        int day=0;
        for(int i=0; i<discount.length-days+1; i++){
            Map<String, Integer> dMap = new HashMap<>();
            for(int j = 0; j < days; j++){
                dMap.put(discount[i + j], dMap.getOrDefault(discount[i + j], 0) + 1);
            }
            
            Boolean isIdentical = true;
            
            for(String key : map.keySet()){
                if(map.get(key) != dMap.get(key)){
                    isIdentical = false;
                    break;
                }
            }
            
            answer+= isIdentical ? 1 : 0;
        }
        
        return answer;
    }
}