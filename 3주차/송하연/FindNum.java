import java.util.*;

public class FindNum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        HashSet<Integer> set = new HashSet<>();

        for(int i=0; i<n; i++){
            set.add(scanner.nextInt());
        }

        for(int j=0; j<m; j++){
            int num = scanner.nextInt();
            if(set.contains(num)){
                System.out.println(1);
            }
            else{
                System.out.println(0);
            }
        }
    }
}
