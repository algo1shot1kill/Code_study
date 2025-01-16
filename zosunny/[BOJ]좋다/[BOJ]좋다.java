package BOJ.BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1253_좋다 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        int cnt = 0;
        for(int i=0; i<n; i++){
            int now = arr[i];
            int s = 0;
            int e = n - 1;
            while(s < e){
                int sum = arr[s] + arr[e];
                // s, e가 i인 경우 제외
                if(s == i) s++;
                else if(e == i) e--;
                // 좋다를 만족 하는 수
                else if(sum == now) {
                    cnt++;
                    break;
                }
                else  if(sum > now) e--;
                else s++;
            }
        }
        System.out.println(cnt);
    }
}
