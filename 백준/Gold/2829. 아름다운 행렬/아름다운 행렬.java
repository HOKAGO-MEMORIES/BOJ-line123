import java.io.*;
import java.util.*;

public class Main {
	
	private static int N;
	private static int[][] matrix, reverseMatrix;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		
		matrix = new int[N + 1][N + 1];
		reverseMatrix = new int[N + 1][N + 1];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				int value = Integer.parseInt(st.nextToken());
				matrix[i + 1][j + 1] = value + matrix[i][j];
				reverseMatrix[i + 1][j] = value + reverseMatrix[i][j + 1];
			}
		}
		
		System.out.println(solve());
	}
	
	private static int solve() {
		int beauty = 0;
		for (int k = 2; k <= N; k++) {
			for (int i = 0; i <= N - k; i++) {
				for (int j = 0; j <= N - k; j++) {
					int A = matrix[i + k][j + k] - matrix[i][j];
					int B = reverseMatrix[i + k][j] - reverseMatrix[i][j + k];
					beauty = Math.max(beauty, A - B);
				}
			}
		}
		
		
		return beauty;
	}
}
