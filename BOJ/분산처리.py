
def lastcomputer(n,k):
    a = 1
    if k==0: 
        k=4
    for _ in range(k):
        a*=n
        a%=10
    return a
    
n=int(input())
while n:
    n-=1
    a,b = map(int, input().split())
    if a%10==0:
        print(10)
    else:
        temp = b % 4
        print(lastcomputer(a, temp))
