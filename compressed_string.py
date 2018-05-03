import collections

n=""
dic={}
new_st = str(raw_input())
num,x,f=0,0,0
l=len(new_st)
while x < l :
    while x < l and ord(new_st[x]) >= 97 and ord(new_st[x]) <= 122:
        print new_st[x]
        n+=str(new_st[x])
        x+=1
        num=0
    while x<l and ord(new_st[x]) >= 48 and ord(new_st[x]) <= 57:
        print new_st[x]
        num = (num*10)+(int(new_st[x]))
        x+=1
    if n not in dic :
        dic[n] = num
    else :
        dic[n] += num
    n=""

if  ord(new_st[x-1]) >= 97 and ord(new_st[x-1]) <= 122:
    n += new_st[x-1]
    if n not in dic :
        dic[n] = 1
    else :
        dic[n] +=1
od = collections.OrderedDict(sorted(dic.items()))

expand = ""

print dic

if len(dic.keys()) == 1 :
    expand += new_st
else :
    for k,v in od.items() :
        expand += k*int(v)

l2 = len(expand)
for i in range(long(raw_input())) :
    get = long(raw_input())
    if get > l2 :
        print "-1"
    else :
        print expand[get-1]
