import java.io.*;
import java.util.*;

public class Main {
	private static int R, C, ans;
	private static char[][] map;
	private static boolean[] visited;
	private static int[] dx = {1, 0, -1, 0};
	private static int[] dy = {0, -1, 0, 1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		map = new char[R][C];
		for (int i = 0; i < R; i++) {
			String s = br.readLine();
			for (int j = 0; j < C; j++) {
				map[i][j] = s.charAt(j);
			}
		}
		
		visited = new boolean[26];
		Arrays.fill(visited, false);
		visited[map[0][0] - 'A'] = true;
		
		solve(0, 0, 1);
		System.out.println(ans);
	}
	
	private static void solve(int x, int y, int cnt) {
		if (cnt > ans) {
			ans = cnt;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				int cur = map[nx][ny] - 'A';
				if (!visited[cur]) {
					visited[cur] = true;
					solve(nx, ny, cnt + 1);
					visited[cur] = false;
				}
			}
		}
	}
}
