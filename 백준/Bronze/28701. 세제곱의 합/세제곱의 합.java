import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        
        int sum = 0;
        int sumTriple = 0;

        for(int i = 1; i <= N; i++) {
            sum += i;
            sumTriple += (i * i * i);
        }
        sb.append(sum).append('\n').append(sum * sum).append('\n').append(sumTriple);
        
        System.out.println(sb);
    }
}