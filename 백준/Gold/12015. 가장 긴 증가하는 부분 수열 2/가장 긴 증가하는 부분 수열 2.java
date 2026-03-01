import java.io.*;
import java.util.*;

public class Main {

    static int[] arr, LIS;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        System.out.println(solve(N));
    }

    static int solve(int N) {
        LIS = new int[N];
        LIS[0] = arr[0];
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if (arr[i] > LIS[cnt - 1]) {
                LIS[cnt++] = arr[i];
            } else {
                int low = 0;
                int high = cnt - 1;

                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (LIS[mid] < arr[i]) low = mid + 1;
                    else high = mid - 1;
                }

                LIS[low] = arr[i];
            }
        }

        return cnt;
    }
}
