import java.util.*;
class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        Map<Integer, Integer> oMap = new HashMap<>();
        Map<Integer, Integer> yMap = new HashMap<>();
        
        for(int t: topping){
            oMap.put(t, oMap.getOrDefault(t,0)+1);
        }
        
        for(int t: topping){
            yMap.put(t, yMap.getOrDefault(t,0)+1);
            
            if(oMap.get(t)-1==0){
                oMap.remove(t);
            } else {
                oMap.put(t, oMap.get(t)-1);
            }
            
            if(yMap.size()==oMap.size()){
                answer++;
            }
        }
        
        
        
        
        
        return answer;
    }
}