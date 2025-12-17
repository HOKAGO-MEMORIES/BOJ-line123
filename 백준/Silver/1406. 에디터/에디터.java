import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {

    private static final StringBuilder sb = new StringBuilder();
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String input = br.readLine();
        Deque<Character> leftStack = new ArrayDeque<>();

        for (char c : input.toCharArray()) {
            leftStack.push(c);
        }

        int m = Integer.parseInt(br.readLine());
        solve(leftStack, m);

        System.out.println(sb);
        br.close();
    }

    public static void solve(Deque<Character> leftStack, int m) throws IOException {
        Deque<Character> rightStack = new ArrayDeque<>();

        while(m-- > 0) {
            String command = br.readLine();
            char c = command.charAt(0);

            switch (c) {
                case 'L':
                    if (!leftStack.isEmpty()) {
                        rightStack.push(leftStack.pop());
                    }
                    break;
                case 'D':
                    if (!rightStack.isEmpty()) {
                        leftStack.push(rightStack.pop());
                    }
                    break;
                case 'B':
                    if (!leftStack.isEmpty()) {
                        leftStack.pop();
                    }
                    break;
                case 'P':
                    leftStack.push(command.charAt(2));
                    break;
            }
        }

        while (!leftStack.isEmpty()) {
            rightStack.push(leftStack.pop());
        }

        while(!rightStack.isEmpty()) {
            sb.append(rightStack.pop());
        }
    }
}
