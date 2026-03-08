import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {-1, 0, 1};
	static char[][] graph;
	static int R, C;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		graph = new char[R][C];

		for (int i = 0; i < R; i++) {
			String input = br.readLine();
			for (int j = 0; j < C; j++) 
				graph[i][j] = input.charAt(j);
		}
		
		int ans = 0;
		
		for (int i = 0; i < R; i++) {
			if (solve(i, 0))	ans++;
		}
		
		System.out.println(ans);
	}
	
	static boolean solve(int x, int y) {
		graph[x][y] = 'x';
		
		if (y == C - 1)	return true;
		
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + 1;
			
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) 
				if (graph[nx][ny] == '.') 
					if (solve(nx, ny)) return true;
		}
		
		return false;
	}
	
}
