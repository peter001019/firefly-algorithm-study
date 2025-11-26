# list[a][b]=1, list[b][a]=1
# cost가 0~이므로 초기화는 list[n][n]=-1 or none

def solution(n, costs):
    answer = 0
    list = [[10000000] * n for _ in range(n)]
    costs.sort(key=lambda x: x[2]) # 비용 최소 기준으로 정리
    # count=0 # 처음에 이걸로 하려고 했으나 list초기화를 해야하니까 vis를 쓰는게 맞음
    vis = [0]*n
    i=0
    dist = [10000000] * n       # 각 정점까지 연결되는 최소 비용
    dist[0] = 0            # 0번 섬부터 시작
    for i in range(len(costs)):
        list[costs[i][0]][costs[i][1]] = min(costs[i][2], list[costs[i][0]][costs[i][1]])
        list[costs[i][1]][costs[i][0]] = min(costs[i][2], list[costs[i][1]][costs[i][0]])
        # for j in range(n):
        #     if costs[i][0]== list[j][i]:
        #         list[j][costs[i][0]] = min(cost[i][2], list[j][costs[i][0]])
        #         list[costs[i][0]][j] = min(cost[i][2], list[costs[i][0]][j])
    # for temp1 in range(n//2):
    #     for temp2 in range(n//2):
    #         answer+=list[temp1][temp2]
        # 정점 n개를 하나씩 MST에 추가
    for _ in range(n):
        u = -1
        # 아직 방문 안 한 정점 중 dist가 가장 작은 정점 u 선택
        for i in range(n):
            if not vis[i] and (u == -1 or dist[i] < dist[u]):
                u = i

        vis[u] = 1
        answer += dist[u]

        # u에서 갈 수 있는 정점들의 dist 갱신
        for v in range(n):
            if not vis[v] and list[u][v] < dist[v]:
                dist[v] = list[u][v]
    return answer