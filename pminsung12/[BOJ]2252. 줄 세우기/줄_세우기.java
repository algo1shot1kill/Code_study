import java.io.*;
import java.util.*;

class 줄_세우기 {

  static int N,M;
  static int[] indegree;
  static List<Integer>[] adjList;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    adjList = new ArrayList[N+1];
    indegree = new int[N+1];
    for(int i=0; i<=N; i++){
      adjList[i] = new ArrayList<>();
    }

    int from, to;
    for(int m =0; m<M; m++){
      st = new StringTokenizer(br.readLine());
      from = Integer.parseInt(st.nextToken());
      to = Integer.parseInt(st.nextToken());
      adjList[from].add(to);
      indegree[to]++;
    }
    String s = topologySort();
    System.out.println(s);
  }

  static String topologySort(){
    StringBuilder sb = new StringBuilder();
    ArrayDeque<Integer> q = new ArrayDeque<>();
    for(int i=1; i<=N ;i++){
      if(indegree[i]==0){
        q.add(i);
      }
    }

    while(!q.isEmpty()){
      int from = q.poll();
      sb.append(from).append(' ');
      for(int to: adjList[from]){
        indegree[to]--;
        if(indegree[to]==0){
          q.add(to);
        }
      }
    }

    return sb.toString();
  }

}