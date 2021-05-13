a,b,c = map(int, input().split())
ab = b-a-1
bc = c-b-1
if ab < bc:
    print(bc)
else:
    print(ab)
