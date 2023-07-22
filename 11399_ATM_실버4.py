import sys
n=int(input())
list=list(map(int, sys.stdin.readline().split(" ")))

list.sort()
s,p=0,0
for i in list:
   s+=i
   p+=s

print(p)