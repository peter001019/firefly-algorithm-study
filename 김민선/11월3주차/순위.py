def solution(n, results):
    answer = 0
    graph = [[None]*(n) for _ in range (n)] # 0이 false와 구분 암됨
    for i in range(len(results)):
        graph[results[i][0]-1][results[i][1]-1]=True
        graph[results[i][1]-1][results[i][0]-1]=False
        
    for k in range(n):
        for i in range(n):
            for j in range(n):
                # i가 k를 이기고, k가 j를 이기면
                if graph[i][k] and graph[k][j]:
                    # i가 j도 이기는 걸로 표시
                    graph[i][j] = True
                    graph[j][i] = False
                    
    for g in graph:
        count = 0
        # print(g)
        for i in range(n):
            if g[i]==True or g[i]==False: # 0이 false와 구분 암됨
                # print(f"count+=1")
                count +=1
        if count==n-1:
            answer+=1
    
    return answer