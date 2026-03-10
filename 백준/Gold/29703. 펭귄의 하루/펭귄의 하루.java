import java.io.*;
import java.util.*;

public class Main {
	
	static class Node {
		int x, y;
		Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static int N, M;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static char[][] graph;
	static Node start, end;
	static List<Node> fishes = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		graph = new char[N][M];
		for (int i = 0; i < N; i++) {
			String input = br.readLine();
			for (int j = 0; j < M; j++) {
				graph[i][j] = input.charAt(j);
				if (graph[i][j] == 'S')	start = new Node(i, j);
				if (graph[i][j] == 'H') end = new Node(i, j);
				if (graph[i][j] == 'F') fishes.add(new Node(i, j));
			}
		}
				
		System.out.println(solve());
	}
	
	static int solve() {	
		int[][] distS = bfs(start);
		int[][] distH = bfs(end);
		
		int ans = Integer.MAX_VALUE;
		for (Node fish : fishes) {
			int fishToStart = distS[fish.x][fish.y];
			int fishToEnd = distH[fish.x][fish.y];
			
			if (fishToStart != -1 && fishToEnd != -1)
				ans = Math.min(ans, fishToStart + fishToEnd);
		}
						
		
		return (ans == Integer.MAX_VALUE) ? -1 : ans;
	}
	
	static int[][] bfs(Node node) {
		Queue<Node> q = new ArrayDeque<>();
		q.offer(node);
				
		int[][] dist = new int[N][M];
		for (int i = 0; i < N; i++)
			Arrays.fill(dist[i], -1);
		dist[node.x][node.y] = 0;
		
		while (!q.isEmpty()) {
			Node cur = q.poll();
			
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				
				if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (dist[nx][ny] == -1 && graph[nx][ny] != 'D') {
						dist[nx][ny] = dist[cur.x][cur.y] + 1;
						q.offer(new Node(nx, ny));
					}
				}					
			}
		}
		
		return dist;
	}
	
}
