import java.io.*;
import java.util.*;
   
public class Solution {
     
    static int[][] field;
    static int N, X;
         
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
           
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            X = Integer.parseInt(st.nextToken());
             
            field = new int[N][N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) 
                    field[i][j] = Integer.parseInt(st.nextToken());
            }
             
            sb.append("#").append(test_case).append(" ").append(solve()).append('\n');
        }
           
        System.out.println(sb);
    }
      
    static int solve() {
        int ans = 0;
         
        for (int i = 0; i < N; i++) {
            if (canBuild(field[i])) ans++; 
        }
         
        for (int j = 0; j < N; j++) {
            int[] col = new int[N];
            for (int i = 0; i < N; i++) col[i] = field[i][j];
            if (canBuild(col)) ans++;
        }
         
        return ans;
    }
     
    static boolean canBuild(int[] line) {
        boolean[] visited = new boolean[N];
         
        for (int i = 0; i < N - 1; i++) {
            if (line[i] == line[i + 1]) continue;
            if (Math.abs(line[i] - line[i + 1]) > 1) return false;
             
            if (line[i] == line[i + 1] + 1) {
                for (int j = i + 1; j <= i + X; j++) {
                    if (j >= N || line[i + 1] != line[j] || visited[j]) return false;
                    visited[j] = true;
                }
            }
            else if (line[i] + 1 == line[i + 1]) {
                for (int j = i; j > i - X; j--) {
                    if (j < 0 || line[i] != line[j] || visited[j]) return false;
                    visited[j] = true;
                }
            }
        }
         
         
        return true;
    }
}