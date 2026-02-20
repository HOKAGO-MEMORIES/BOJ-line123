import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<>();

        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String fruit = st.nextToken();
            int count = Integer.parseInt(st.nextToken());

            map.put(fruit, map.getOrDefault(fruit, 0) + count);
        }

        String ans = (map.containsValue(5)) ? "YES" : "NO";
        System.out.println(ans);
    }
}
