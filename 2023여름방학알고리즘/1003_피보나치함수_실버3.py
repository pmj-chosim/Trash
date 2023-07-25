import sys
x=int(sys.stdin.readline())
for i in range(x):
    n=int(sys.stdin.readline())
    if n==0:
        print("1 0")
    elif n==1:
        print("0 1")
    else:
        list0=[1,0]
        list1=[0,1]
        mege1=0
        for i in range(2,n+1):
            mege1,list0[0]=list0[0],list0[1]
            list0[1]=mege1+list0[0]
            mege1,list1[0]=list1[0],list1[1]
            list1[1]=mege1+list1[0]
        print(f"{list0[1]} {list1[1]}")