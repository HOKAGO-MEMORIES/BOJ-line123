import java.io.*;
import java.util.*;

public class Main {
	
	static class Node {
		int x, y, time;
		Node(int x, int y, int time) {
			this.x = x;
			this.y = y;
			this.time = time;
		}
	}
		
	private static char[][] map;
	private static int R, C;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		
		for (int i = 0; i < R; i++) {
			String s = br.readLine();
			for (int j = 0; j < C; j++) 
				map[i][j] = s.charAt(j);
		}
		
		int ans = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 'L')
				ans = Math.max(ans, solve(i, j));
			}
		}
		
		System.out.println(ans);
	}
	
	private static int solve(int x, int y) {
		int len = 0;
		int[] dx = {1, 0, -1, 0};
		int[] dy = {0, 1, 0, -1};
		boolean visited[][] = new boolean[R][C];
		Queue<Node> q = new ArrayDeque<>();
		
		q.offer(new Node(x, y, 0));
		visited[x][y] = true;
		
		while(!q.isEmpty()) {
			Node node = q.poll();
			
			if (node.time > len)
				len = node.time;
			
			for (int i = 0; i < 4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];
				
				if (nx >= 0 && ny >= 0 && nx < R && ny < C && map[nx][ny] != 'W' && !visited[nx][ny]) {
					q.offer(new Node(nx, ny, node.time + 1));
					visited[nx][ny] = true;
				}
			}
		}
		
		return len;
	}
}
