import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[] arr;

    public static void main(String[] args) throws IOException {
       n = Integer.parseInt(br.readLine());
       arr = new int[n + 1];

       StringTokenizer st = new StringTokenizer(br.readLine());
       for (int i = 1; i <= n; i++) {
           arr[i] = Integer.parseInt(st.nextToken());
       }

       solve();

       System.out.println(sb);
    }

    public static void solve() throws IOException {
        int studentCount = Integer.parseInt(br.readLine());

        for (int i = 0; i < studentCount; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int gender = Integer.parseInt(st.nextToken());
            int target = Integer.parseInt(st.nextToken());

            if (gender == 1) {
                playMale(target);
            } else {
                playFemale(target);
            }
        }

        for (int i = 1; i <= n; i++) {
            sb.append(arr[i]).append(" ");
            if (i % 20 == 0) sb.append('\n');
        }
    }

    public static void playMale(int target) {
        for (int i = target; i <= n; i += target) {
            arr[i] = 1 - arr[i];
        }
    }

    public static void playFemale(int target) {
        arr[target] = 1 - arr[target];
        int left = target - 1;
        int right = target + 1;

        while (left >= 1 && right <= n && arr[left] == arr[right]) {
            arr[left] = 1 - arr[left];
            arr[right] = 1 - arr[right];
            left--;
            right++;
        }
    }
}
