package BOJ.Graph.BellmanFord;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_11657_타임머신 {

    static class Point{
        int e;
        int dis;
        Point(int e, int dis){
            this.e = e;
            this.dis = dis;
        }
    }

    static final int INF = Integer.MAX_VALUE;
    static int n, m;
    static List<Point>[] list;
    static long[] dist;

    public static boolean bellmanford(){
        dist[1] = 0;
        // 1. 최단거리 구하기 (n - 1)번 반복
        for (int i = 1; i < n; i++) {
            boolean flag = false;

            for (int j = 1; j <= n; j++) {
                if (dist[j] == INF) continue;

                for (Point p : list[j]) {
                    if (dist[j] + p.dis < dist[p.e]) {
                        dist[p.e] = dist[j] + p.dis;
                        flag = true;
                    }
                }
            }
            // 갱신이 없으면 종료
            if (!flag) break;
        }

        // 2. 음수 사이클 확인
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) continue;

            for (Point p : list[i]) {
                if (dist[i] + p.dis < dist[p.e]) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        list = new ArrayList[n+1];
        dist = new long[n+1];
        for(int i=0; i<n+1; i++){
            list[i] = new ArrayList<>();
            dist[i] = INF;
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            list[x].add(new Point(y, d));
        }

        StringBuilder sb = new StringBuilder();
        // 음수 사이클이 존재하면 -1출력
        if(bellmanford()) sb.append(-1);
        // 그외 각 경로 출력
        else{
            for(int i=2; i<n+1; i++){
                if(dist[i] == INF) sb.append(-1).append("\n");
                else sb.append(dist[i]).append("\n");
//                sb.append(dist[i]).append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}
