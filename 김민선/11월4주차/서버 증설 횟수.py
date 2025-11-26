def solution(players, m, k):
    answer = 0
    server_count = 0 # 증설 횟수
    server_list = [] # 서버 리스트, 증설된 서버의 수 = size로
    
    for i in range(24):
        # for s in server_list:
        #     s-=1 # 복사본이라 원본이 -1이 안됨.
        #     if s==0:
        #         server_list.pop(0) # 중간에 pop하면 꼬임. 
        #         server_count-=1
        # 해결방법: 뒤에서부터 순회해서 pop하면 이미 지나간 인덱스라 제거해도 순회 안꼬임
        for idx in range(len(server_list)-1, -1, -1):
            server_list[idx] -= 1
            if server_list[idx] == 0:
                server_list.pop(idx)
                        
#         if i == 0:
#             diff = players[0]
#             if diff > m:
#                 while(1):
#                     answer+=1
#                     server_list.append(k)
#                     server_count +=1
#                     print(f"1: ")
#                     if server_count*m < players[i] or (server_count+1)*m < players[i]:
#                         break
                    
#         else:
#             diff = players[i]-players[i-1]
#             if diff > m:
#                 while(1):
#                     answer+=1
#                     server_list.append(5)
#                     server_count +=1
#                     if server_count*m < players[i] or (server_count+1)*m < players[i]:
#                         break

        need = players[i] // m

        if need > len(server_list):
            add = need - len(server_list)  # 더 필요한 서버 수
            answer += add
            for _ in range(add):
                server_list.append(k)

                
    return answer