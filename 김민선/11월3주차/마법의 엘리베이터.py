def solution(storey):
    answer = 0
    while (storey>0):
        temp = storey%10 # 일의자리
        next_d = (storey // 10) % 10 
        if temp<5:
            answer+=temp
        elif temp>5:
            answer=answer+(10-temp)
            storey+=10
        else:
            answer=answer+(10-temp)
            if next_d >= 5:
                storey+=10
        
        storey=storey//10
    return answer