import java.io.*;
import java.util.*;
  
public class Solution {
	
	static class Node {
		int r, c, t;
		Node (int r, int c, int t) {
			this.r = r;
			this.c = c;
			this.t = t;
		}
	}
	
	static int N, ans;
	static ArrayList<Node> people, door;
	static int[] match;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        
        for (int test_case = 1; test_case <= T; test_case++) {
        	N = Integer.parseInt(br.readLine());

        	door = new ArrayList<>();
        	people = new ArrayList<>();
        	
        	for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                	int input = Integer.parseInt(st.nextToken());
                	if (input > 0) {
                		if (input == 1) {
                			people.add(new Node(i, j, 0));
                		} else {
                			door.add(new Node(i, j, input));
                		}
                	}
                }
        	}

        	ans = Integer.MAX_VALUE;
        	match = new int[people.size()];
        	dfs(0);
        	
        	sb.append("#").append(test_case).append(" ").append(ans).append('\n');
        }
        
        System.out.println(sb);
    }
    
    static void dfs(int depth) {
    	if (depth == people.size()) {
    		int time = simulate();
    		ans = Math.min(ans, time);
    		return;
    	}
    	
    	match[depth] = 0;
    	dfs(depth + 1);
    	
    	match[depth] = 1;
    	dfs(depth + 1); 
    }
    
    static int simulate() {
    	PriorityQueue<Integer> stair0 = new PriorityQueue<>();
    	PriorityQueue<Integer> stair1 = new PriorityQueue<>();
    	
    	for (int i = 0; i < people.size(); i++) {
    		Node p = people.get(i);
    		if (match[i] == 0) {
    			Node d = door.get(0);
    			stair0.add(getDistance(p.r, p.c, d.r, d.c));
    		} else {
    			Node d = door.get(1);
    			stair1.add(getDistance(p.r, p.c, d.r, d.c));
    		}
    	}
    	
    	int time0 = getTime(stair0, door.get(0).t);
    	int time1 = getTime(stair1, door.get(1).t);
    	
    	return Math.max(time0, time1);
    }
    
	static int getTime(PriorityQueue<Integer> stair, int stairLen) {
		if (stair.isEmpty()) return 0;
		
		int len = stair.size();
		int[] exit = new int[len];
		
		for (int i = 0; i < len; i++) {
			int time = stair.poll() + 1;
			
			if (i >= 3) {
				time = Math.max(time, exit[i - 3]);
			}
			
			exit[i] = time + stairLen;
		}
		
		return exit[len - 1];
	}
	
	static int getDistance(int pr, int pc, int sr, int sc) {
		return Math.abs(pr - sr) + Math.abs(pc - sc);
	}
}
