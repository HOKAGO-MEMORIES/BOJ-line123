import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int min = 1000000;
        int max = -1000000;

        while (st.hasMoreTokens()) {
            int num = Integer.parseInt(st.nextToken());

            if (num > max) {
                max = num;
            }

            if (num < min) {
                min = num;
            }
        }

        bw.write(min + " " + max);

        bw.flush();
        bw.close();
        br.close();
    }
}