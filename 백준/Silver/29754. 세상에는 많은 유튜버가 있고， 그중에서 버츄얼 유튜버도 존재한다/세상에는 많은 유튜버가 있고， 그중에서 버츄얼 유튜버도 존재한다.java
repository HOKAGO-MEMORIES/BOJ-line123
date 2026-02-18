import java.io.*;
import java.util.*;

public class Main {

    static class Broadcast {
        int day, startTime, endTime;
        Broadcast(int day, int startTime, int endTime) {
            this.day = day;
            this.startTime = startTime;
            this.endTime = endTime;
        }
    }

    static int M;
    static Map<String, List<Broadcast>> youtubers = new HashMap<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int day = Integer.parseInt(st.nextToken());
            int startTime = timeToMin(st.nextToken());
            int endTime = timeToMin(st.nextToken());

            if (!youtubers.containsKey(name))
                youtubers.put(name, new ArrayList<>());
            youtubers.get(name).add(new Broadcast(day, startTime, endTime));
        }

        solve();
        System.out.println(sb);
    }

    static int timeToMin(String time) {
        String[] parts = time.split(":");
        int hour = Integer.parseInt(parts[0]);
        int minute = Integer.parseInt(parts[1]);
        return hour * 60 + minute;
    }

    static void solve() {
        List<String> realVirtualYoutubers = new ArrayList<>();

        for (String name : youtubers.keySet()) {
            List<Broadcast> history = youtubers.get(name);

            if (checkReal(history))
                realVirtualYoutubers.add(name);
        }

        if (realVirtualYoutubers.isEmpty())
            sb.append(-1);
        else {
            Collections.sort(realVirtualYoutubers);
            for (String name : realVirtualYoutubers)
                sb.append(name).append('\n');
        }
    }

    static boolean checkReal(List<Broadcast> history) {
        int totalWeeks = M / 7;

        int[] weeklyTime = new int[totalWeeks];
        int[] weeklyCount = new int[totalWeeks];

        for (Broadcast broadcast : history) {
            int idx = (broadcast.day - 1) / 7;
            weeklyTime[idx] += (broadcast.endTime - broadcast.startTime);
            weeklyCount[idx]++;
        }

        for (int i = 0; i < totalWeeks; i++)
            if (weeklyTime[i] < 3600 || weeklyCount[i] < 5)
                return false;

        return true;
    }
}
