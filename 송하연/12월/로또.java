import java.util.Scanner;

public class Solution_1204_02 {

    static int k;
    static int[] s;
    static int[] pick=new int[6];

    public static void main(String[] args){

        Scanner scanner=new Scanner(System.in);

        while(true){
            k=scanner.nextInt(); //뽑을 개수
            s=new int[k]; //k 개수 만큼 s 숫자 뽑기
            
            for(int i=0;i<k;i++) {
                s[i] = scanner.nextInt();
            }
            dfs(0,0);
            System.out.println();
        }
    }

    static void dfs(int depth,int start){
        if(depth==6){
            for(int i=0;i<6;i++){
                System.out.print(pick[i]+" ");
            }
            System.out.println();
            return;
        }
        for(int i=start;i<k;i++){
            pick[depth]=s[i];
            dfs(depth+1,i+1);
        }
    }
}
