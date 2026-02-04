import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int C = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        // 고객 수는 초과 가능, C 값을 뛰어 넘을 때도 생각
        int maxPerson = C + 101;
        int[] dp = new int[maxPerson];
        
        // 그냥 Integer.MAX_VALUE로 두면 터짐
        Arrays.fill(dp, Integer.MAX_VALUE - 101);
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int cost = Integer.parseInt(st.nextToken());
            int person = Integer.parseInt(st.nextToken());

            // 특정 인원 수 일 때 가지는 최솟값 계산
            for (int j = person; j < maxPerson; j++)
                dp[j] = Math.min(dp[j], cost + dp[j - person]);
        }

        int ans = Integer.MAX_VALUE;
        // C 값을 뛰어 넘는 것까지 생각
        for (int i = C; i < maxPerson; i++)
            ans = Math.min(ans, dp[i]);

        System.out.println(ans);
    }
}
