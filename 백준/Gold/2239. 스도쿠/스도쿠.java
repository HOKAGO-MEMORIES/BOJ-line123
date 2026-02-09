import java.io.*;
import java.util.*;

public class Main {

    static int[][] sudoku = new int[9][9];
    // 1 : 3x3 사각형, 2 : 가로, 3 : 세로
    static int[] check1 = new int[9];
    static int[] check2 = new int[9];
    static int[] check3 = new int[9];
    static ArrayList<int[]> zeroList = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++) {
            String input = br.readLine();
            for (int j = 0; j < 9; j++) {
                int num = input.charAt(j) - '0';
                sudoku[i][j] = num;
                if (num != 0) {
                    check1[getSquareIdx(i, j)] |= (1 << num);
                    check2[i] |= (1 << num);
                    check3[j] |= (1 << num);
                } else {
                    zeroList.add(new int[]{i, j});
                }
            }
        }

        solve(0);
    }

    static int getSquareIdx(int x, int y) {
        return (x / 3) * 3 + (y / 3);
    }

    static void solve(int depth) {
        if (depth == zeroList.size()) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++)
                    sb.append(sudoku[i][j]);
                sb.append('\n');
            }

            System.out.println(sb);
            System.exit(0);
        }

        int x = zeroList.get(depth)[0];
        int y = zeroList.get(depth)[1];

        for (int i = 1; i <= 9; i++) {
            if ((check1[getSquareIdx(x, y)] & (1 << i)) == 0 &&
                    (check2[x] & (1 << i)) == 0 && (check3[y] & (1 << i)) == 0) {
                check1[getSquareIdx(x, y)] |= (1 << i);
                check2[x] |= (1 << i);
                check3[y] |= (1 << i);
                sudoku[x][y] = i;

                solve(depth + 1);

                check1[getSquareIdx(x, y)] &= ~(1 << i);
                check2[x] &= ~(1 << i);
                check3[y] &= ~(1 << i);
                sudoku[x][y] = 0;
            }
        }
    }
}
