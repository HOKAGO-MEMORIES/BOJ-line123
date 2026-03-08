import java.io.*;
import java.util.*;

public class Main {
	
	static boolean[][] student;
	static int N, M;
		
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); 
		M = Integer.parseInt(st.nextToken());
		student = new boolean[N + 1][N + 1];
		
		while (M-- > 0) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			student[a][b] = true;
		}
		
		for (int i = 1; i <= N; i++)
			student[i][i] = true;
		
		
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++) 
				for (int j = 1; j <= N; j++) 
					if (student[i][k] && student[k][j])
						student[i][j] = true;
				
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			int cnt = 0;
			for (int j = 1; j <= N; j++) {
				if (student[i][j] || student[j][i]) {
					cnt++;
				}
			}
			
			if (cnt == N) ans++;
		}
		
		System.out.println(ans);
	}
}
