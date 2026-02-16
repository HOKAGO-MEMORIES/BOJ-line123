import java.io.*;
import java.util.*;

public class Main {

    static String input;
    static int S, P, ans;
    static int[] condition = new int[5];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        input = br.readLine();

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= 4; i++)
            condition[i] = Integer.parseInt(st.nextToken());

        solve();

        System.out.println(ans);
    }

    static void solve() {
        int[] check = new int[S + 1];;
        int[] result = new int[5];

        for (int i = 0; i < S; i++) {
            switch (input.charAt(i)) {
                case 'A':
                    check[i] = 1;
                    break;
                case 'C':
                    check[i] = 2;
                    break;
                case 'G':
                    check[i] = 3;
                    break;
                case 'T':
                    check[i] = 4;
                    break;
                default:
                    break;
            }
        }

        for (int i = 0; i < P; i++)
            result[check[i]]++;

        ans++;
        for (int i = 1; i <= 4; i++) {
            if (result[i] < condition[i]) {
                ans--;
                break;
            }
        }

        for (int start = 1; start <= S - P; start++) {
            int end = start + P - 1;

            result[check[start - 1]]--;
            result[check[end]]++;

            ans++;
            for (int i = 1; i <= 4; i++) {
                if (result[i] < condition[i]) {
                    ans--;
                    break;
                }
            }
        }
    }

}
