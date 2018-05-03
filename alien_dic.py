string = raw_input().split(" ")

dic,dic2={},{}

lis,lis1=[],[]
i=0

for x in string :
	if x[0] not in dic :
		dic[x[0]] = {}
		dic[x[0]][x] = 1
		dic2[x[0]] = 1
		i+=1
		lis1.append(x[0])
	else :
		dic[x[0]][x] = dic2[x[0]]
		dic2[x[0]] += 1

print dic

print

print dic2

for x in lis1 :
	if dic2[x] <= 1 :
		lis.append(x)
	else :
		store = dic[x].keys()
		lis.append(x)
		print len(store)
		for i in range(0,len(store)-1) :
			str1,str2 = store[i],store[i+1]			
			for j in range(len(str1)) :
				print str1[j],str2[j]
				print lis
				print
				if ord(str1[j]) != ord(str2[j]) :
					print str1[j] in lis,str2[j] in lis
					if str1[j] in lis and str2[j] not in lis:
						temp = lis.index(str1[j])
						lis.insert(temp+1,str2[j])
						print "str1"
						print lis
						print
					elif str2[j] in lis and str1[j] not in lis:
						temp = lis.index(str2[j])
						lis.insert(temp,str1[j])
						print "str2"
						print lis
						print
					elif str2[j] not in lis and str1[j] not in lis :
						lis.append(str1[j])
						lis.append(str2[j])					                    
					break

