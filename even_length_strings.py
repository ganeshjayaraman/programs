get = raw_input().split(" ")

dic={}
dic2={}
i=0
for x in get :
	if not x in dic :
		if len(x)%2 == 0 :
			dic[x] = [1,i]
			#dic2[x] = i
	else :
		if len(x)%2 == 0 :
			dic[x][0] += 1
	i+=1

maxi=0
store=str
for k in dic :
	if dic[k][0] > maxi :
		store = k
		maxi = dic[k][0]
	elif dic[k][0] == maxi :
		if dic[k][0] < dic[store][0] :
			store = k
			maxi = dic[k][0]
if maxi == 0 :
        print "00"
else :        
        print maxi,store
