#튜플로 했는데 시간초과 #set으로 함
n,m=map(int, input().split())

a=set()
for i in range(n):
    a.add(input())

b=set()
for i in range(m):
    b.add(input())

result=sorted(list(a&b))

print(len(result))

for i in result:
    print(i)
