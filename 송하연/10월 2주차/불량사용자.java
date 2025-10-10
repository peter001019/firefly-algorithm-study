import java.util.*;

class Solution {
    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        
        Set<Set<String>> result = new HashSet<>();
        List<List<String>> candidate = new ArrayList<>();
        
        for(int i=0; i<banned_id.length; i++){
            List<String> list = new ArrayList<>(); //각각의 ban에 매핑되는 user 저장
            
            for(int j=0; j<user_id.length; j++){
                if(banned_id[i].length()!=user_id[j].length()) continue;
                else{
                    if(isMatch(user_id[j],banned_id[i])) list.add(user_id[j]);
                }
            }
            candidate.add(list);
        }
        dfs(0,candidate,new HashSet<>(),result);
        return answer=result.size();
    }
    
    boolean isMatch(String user, String ban){
        boolean result = true;
        for(int i=0; i<user.length(); i++){
            if(ban.charAt(i)=='*') continue;
            if(user.charAt(i)!=ban.charAt(i)){
                result=false;
                break;
            }
        }
        return result;
    }
    
    void dfs(int idx, List<List<String>> candidate, Set<String> selected, Set<Set<String>> result){
        if(idx==candidate.size()){
            result.add(new HashSet<>(selected));
            return;
        }
        
        for(String user:candidate.get(idx)){
            if(!selected.contains(user)){
                selected.add(user);
                dfs(idx+1, candidate, selected, result);
                selected.remove(user);
            }
        }
    }
}
