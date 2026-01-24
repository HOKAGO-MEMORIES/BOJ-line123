import java.io.*;
import java.util.*;

public class Main {

    private static int[] arr;
    private static int[] dp_r;
    private static int[] dp_l;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        dp_l = new int[N];
        dp_r = new int[N];

        for (int i = 0; i < N; i++)
            LIS(i);

        for (int i = N - 1; i >= 0; i--)
            LDS(i);

        int ans = -1;
        for (int i = 0; i < N; i++)
            ans = Math.max(ans, dp_l[i] + dp_r[i]);

        System.out.println(ans - 1);
    }

    // 최장 증가 부분수열
    private static void LIS(int N) {
        if (dp_r[N] == 0)
            dp_r[N]++;

        for (int i = 0; i < N; i++)
            if (arr[N] > arr[i])
                dp_r[N] = Math.max(dp_r[N], dp_r[i] + 1);
    }

    // 최장 감소 부분수열
    private static void LDS(int N) {
        if (dp_l[N] == 0)
            dp_l[N]++;

        for (int i = dp_l.length - 1; i >= N ; i--)
            if (arr[N] > arr[i])
                dp_l[N] = Math.max(dp_l[N], dp_l[i] + 1);
    }

}
