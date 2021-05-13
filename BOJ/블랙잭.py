n,m=map(int,input().split())
nums=[int(x) for x in input().split()]

maxx=0
sum=0
for i in range(0,n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):
            sum=nums[i]+nums[j]+nums[k]
            if sum <= m and sum > maxx:
                maxx=sum
print(maxx)