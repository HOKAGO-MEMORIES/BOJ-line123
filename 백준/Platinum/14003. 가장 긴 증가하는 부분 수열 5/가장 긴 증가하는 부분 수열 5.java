import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        System.out.println(solve(N));
    }

    static String solve(int N) {
        int[] LIS = new int[N];
        LIS[0] = arr[0];

        int[] tracking = new int[N];
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if (arr[i] > LIS[cnt - 1]) {
                LIS[cnt] = arr[i];
                tracking[i] = cnt;
                cnt++;
            } else {
                int left = 0;
                int right = cnt - 1;

                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[i] > LIS[mid]) left = mid + 1;
                    else right = mid - 1;
                }

                LIS[left] = arr[i];
                tracking[i] = left;
            }
        }

        int idx = cnt - 1;
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = N - 1; i >= 0; i--) {
            if (tracking[i] == idx) {
                result.add(arr[i]);
                idx--;
            }
            if (idx < 0) break;
        }

        Collections.reverse(result);
        return new StringBuilder()
                .append(cnt).append('\n')
                .append(result.stream()
                        .map(String::valueOf)
                        .collect(Collectors.joining(" ")))
                .toString();
    }
}
