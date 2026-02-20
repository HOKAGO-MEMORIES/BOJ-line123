import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<String, Boolean> map = new HashMap<>();

        int N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for (String s : input)
            map.put(s, false);

        input = br.readLine().split(" ");
        for (String s : input)
            map.replace(s, true);

        map.forEach((key, value) -> {
            if (!value) System.out.println(key);
        });
    }
}
