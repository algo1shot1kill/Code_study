import java.io.*;
import java.util.*;


class 골목길 {

  static class Edge {
    int from;
    int to;
    int weight;

    public Edge(int from, int to, int weight) {
      this.from = from;
      this.to = to;
      this.weight = weight;
    }
  }

  static int N,M;
  static List<Edge> edgeList;
  static int[] dist;
  static int[] prev;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    edgeList = new ArrayList<>();
    dist = new int[N+1];
    prev = new int[N+1];
    Arrays.fill(dist, Integer.MIN_VALUE);
    Arrays.fill(prev, -1);

    int from, to, weight;
    for(int m =0; m<M; m++){
      st = new StringTokenizer(br.readLine());
      from = Integer.parseInt(st.nextToken());
      to = Integer.parseInt(st.nextToken());
      weight = Integer.parseInt(st.nextToken());
      edgeList.add(new Edge(from, to, weight));
    }

    if (!bellmanFord(1)) {
      System.out.println(-1); // 음수 사이클로 최적 경로를 구할 수 없는 경우
    } else if (dist[N] == Integer.MIN_VALUE) {
        System.out.println(-1); // 도달 불가능한 경우
    } else {
        printPath();
    }
  }

  static boolean bellmanFord(int start){
    dist[start]=0;
    // 벨만 포드는 N-1번 반복!
    for(int i=1; i<N; i++){
      for(Edge edge: edgeList){
        if(dist[edge.from]!=Integer.MIN_VALUE && dist[edge.to]<dist[edge.from]+edge.weight){
          dist[edge.to] = dist[edge.from]+edge.weight;
          prev[edge.to] = edge.from;
        }
      }
    }
    
    // 음수 사이클 체크
    for (Edge edge : edgeList) {
      if (dist[edge.from] != Integer.MAX_VALUE && dist[edge.to] < dist[edge.from] + edge.weight) {
          // 음수 사이클이 n번 노드에 도달 가능한지 추가 확인
          if (canReach(edge.to)) {
              return false;
          }
      }
  }

  return true;
  }

  static boolean canReach(int start) {
    boolean[] visited = new boolean[N + 1];
    Queue<Integer> queue = new LinkedList<>();
    queue.add(start);
    visited[start] = true;

    while (!queue.isEmpty()) {
        int current = queue.poll();
        if (current == N) return true; // n번 노드에 도달 가능
        for (Edge edge : edgeList) {
            if (edge.from == current && !visited[edge.to]) {
                visited[edge.to] = true;
                queue.add(edge.to);
            }
        }
    }
    return false;
}

static void printPath() {
    List<Integer> path = new ArrayList<>();
    for (int at = N; at != -1; at = prev[at]) {
        path.add(at);
    }
    Collections.reverse(path);

    for (int node : path) {
        System.out.print(node + " ");
    }
}


}