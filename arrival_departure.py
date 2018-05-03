lis1,lis2=[],[]
for i in range(int(raw_input())) :
	lis = raw_input().split(" ")
	lis1.append(int(lis[0]))
	lis2.append(int(lis[1]))

i=0
j=0

lis1,lis2 = sorted(lis1),sorted(lis2)
l1,l2 = len(lis1),len(lis2)

print lis1
print lis2
count=0

while i<l1 and j<l2 :
    if lis1[i] < lis2[j] :
        i+=1
        count+=1
    elif lis1[i] > lis2[j] :
        j+=1
        count-=1
    else:
        i+=1
        j+=1
        if count < 0 :
            count = 0
print count
