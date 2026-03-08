import java.io.*;
import java.util.*;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        arr = new int[N][K];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < K; j++)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        int ans = solve(N, K);
        System.out.println(ans);
    }

    static int solve(int N, int K) {
        int ans = 0;

        boolean[] isSelected = new boolean[N];

        for (int j = 0; j < K; j++) {
            int max = 0, maxIdx = -1;
            boolean isMax = true;

            for (int i = 0; i < N; i++) {
                if (arr[i][j] == max)   isMax = false;

                if (arr[i][j] > max) {
                    isMax = true;
                    maxIdx = i;
                    max = arr[i][j];
                }
            }

            if (isMax && maxIdx != -1) {
                if (!isSelected[maxIdx])    ans++;
                isSelected[maxIdx] = true;
            }
        }

        return ans;
    }
}
