store=raw_input().split(" ")
lis = raw_input().split(" ")
lis = map(int,lis)
mat = [[0 for x in range(len(store[i])) ] for i in range(len(store)) ]
i=0

for x in store :	
	for j in range(len(x)) :
		mat[i][j] = ord(x[j])
	i+=1

mini = 10000000000000
maxi_len,maxi_pos = 0,0
for x in mat :
	if len(x) < mini :
		mini = len(x)

i=0
for x in mat :
	if len(x) > maxi_len :
		maxi_len = len(x)
		maxi_pos = i
	i+=1
	
store=[]
f=0
isset = 0
for j in range(mini) :
    maxi=mat[0][j]
    for i in range(1,len(mat)) :
        if i not in store :
            if mat[i][j] > maxi :
                if not isset :                        
                    s = store.pop
                    isset = 1
                store.append(i)
                f=1
                break

if not f :
    print maxi_pos
else :
    print store
    print store == lis
