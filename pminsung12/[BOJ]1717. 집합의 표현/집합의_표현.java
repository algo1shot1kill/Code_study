import java.io.*;
import java.util.*;

class 집합의_표현 {

  static int N,M;
  static int[] parent;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    parent = new int[N+1];

    for(int i=0; i<N+1; i++){
      parent[i] = i;
    }

    int cmd, a, b;
    
    for(int m =0; m<M; m++){
      st = new StringTokenizer(br.readLine());
      cmd = Integer.parseInt(st.nextToken());
      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());

      if(cmd==0){
        union(a,b);
      } else {
        System.out.println((find(a)==find(b) ? "YES" : "NO"));
      }
      
    }
  }

  static int find(int a){
    if(a==parent[a]){
      return a;
    }
    return parent[a] = find(parent[a]);
  }
  
  static void union(int a, int b){

    int aRoot = find(a);
    int bRoot = find(b);

    if(aRoot != bRoot){
      parent[bRoot]=aRoot;
    }
  }
}