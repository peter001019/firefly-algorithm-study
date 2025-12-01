import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> result = new ArrayList<>();

        //가로 m, 세로 n, 세로 x좌표, 가로 y좌표, 명령 개수
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int cmdCnt = scanner.nextInt();

        // 지도 값 초기화
        int[][] map = new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                map[i][j] = scanner.nextInt();
            }
        }

        int[] dice = {0,0,0,0,0,0}; // 위,바닥,서,동,북,남
        int[] dx = {0,0,-1,1};
        int[] dy = {1,-1,0,0};

        //시작점 초기화
        int cx = x; //행
        int cy = y; //열

        // 지도 움직이기
        //동쪽(오)은 1, 서쪽(왼)은 2, 북쪽(위)은 3, 남쪽(아래)은 4
        for(int k=0; k<cmdCnt; k++){
            int cmd = scanner.nextInt();
            int nx = cx + dx[cmd-1];
            int ny = cy + dy[cmd-1];

            //주사위는 지도의 바깥으로 이동시킬 수 없다.
            //만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

            //System.out.println("현재 위치 : " + nx + "," + ny);
            int[] rolledDice = rollDice(dice, cmd);
            //System.out.println(Arrays.toString(rolledDice));

            //이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
            //0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
            if(map[nx][ny]==0) {
                map[nx][ny] = rolledDice[1];
            }
            else {
                rolledDice[1]=map[nx][ny];
                map[nx][ny]=0;
            }
            //System.out.println("정답 :" + rolledDice[0]);
            result.add(rolledDice[0]);

            cx = nx;
            cy = ny;
        }

        for(int num:result){
            System.out.println(num);
        }

    }

    public static int[] rollDice(int[] dice, int cmd){
        // 동쪽(오): 위=서, 서=바닥, 바닥=동, 동=위
        // 서쪽(왼): 서=위, 위=동, 동=바닥, 바닥=서
        // 북쪽(위): 북=위, 위=남, 남=바닥, 바닥=북
        // 남쪽(아래): 위=북, 북=바닥, 바닥=남, 남=위

        if(cmd==1){ int temp=dice[0]; dice[0]=dice[2];  dice[2]=dice[1];  dice[1]=dice[3];  dice[3]=temp;};
        if(cmd==2){ int temp=dice[2]; dice[2]=dice[0];  dice[0]=dice[3];  dice[3]=dice[1];  dice[1]=temp;};
        if(cmd==3){ int temp=dice[4]; dice[4]=dice[0];  dice[0]=dice[5];  dice[5]=dice[1];  dice[1]=temp;};
        if(cmd==4){ int temp=dice[0]; dice[0]=dice[4];  dice[4]=dice[1];  dice[1]=dice[5];  dice[5]=temp;};

        return dice;
    }
}

