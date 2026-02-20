import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int H = Integer.parseInt(br.readLine()) * 100;
        int W = Integer.parseInt(br.readLine()) * 100;

        int ans = (H > W) ? W / 2 : H / 2;
        System.out.println(ans);
    }
}
