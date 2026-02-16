import java.io.*;
import java.util.*;

public class Main {

    static int[] height;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        height = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0 ; i < N; i++)
            height[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(height);

        int ans = solve(N, L);
        System.out.println(ans);
    }

    static int solve(int N, int L) {
        for (int i = 0; i < N; i++) {
            if (height[i] > L)
                break;
            L++;
        }

        return L;
    }
}
