from scipy import sparse
from numpy import array
I = array([0,0,1,3,1,0,0,2,3])
J = array([0,2,1,3,1,0,0,0,0])
V = array([1,1,1,1,1,1,1,2,3])
B = sparse.coo_matrix((V,(I,J)),shape=(4,4)).tocsr()


print B
