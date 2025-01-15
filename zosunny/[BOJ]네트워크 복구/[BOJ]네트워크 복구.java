package BOJ.Graph.Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_2211_네트워크복구 {
    static class Point implements Comparable<Point> {
        int y;
        int dis;
        Point(int y, int dis){
            this.y = y;
            this.dis = dis;
        }
        @Override
        public int compareTo(Point o){
            return this.dis - o.dis;
        }
    }

    static int n, m;
    static List<Point>[] list;
    static int[] dis;
    static int[] ans;

    public static void dijkstra(int start){
        PriorityQueue<Point> pq = new PriorityQueue<>();
        boolean[] visited = new boolean[n+1];
        pq.add(new Point(1, 0));
        dis[1] = 0;
        while(!pq.isEmpty()){
            Point p = pq.poll();
            // 한 노드에서 방문 한 노드를 방문처리 하는 것이 아닌
            // 모든 인접 노드를 탐색한 출발 노드를 방문 처리. -> 그래야 모든 최단 거리 확정하고 방문처리 됨
            if(visited[p.y]) continue;
            visited[p.y] = true;
            for(Point next : list[p.y]){
                // 거리 최솟값 갱신
                if(dis[next.y] > dis[p.y] + next.dis){
                    dis[next.y] = dis[p.y] + next.dis;
                    ans[next.y] = p.y;
                    pq.add(new Point(next.y, dis[next.y]));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        list = new ArrayList[n+1];
        for(int i=0; i<n+1; i++){
            list[i] = new ArrayList<>();
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int dis = Integer.parseInt(st.nextToken());
            list[a].add(new Point(b, dis));
            list[b].add(new Point(a, dis));
        }

        dis = new int[n+1];
        ans = new int[n+1];
        Arrays.fill(dis, Integer.MAX_VALUE);

        dijkstra(1);

        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        for(int i=1; i<n+1; i++){
            if(ans[i] != 0) {
                cnt++;
                sb.append(i + " " + ans[i]).append("\n");
            }
        }

        System.out.println(cnt);
        System.out.println(sb.toString());
    }
}
