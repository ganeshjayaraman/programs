string = raw_input().split(" ")

lis=[]

for i in range(len(string)-1) :
	str1,str2 = string[i],string[i+1]
	f,slen1,slen2=0,len(str1),len(str2)
	for j in range(min(slen1,slen2)) :
		if ord(str1[j]) != ord(str2[j]) :
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
print lis
