import java.util.*;

class Solution {
    public String[] solution(String[] record) {        
        Map<String, String> nameMap = new HashMap<>();
        
        Queue<String[]> inOutQueue = new LinkedList<>();
        
        for(String str: record){
            String[] parts= str.split(" ");
            String cmd = parts[0];
            String uid = parts[1];
            
            if(cmd.equals("Enter")){
                String name = parts[2];
                nameMap.put(uid,name);
                inOutQueue.offer(new String[]{uid,cmd});
            } 
            
            if(cmd.equals("Leave")){
               inOutQueue.offer(new String[]{uid,cmd}); 
            }
            
            if(cmd.equals("Change")){
                String name = parts[2];
                nameMap.put(uid,name);
            }
              
        }
        
        String[] answer = new String[inOutQueue.size()];
        int cnt=0;
        
        while(!inOutQueue.isEmpty()){
            String[] inOutHistory = inOutQueue.poll();
            String name = nameMap.get(inOutHistory[0]);
            String message="";
            
            if(inOutHistory[1].equals("Enter")){
                message = name + "님이 들어왔습니다.";
            }
            if(inOutHistory[1].equals("Leave")){
                message = name + "님이 나갔습니다.";
            }
            answer[cnt] = message;
            cnt++;

        }

        return answer;
    }
}


