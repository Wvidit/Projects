import numpy as np
#simple defination
test = np.array([[1, 2, 3, 4, 5, 6, 7], [8, 9, 10, 11, 12, 13, 14]])

test.flags.writeable = False #Makes array test immutable

zero_matrix = np.zeros((3,2))

matrix_full_of_one = np.ones((2,3,4),dtype=np.int16)

matrix_full_of_one.dtype #Gives the data type of matrix

matrix_full_of_one.size #Gives no. of elements of matrix

test[0, :] #Gets the whole array in zeroth index

test[:, 0] #Gets the zeroth indices of all the array

test[:, 2] = [1,2]#Updates 2nd index of 2 arrays to 1 and 2 respectively

test[0, 1:6:2] #Gets element from [ index, start:end(not included):step_value]

d = np.arange( 10, 25, 5) #Matrix with step value 5, includes 10 but not 25

matrix_full_of_heil = np.full((2,2), 99, dtype='float32')

identity_matrix = np.eye(2)

random_matrix = np.random.random((3,3))
np.random.randint(start, end, order) #makes a matrix with random entries between start and end(not included) and of size order

empty_matrix = np.empty((3,2))

random_matrix.sum() #Sums the whole array

random_matrix.min() #gives minimum of array

random_matrix.max(axis = 1) # axis = 1 maximum in x-axis
random_matrix.max(axis = 0) # axis = 0 maximum in y-axis

# Assuming identical shape of the arrays and a tolerance for the comparison of values
equal = np.allclose(A,B)

# Checking both the shape and the element values, no tolerance (values have to be exactly equal)
equal = np.array_equal(A,B)


#print(test)
#print(random_matrix)
#print(random_matrix.sort(axis = 0))
#print(random_matrix.sum())


#print(a.shape)
#print(len(a))
