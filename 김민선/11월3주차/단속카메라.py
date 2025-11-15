def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1])
    i=0
    
    while i < len(routes):
        end = routes[i][1]
        i += 1
        while i < len(routes) and routes[i][0] <= end:
            i += 1
        
        answer += 1
    return answer