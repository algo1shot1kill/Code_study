import java.io.*;
import java.util.*;

class 이분_그래프 {

  static int K, V, E;
  static int[] parent;
  static List<Integer>[] adjList;
  static int[] visited;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    K = Integer.parseInt(br.readLine());
    
    for(int k =0; k<K; k++){
      StringTokenizer st = new StringTokenizer(br.readLine());
      V = Integer.parseInt(st.nextToken());
      E = Integer.parseInt(st.nextToken());

      adjList = new ArrayList[V+1];
      visited = new int[V+1];

      for(int i=0; i<=V; i++){
        adjList[i] = new ArrayList<>();
      }

      int u, v;
      for(int e=0; e<E; e++){
        st = new StringTokenizer(br.readLine());
        u = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());
        adjList[u].add(v);
        adjList[v].add(u);
      }
      boolean isTrue = true;
      for(int i=1; i<=V; i++){
        if(visited[i]==0){
          if(!dfs(i, 1)){
            isTrue=false;
            break;
          }
        }
      }
      if(isTrue){
        System.out.println("YES");
      } else {
        System.out.println("NO");
      }
    }
  }

  static boolean dfs(int cur, int group){
    // 1. 체크인
    visited[cur]=group;
    // 2. 연결된 곳 순회
    for(int next: adjList[cur]){
      if(visited[next]==0){
        // 방문
        if(!dfs(next, 3-group)) return false;
      } else {
        if(visited[next]==group){
          return false;
        }
      }
    }
    return true;
  }
}