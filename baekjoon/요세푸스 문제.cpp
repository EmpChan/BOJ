size, n=map(int,input().split())
nums=[int(x) for x in range(1,size+1)]
i=(n-1)%len(nums)
result=[]
while len(nums)>0:
    result.append(nums.pop(i))
    try:
        i=(i+n-1)%len(nums)
    except:
        pass
print("<"+str(result[0]),end="")
for i in range(1,len(result)):
    print(", "+str(result[i]),end="")
print(">")