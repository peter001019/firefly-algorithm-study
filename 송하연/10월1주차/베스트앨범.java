import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {

        Map<String, Integer> genrePlay = new HashMap<>();
        Map<String, List<int[]>> genreInfo = new HashMap<>();
        
        //장르별 정렬
        int idx=0;
        for(String genre:genres){
            genrePlay.put(genre, genrePlay.getOrDefault(genre,0)+plays[idx]);
            
            genreInfo.putIfAbsent(genre, new ArrayList<>());
            genreInfo.get(genre).add(new int[]{idx,plays[idx]});
            
            idx++;
        }
        
        List<String> sortedGenre = new ArrayList<>(genrePlay.keySet());
        sortedGenre.sort((a,b)->genrePlay.get(b)-genrePlay.get(a));
        
        //장르 내 play횟수별 정렬
        for(String genre: sortedGenre){
            List<int[]> song = genreInfo.get(genre);

            song.sort((a,b)->{
                if(a[1]==b[1]) return a[0]-b[0];
                else return b[1]-a[1];
            }); 
        }
        
        List<Integer> result = new ArrayList<>();
        
        for(String genre: sortedGenre){
            List<int[]>song = genreInfo.get(genre);
            int cnt=0;
            for(int[] s: song){
                if(cnt<2){
                    result.add(s[0]);
                    cnt++;
                }  
            }
        }
        int[] answer = result.stream().mapToInt(Integer::intValue).toArray();

        return answer;
    }
}
