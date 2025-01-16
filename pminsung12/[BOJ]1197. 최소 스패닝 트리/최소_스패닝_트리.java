import java.io.*;
import java.util.*;


class 최소_스패닝_트리 {

  static class Node implements Comparable<Node> {
    int from;
    int to;
    int weight;
  
    public Node(int from, int to, int weight){
      this.from = from;
      this.to = to;
      this.weight = weight;
    }
  
    // weight에 따라 정렬
    @Override
    public int compareTo(Node o){
      return this.weight - o.weight;
    }

  }
  

  static int N,M;
  static int[] parent;
  static List<Node> edgeList;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    
    parent = new int[N+1];
    edgeList = new ArrayList<>();
    
    // 1. 초기화
    initParent();

    // 2. edgeList 저장
    int from, to, weight;
    for(int m =0; m<M; m++){
      st = new StringTokenizer(br.readLine());
      from = Integer.parseInt(st.nextToken());
      to = Integer.parseInt(st.nextToken());
      weight = Integer.parseInt(st.nextToken());
      edgeList.add(new Node(from, to, weight));
    }

    // weight 기준으로 edge 정렬
    Collections.sort(edgeList);

    System.out.println(kruskal());
    
  }

  static void initParent(){
    for(int i=1; i<=N; i++){
      parent[i]=i;
    }
  }

  static int find(int a){
    if(a==parent[a]){
      return a;
    } else {
      return parent[a] = find(parent[a]);
    }
  }

  static boolean union(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if(rootA != rootB){
      parent[rootB] = rootA;
      return true;
    } else {
      return false;
    }
  }

  static int kruskal(){
    
    int edgeCnt =0;
    int totalWeight=0;
    for(Node edge: edgeList){
      if(edgeCnt==N-1){
        break;
      }
      if(union(edge.from, edge.to)){
        totalWeight += edge.weight;
        edgeCnt++;
      }
    }

    return totalWeight;
  }

}