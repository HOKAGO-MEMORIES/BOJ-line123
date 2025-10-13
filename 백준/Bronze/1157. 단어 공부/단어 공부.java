import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] arr = new int[26];
        String s = br.readLine().toUpperCase();

        for (char c : s.toCharArray()) {
            arr[c - 'A']++;
        }

        int max = -1;
        char result = '?';

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
                result = (char)(i + 'A');
            } else if (arr[i] == max) {
                result = '?';
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(result);

        bw.flush();
        bw.close();
        br.close();
    }
}