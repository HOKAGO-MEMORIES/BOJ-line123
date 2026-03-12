import java.io.*;
import java.util.*;

public class Main
{
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static boolean[][] arr = new boolean[101][101];
	
	public static void main(String args[]) throws IOException
	{
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			st = new StringTokenizer(br.readLine());
			 
			int sx = Integer.parseInt(st.nextToken());
			int sy = Integer.parseInt(st.nextToken());
			int ex = Integer.parseInt(st.nextToken());
			int ey = Integer.parseInt(st.nextToken());
			
			for (int x = sx; x < ex; x++) {
				for (int y = sy; y < ey; y++) {
					if (!arr[x][y]) {
						arr[x][y] = true;
						sum++;
					}
				}
			}
		}
		
		System.out.println(sum);
	}
}