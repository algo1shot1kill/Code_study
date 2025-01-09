package BOJ.Implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_19638_센티와마법의뿅망치 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());   // 거인 인구수
        int h = Integer.parseInt(st.nextToken());   // 센티 키
        int t = Integer.parseInt(st.nextToken());   // 뿅망치 횟수

        // 거인 키 내림차순 정렬
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0; i<n; i++){
            pq.add(Integer.parseInt(br.readLine()));
        }

        int cnt = 0; // 뿅망치 사용 횟수
        boolean flag = false;

        for (int i=0; i<t; i++) {
            if (pq.isEmpty()) break;
            // 가장 키 큰 거인
            int now = pq.poll();
            // 센티보다 키가 작은 경우
            if (now < h) {
                sb.append("YES\n").append(cnt);
                flag = true;
                break;
            }
            // 키가 1인 경우
            if (now == 1) {
                pq.add(now);
                break;
            }
            pq.add(now / 2);
            cnt++;
        }

        if (!flag) {
            if (!pq.isEmpty() && pq.peek() < h) sb.append("YES\n").append(cnt);
            else sb.append("NO\n").append(pq.poll());
        }

        System.out.println(sb.toString());
    }
}
