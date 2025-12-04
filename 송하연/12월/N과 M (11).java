import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution_1204 {
    public static void main(String[] args) {

        Scanner scanner=new Scanner(System.in);

        //n개의 숫자 중 길이가 m인 수열 만들기
        int n=scanner.nextInt();
        int m=scanner.nextInt();

        Set<Integer> set=new HashSet<>();

        //중복 제거
        for (int i=0; i<n; i++) {
            set.add(scanner.nextInt());
        }

        int[] num = set.stream().sorted().mapToInt(Integer::intValue).toArray();

        int[] result = new int[m];
        pick(0,m,num,result);

    }

    static void pick(int depth, int m, int[] num, int[] result) {
        if (depth==m) {
            for (int i=0; i<m; i++) {
                System.out.print(result[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i=0; i<num.length;i++) {
            result[depth]=num[i];
            pick(depth + 1, m, num, result);
        }
    }
}
