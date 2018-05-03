import numpy as np
from lightfm.datasets import fetch_movielens
from lightfm import LightFM
import scipy.sparse as sp

i=0
data = fetch_movielens(indicator_features=True, genre_features=True)

print data
'''
model = LightFM(loss='warp')
#train model
model.fit(data['train'], epochs=30, num_threads=2)


pos_values_for_a_user =  data["item_labels"][data["train"].tocsr()[942].indices]

#print data["train"].tocsr()[24].shape

scores = model.predict(942,np.arange(data["train"].shape[0]))

top_items = data["item_labels"][np.argsort(-scores)]

top_N = [str(x) for x in top_items[:5]]

print top_N

for x in top_items[:5] :
	print x

for i in range(len(top_items)) :    
    print top_items[i], i,
    for j in range(len(top_items)) :
        if top_items[i] == data["item_labels"][j] :
            print data["item_labels"][j],j
            break

        
'''
