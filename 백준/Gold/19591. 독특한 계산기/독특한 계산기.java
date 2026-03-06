import java.io.*;
import java.util.*;

public class Main {

    static Deque<Long> numbers = new ArrayDeque<>();
    static Deque<Character> operators = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        StringBuilder number = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            char cur = input.charAt(i);

            if (i == 0 && cur == '-') {
                number.append(cur);
                continue;
            }

            if (Character.isDigit(cur)) {
                number.append(cur);
            } else {
                numbers.offer(Long.parseLong(number.toString()));
                number = new StringBuilder();
                operators.offer(cur);
            }
        }

        if (number.length() > 0)
            numbers.offer(Long.parseLong(number.toString()));

        System.out.println(solve());
    }

    static long solve() {
        while (!operators.isEmpty()) {
            char leftOperator = operators.peekFirst();
            char rightOperator = operators.peekLast();

            int leftDegree = getDegree(leftOperator);
            int rightDegree = getDegree(rightOperator);

            long left1 = numbers.pollFirst();
            long left2 = numbers.peekFirst();
            numbers.offerFirst(left1);

            long right2 = numbers.pollLast();
            long right1 = numbers.peekLast();
            numbers.offerLast(right2);

            if (leftDegree == rightDegree) {
                long leftCal = calculate(leftOperator, left1, left2);
                long rightCal = calculate(rightOperator, right1, right2);

                if (leftCal >= rightCal)    leftDegree++;
                else rightDegree++;
            }

            if (leftDegree > rightDegree) {
                long n1 = numbers.pollFirst();
                long n2 = numbers.pollFirst();
                numbers.offerFirst(calculate(leftOperator, n1, n2));
                operators.pollFirst();
            } else {
                long n2 = numbers.pollLast();
                long n1 = numbers.pollLast();
                numbers.offerLast(calculate(rightOperator, n1, n2));
                operators.pollLast();
            }
        }

        return numbers.getFirst();
    }

    static int getDegree(char op) {
        if (op == '*' || op == '/') return 2;
        else return 1;
    }

    static long calculate(char op, long n1, long n2) {
        if (op == '*') return n1 * n2;
        else if (op == '/') return n1 / n2;
        else if (op == '+') return n1 + n2;
        else return n1 - n2;
    }

}
