import java.io.*;
import java.util.*;

public class Main {
	
	static StringBuilder sb = new StringBuilder();
	static int N;
		
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine()); 
		solve(0, "");		
		System.out.println(sb);
	}
	
	static boolean solve(int idx, String str) {
		if (idx == N) {
			sb.append(str);
			return true;
		}
		
		for (int i = 1; i <= 3; i++) {
			if (check(str + i)) {
				if (solve(idx + 1, str + i)) {
					return true;
				}
			}
		}
		
		return false;
	}
	
	static boolean check(String str) {
		int len = str.length() / 2;
		
		for (int i = 1; i <= len; i++) {
			if (str.substring(str.length() - i)
					.equals(str.substring(str.length() - i * 2, str.length() - i)))
				return false;
		}
		
		return true;
	}

}
