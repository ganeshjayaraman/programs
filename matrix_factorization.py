import numpy as np
from scipy.sparse import csr_matrix


genre = ["action","thriller","comedy","adventure","romance","horror","fantasy","drama","sports","crime"]

movies = [1,2,3,4,5,6,7,8,9,10,11]

movies_detail = {
    1 : ["action","thriller"],
    2 : ["comedy","romance","action"],
    3 : ["comedy","fantasy"],
    4 : ["drama","sports"],
    5 : ["fantasy","romance","sports","crime"],
    6 : ["action","crime","comedy"],
    7 : ["comedy"],
    8 : ["drama","romance"],
    9 : ["crime"],
    10: ["horror","crime"],
    11: ["comedy","romance","action"]
    }

#ratings = [7.2,6.3,9.0,4.5,9.0,3.8,2.9,6.9,8.5,5.5]

len_movies,len_genre,genre_weights = len(movies), len(genre),[]

one_hot = [[0 for x in range(len_genre)] for y in range(len_movies)]
#print len(one_hot[0])
print len(one_hot)
#one hot encoding 
for i in range(len(movies)) :    
    lis = movies_detail[i+1]    
    for j in range(len(genre)) :
        if genre[j] in lis :
           one_hot[i][j]=1
        else :
            one_hot[i][j]=0

for i in range(len_genre) :
    cost=0
    for j in range(len_movies) :
        if one_hot[j][i] == 1 :
            cost +=1
    #print cost/float(len_movies),i,j
    genre_weights.append(cost/float(len_movies))

#print one_hot[1]
#print one_hot[10]
len_genre_weights = len(genre_weights)
u = np.zeros(shape=(len_movies,len_genre_weights), dtype=np.float32)
s = np.zeros(shape=(len_genre_weights,len_genre_weights), dtype=np.float32)
v = np.zeros(shape=(len_genre_weights,len_genre), dtype=np.float32)
estimate = np.zeros(shape=(1,len_genre), dtype=np.float32)

for i in range(len(u)) :
    for j in range(len(u[i])) :        
        if genre[j] in movies_detail[i+1] :
            u[i][j] = 1.0
        else :
            u[i][j] = 0.0

for i in range(len_genre_weights) :
    for j in range(len_genre_weights) :
        if i == j :
            s[i][j] = genre_weights[i]
        else :
            s[i][j] = 0.0

for i in range(len(v)) :
    for j in range(len(v[i])) :
        if genre[j] in movies_detail[i+1] :
            v[i][j] = 1.0
        else :
            v[i][j] = 0.0

u = csr_matrix(u)
s = csr_matrix(s)
v = csr_matrix(v)
                 
#temp = np.multiply(u,np.multiply(s,v))

temp = u[1,:]*(s*v)

#print temp

estimate[0,:] = temp.todense()

recom = (-estimate[0, :]).argsort()[:5]

print [movies[r] for r in recom]

