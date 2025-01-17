package BOJ.BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_2470_두용액 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int[] ans = new int[2];
        int res = Integer.MAX_VALUE;

        int s = 0;
        int e = n - 1;
        while(s < e){
            int sum = arr[s] + arr[e];
            if(sum == 0) {
                ans[0] = arr[s];
                ans[1] = arr[e];
                break;
            }
            if (sum < 0) {
                // |sum|이 이전 res 값보다 작으면 치환 (ex. sum=-6, res=15)
                if(Math.abs(sum) < res){
                    res = Math.abs(sum);
                    ans[0] = arr[s];
                    ans[1] = arr[e];
                }
                s++;
            }
            else {
                // sum이 이전 res 값보다 작으면 치환 (ex. sum=6, res=15)
                if(sum < res){
                    res = Math.abs(sum);
                    ans[0] = arr[s];
                    ans[1] = arr[e];
                }
                e--;
            }
        }
        System.out.println(ans[0] + " " + ans[1]);
    }
}
