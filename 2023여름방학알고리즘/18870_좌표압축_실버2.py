import sys
n=int(sys.stdin.readline())
origin=list(map(int, input().split()))
new=sorted(list(set(origin)))
'''
for i in origin:
    print(new.index(i),end=" ") #.index의 빅오가 n이라 시간초과
'''
dic={new[i]: i for i in range(len(new))}
for i in origin:
    print(dic[i],end=" ")