import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String bomb = br.readLine();

        System.out.println(solve(input, bomb));
    }

    private static String solve(String input, String bomb) {
        StringBuilder sb = new StringBuilder();
        int bombLen = bomb.length();

        for (char c : input.toCharArray()) {
            sb.append(c);

            if (sb.length() >= bombLen) {
                int inputLen = sb.length();
                if (sb.substring(inputLen - bombLen, inputLen).equals(bomb))
                    sb.delete(inputLen - bombLen, inputLen);
            }
        }

        return sb.length() == 0 ? "FRULA" : sb.toString();
    }
}
