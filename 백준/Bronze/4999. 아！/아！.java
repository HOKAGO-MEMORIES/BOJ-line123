import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        if (br.readLine().length() >= br.readLine().length()) {
            System.out.println("go");
        } else {
            System.out.println("no");
        }
    }
}
