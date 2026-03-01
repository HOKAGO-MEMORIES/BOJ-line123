import java.io.*;
import java.util.*;

public class Main {

    static class Point implements Comparable<Point> {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (this.x == o.x) return this.y - o.y;
            return this.x - o.x;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Point[][] points = new Point[2][2];
        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 2; j++)
                points[i][j] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(points[0]);
        Arrays.sort(points[1]);

        System.out.println(solve(points));
    }

    static int solve(Point[][] points) {
        int ccw1 = ccw(points[0][0], points[0][1], points[1][0]);
        int ccw2 = ccw(points[0][0], points[0][1], points[1][1]);
        int ccw3 = ccw(points[1][0], points[1][1], points[0][0]);
        int ccw4 = ccw(points[1][0], points[1][1], points[0][1]);

        if (ccw1 != ccw2 && ccw3 != ccw4)   return 1;
        if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0)
            if (points[1][0].compareTo(points[0][1]) <= 0 && points[0][0].compareTo(points[1][1]) <= 0 )
                return 1;
        return 0;
    }

    static int ccw(Point a, Point b, Point c) {
        long cross = (long) (b.x - a.x) * (c.y - a.y) - (long) (c.x - a.x) * (b.y - a.y);
        if (cross > 0) return 1;
        else if (cross == 0) return 0;
        else return -1;
    }
}
