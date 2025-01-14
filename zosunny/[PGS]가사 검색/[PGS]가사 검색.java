import java.util.*;

class Solution {
    
    // 노드 자료구조
    static class Node{
        HashMap<Character, Node> child;
        int cnt;    // 현재 노드에서 시작하는 단어 개수
        Node(){
            this.child = new HashMap<>();
            this.cnt = 0;
        }
    }
    
    // 트라이 자료구조
    static class Trie{
        Node root;
        Trie(){
            this.root = new Node();
        }
        // 단어 삽입
        void insert(String word){
            Node node = root;   // 루트 노드부터 시작
            node.cnt++;
            for(char c : word.toCharArray()){
                node.child.putIfAbsent(c, new Node());  // c 자식 노드 없으면 추가
                node = node.child.get(c);               // 현재 노드를 자식 노드로 이동
                node.cnt++;                             // 이 노드 거치는 단어 개수 증가
            }
        }
        
        // 와일드카드 쿼리 검색
        int search(String query){
            Node node = root;
            for(char c : query.toCharArray()){
                if(c == '?') break;                         // 와일드카드 이후는 탐색 종료
                if(!node.child.containsKey(c)) return 0;    // 노드에 없는 쿼리 문자면 0 반환
                node = node.child.get(c);
            }
            return node.cnt;        // 와일드카드까지 도달했으면, 해당 노드의 단어 수 반환
        }
    }
    
    public int[] solution(String[] words, String[] queries) {
        
        // 단어 길이별 정방향, 역방향 트라이 생성 ('fro??' 일때, '??fro' 일때)
        Map<Integer, Trie> tries = new HashMap<>();
        Map<Integer, Trie> reverseTries = new HashMap<>();
        
        // 길이별 트라이에 word 저장
        for(String word : words){
            int len = word.length();
            tries.putIfAbsent(len, new Trie());
            reverseTries.putIfAbsent(len, new Trie());
            
            tries.get(len).insert(word);
            reverseTries.get(len).insert(new StringBuilder(word).reverse().toString());
        }
        
        // 쿼리별 단어 찾기
        int[] answer = new int[queries.length];
        for(int i=0; i<queries.length; i++){
            String query = queries[i];
            int len = query.length();
            
            // 해당 길이가 아예 없으면
            if(!tries.containsKey(len)){
                answer[i] = 0;
                continue;
            }
            
            // ? 와일드카드로 먼저 시작하면
            if(query.charAt(0) == '?') {
                // 쿼리가 모두 ?면
                if(query.replace("?", "").isEmpty()){
                    answer[i] = reverseTries.get(len).root.cnt;
                }else{
                    String reverseQuery = new StringBuilder(query).reverse().toString();
                    answer[i] = reverseTries.get(len).search(reverseQuery);
                }
            }else{
                answer[i] = tries.get(len).search(query);
            }
        }
        return answer;
    }
}
