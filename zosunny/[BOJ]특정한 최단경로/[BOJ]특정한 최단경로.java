package BOJ.Graph.Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1504_특정한최단경로 {

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

    static int n, e;
    static int v1, v2;
    static final int INF = Integer.MAX_VALUE;
    static List<Point>[] list;
    static int[] dist;

    public static int dijk(int s, int e){
        PriorityQueue<Point> pq = new PriorityQueue<>();
        dist = new int[n+1];
        Arrays.fill(dist, INF);

        dist[s] = 0;
        pq.add(new Point(s, 0));
        while(!pq.isEmpty()){
            Point p = pq.poll();
            for(Point now : list[p.y]){
                if(dist[now.y] > dist[p.y] + now.dis){
                    dist[now.y] = dist[p.y] + now.dis;
                    pq.add(new Point(now.y, dist[now.y]));
                }
            }
        }
        return dist[e];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        list = new ArrayList[n+1];
        for(int i=0; i<n+1; i++){
            list[i] = new ArrayList<>();
        }

        for(int i=0; i<e; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            list[x].add(new Point(y, d));
            list[y].add(new Point(x, d));
        }

        st = new StringTokenizer(br.readLine());
        v1 = Integer.parseInt(st.nextToken());
        v2 = Integer.parseInt(st.nextToken());

        // 1 -> v1 -> v2 -> n / 1 -> v2 -> v1 -> n
        long ans = Math.min((long) dijk(1, v1) + dijk(v1, v2) + dijk(v2, n), (long) dijk(1, v2) + dijk(v2, v1) + dijk(v1, n));

        if(ans >= INF) System.out.println(-1);
        else System.out.println(ans);

    }
}
