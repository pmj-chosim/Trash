import sys

n,m=map(int, input().split(" "))
list=[]
for i in range(n):
    me=sys.stdin.readline().replace("\n","")
    list.append(me)

for j in range(m):
    input=sys.stdin.readline().replace("\n","")
    if input.isdigit():
        print(list[int(input)-1])
    else:
        print(list.index(input)+1)