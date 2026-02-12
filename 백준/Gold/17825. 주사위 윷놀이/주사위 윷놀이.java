import java.io.*;
import java.util.*;

public class Main {

    static int[] dices = new int[10];
    static int[] piece = new int[4];
    static boolean[] visited = new boolean[33];

    static int[] score = new int[33];
    static int[] nextNode = new int[33];
    static int[] blueNode = new int[33];

    static int maxScore = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        setupMap();

        for (int i = 0; i < 10; i++)
            dices[i] = Integer.parseInt(st.nextToken());

        play(0, 0);

        System.out.println(maxScore);
    }

    static void setupMap() {
        // 일반 루트
        for (int i = 0; i <= 20; i++) {
            score[i] = 2 * i;
            nextNode[i] = i + 1;
        }

        // 도착 노드
        score[21] = 0;
        nextNode[21] = 21;

        // 파랑 루트 →
        blueNode[5] = 22; score[22] = 13;
        nextNode[22] = 23; score[23] = 16;
        nextNode[23] = 24; score[24] = 19;
        nextNode[24] = 25;

        // 파랑 루트 ↑
        blueNode[10] = 26; score[26] = 22;
        nextNode[26] = 27; score[27] = 24;
        nextNode[27] = 25;

        // 파랑 루트 ←
        blueNode[15] = 28; score[28] = 28;
        nextNode[28] = 29; score[29] = 27;
        nextNode[29] = 30; score[30] = 26;
        nextNode[30] = 25;

        // 파랑 공통 루트
        nextNode[25] = 31; score[31] = 30;
        nextNode[31] = 32; score[32] = 35;
        nextNode[32] = 20;
        score[25] = 25;
    }

    static void play(int turn, int curScore) {
        if (turn == 10) {
            maxScore = Math.max(maxScore, curScore);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int curPosition = piece[i];

            // 이미 도착한 말
            if (curPosition == 21)
                continue;

            int move = dices[turn];
            int nextPosition = curPosition;

            // 파랑 루트 확인
            if (blueNode[curPosition] != 0) {
                nextPosition = blueNode[curPosition];
                move--;
            }

            // 루트 이동
            while (move > 0) {
                nextPosition = nextNode[nextPosition];
                if (nextPosition == 21) break;
                move--;
            }

            if (visited[nextPosition] && nextPosition != 21)
                continue;

            visited[curPosition] = false;
            visited[nextPosition] = true;
            piece[i] = nextPosition;

            play(turn + 1, curScore + score[nextPosition]);

            visited[curPosition] = true;
            visited[nextPosition] = false;
            piece[i] = curPosition;
        }
    }

}
