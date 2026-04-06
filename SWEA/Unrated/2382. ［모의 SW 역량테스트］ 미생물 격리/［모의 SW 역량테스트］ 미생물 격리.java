import java.io.*;
import java.util.*;
  
public class Solution {
	
	static class Micro implements Comparable<Micro> {
		int x, y, t, d;
		Micro(int x, int y, int t, int d) {
			this.x = x;
			this.y = y;
			this.t = t;
			this.d = d;
		}
		
		@Override
		public int compareTo(Micro o) {
		    if (this.x != o.x) return this.x - o.x; 
		    if (this.y != o.y) return this.y - o.y;
		    return o.t - this.t; 
		}
	}
	
	static int N, M, K;
	static int[] dx = {0, -1, 1, 0, 0};
	static int[] dy = {0, 0, 0, -1, 1};
	static ArrayList<Micro> microList;
         
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
          
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            
            microList = new ArrayList<>();
            
            while (K-- > 0) {
            	st = new StringTokenizer(br.readLine());
            	int x = Integer.parseInt(st.nextToken());
            	int y = Integer.parseInt(st.nextToken());
            	int t = Integer.parseInt(st.nextToken());
            	int d = Integer.parseInt(st.nextToken());
            	microList.add(new Micro(x, y, t, d));
            }
            
            sb.append("#").append(test_case).append(" ").append(solve()).append('\n');
        }
          
        System.out.println(sb);
    }
     
    static int solve() {
    	while (M-- > 0) {
    		move();
    		Collections.sort(microList);
    		checkPlace();
    	}
    	
    	int ans = 0;
    	for (Micro micro : microList)
    		ans += micro.t;
        return ans;
    }
    
    static void move() {
    	for (int i = microList.size() - 1; i >= 0; i--) {
    		Micro micro = microList.get(i);
    		micro.x += dx[micro.d];
    		micro.y += dy[micro.d];
    		
    		if (micro.x == 0 || micro.y == 0 || micro.x == N - 1 || micro.y == N - 1) {
    			micro.t /= 2;
    			
    			if (micro.t == 0) {
    				microList.remove(i);
    				continue;
    			}
    			
    			if (micro.d % 2 == 1) micro.d++;
    			else micro.d--;
    		}
    	}
    }
    
    static void checkPlace() {    	
    	for (int i = 0; i < microList.size() - 1; i++) {
            Micro current = microList.get(i);
            Micro next = microList.get(i + 1);

            if (current.x == next.x && current.y == next.y) {
                current.t += next.t;    
                microList.remove(i + 1); 
                i--;                    
            }
        }
    }
}
