def solution(n):
    ans = 0
    
    while n>0:
        if n%2==0:
            # n=n/2 형변환 문제였음;;
            n=n//2
        else:
            n-=1
            ans+=1

    return ans