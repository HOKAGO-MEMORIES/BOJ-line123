import java.io.*;
import java.util.*;

import java.io.*;
import java.util.*;
 
public class Solution {
	
	static class Node{
		int x, y;
		Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
 	
	static int N, ans;
	static boolean[] visited;
	static Node[] nodes;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
         
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
        	N = Integer.parseInt(br.readLine());
        	nodes = new Node[N + 2];
        	
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	nodes[0] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        	nodes[N + 1] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

        	for (int i = 1; i <= N; i++) 
        		nodes[i] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        	
        	visited = new boolean[N + 2];
        	ans = Integer.MAX_VALUE;
        	
        	solve(0, 0, 0);

        	
            sb.append("#").append(test_case).append(" ").append(ans).append('\n');
        }
         
        System.out.println(sb);
    }
    
    static void solve(int cur, int cnt, int dis) {
    	if (dis > ans) return;
    	
    	if (cnt == N) {
    		dis += getDistance(nodes[cur], nodes[N + 1]);
    		ans = Math.min(ans, dis);
    		return;
    	}
    	
    	for (int i = 1; i <= N; i++) {
    		if (!visited[i]) {
    			visited[i] = true;
    			solve(i, cnt + 1, dis + getDistance(nodes[cur], nodes[i]));
    			visited[i] = false;
    		}
    	}
    }
    
    static int getDistance(Node n1, Node n2) {
    	return Math.abs(n1.x - n2.x) + Math.abs(n1.y - n2.y);
    }
}
