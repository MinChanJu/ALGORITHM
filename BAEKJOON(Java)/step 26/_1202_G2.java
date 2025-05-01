import java.io.*;
import java.util.*;

public class _1202_G2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    String input[] = br.readLine().split(" ");
    int N = Integer.parseInt(input[0]), K = Integer.parseInt(input[1]);

    PriorityQueue<Jewelry> jewelries = new PriorityQueue<>();
    for (int i = 0; i < N; i++) {
      input = br.readLine().split(" ");
      jewelries.add(new Jewelry(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
    }

    PriorityQueue<Integer> bags = new PriorityQueue<>();
    for (int i = 0; i < K; i++) {
      bags.add(Integer.parseInt(br.readLine()));
    }

    Long sum = 0L;
    PriorityQueue<Integer> capable = new PriorityQueue<>(Comparator.reverseOrder());
    for (int i = 0; i < K; i++) {
      int bag = bags.poll();
      while (!jewelries.isEmpty() && bag >= jewelries.peek().weight) {
        Jewelry jewelry = jewelries.poll();
        capable.add(jewelry.value);
      }
      if (!capable.isEmpty()) sum += capable.poll();
      else if (jewelries.isEmpty()) break;
    }

    sb.append(sum).append("\n");

    bw.write(sb.toString());
    bw.flush();
  }
}

class Jewelry implements Comparable<Jewelry> {
  public int weight, value;

  public Jewelry(int weight, int value) {
    this.weight = weight;
    this.value = value;
  }

  @Override
  public int compareTo(Jewelry jewelry) {
    if (jewelry.weight != this.weight)
      return Integer.compare(this.weight, jewelry.weight);
    return Integer.compare(jewelry.value, this.value);
  }
}