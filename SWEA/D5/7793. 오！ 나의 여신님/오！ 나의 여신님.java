import java.io.*;
import java.util.*;
  
public class Solution {
	
	static class Node {
		int x, y;
		Node (int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
		
	static int N, M;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static Node start;
	static Queue<Node> devil;
	static int[][] map;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
          
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	N = Integer.parseInt(st.nextToken());
        	M = Integer.parseInt(st.nextToken());
        	map = new int[N][M];
        	devil = new ArrayDeque<>();
        	
        	for (int i = 0; i < N; i++) {
        		String input = br.readLine();
        		for (int j = 0; j < M; j++) {
        			if (input.charAt(j) == 'S') {
        				start = new Node(i, j);
        				map[i][j] = 2;
        			}
        			else if (input.charAt(j) == 'D') map[i][j] = 0;
        			else if (input.charAt(j) == 'X') map[i][j] = Integer.MIN_VALUE;
        			else if (input.charAt(j) == '*') {
        				devil.offer(new Node(i, j));
        				map[i][j] = -1;
        			} else {
        				map[i][j] = 1;
        			}
        		}
        	}
        	
            sb.append("#").append(test_case).append(" ").append(solve()).append('\n');
        }
          
        System.out.println(sb);
    }
     
    static String solve() {
    	Queue<Node> player = new ArrayDeque<>(); 
    	player.offer(start);
    	int turn = 0;
    	
    	while (!player.isEmpty()) {
    		turn++;
    		int size = devil.size();
    		while (size-- > 0) {
    			Node curDevil = devil.poll();
    			for (int i = 0; i < 4; i++) {
    				int nx = curDevil.x + dx[i];
    				int ny = curDevil.y + dy[i];
    				
    				if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
    					if (map[nx][ny] > 0) {
    						map[nx][ny] = -1;
    						devil.offer(new Node(nx, ny));
    					}
    				}
    			}
    		}
    		
    		size = player.size();
    		while (size-- > 0) {
    			Node curPlayer = player.poll();
    			for (int i = 0; i < 4; i++) {
    				int nx = curPlayer.x + dx[i];
    				int ny = curPlayer.y + dy[i];
    				
    				if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] >= 0 && map[nx][ny] < 2) {
    					if (map[nx][ny] == 0) {
    						return Integer.toString(turn);
    					}
    					
    					if (map[nx][ny] == 1) {
    						map[nx][ny] = 2;
    						player.offer(new Node(nx, ny));
    					}
    				}
    			}
    		}
    	}
    	
    	return "GAME OVER";
    }
}
