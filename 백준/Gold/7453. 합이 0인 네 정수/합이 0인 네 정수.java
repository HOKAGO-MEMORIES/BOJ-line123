import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] A, B, C, D;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = new int[N]; B = new int[N];
        C = new int[N]; D = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            A[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
            C[i] = Integer.parseInt(st.nextToken());
            D[i] = Integer.parseInt(st.nextToken());
        }

        System.out.println(solve());
    }

    static long solve() {
        int size = N * N;
        int[] sumA = new int[size];
        int[] sumB = new int[size];

        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sumA[idx] = A[i] + B[j];
                sumB[idx] = C[i] + D[j];
                idx++;
            }
        }

        Arrays.sort(sumA);
        Arrays.sort(sumB);

        long ans = 0;
        int left = 0;
        int right = size - 1;

        while (left < size && right >= 0) {
            int curA = sumA[left];
            int curB = sumB[right];
            long sum = (long) curA + curB;

            if (sum == 0) {
                long cntA = 0, cntB = 0;

                while (left < size && curA == sumA[left]) {
                    cntA++;
                    left++;
                }

                while (right >= 0 && curB == sumB[right]) {
                    cntB++;
                    right--;
                }

                ans += cntA * cntB;
            }
            else if (sum < 0)
                left++;
            else
                right--;
        }

        return ans;
    }
}
