import numpy as np
data = np.loadtxt("C:/Users/VIDIT/Desktop/Codes/Machine Learning/Data_set/PCOS_infertility.csv", delimiter = ',')
X = data[0:501, 3:6]
y = data[:, 2]
for i in range(501):
    for j in range(3):
        X[i][j] = X[i][j]/10000
def sigmoid(z):
    return 1/(1 + np.exp(-z))

def compute_cost(w, b, X, y):
    m, n = X.shape
    total_cost = 0.0
    for i in range(m):
        j_hat = (np.dot(w,X[i]))

        f_wb = sigmoid(j_hat + b)
        loss = -y[i]*np.log(f_wb) - (1 - y[i])*np.log(1 - f_wb)
        total_cost += loss/m

    return total_cost

def gradient(w, b, X, y):
    m, n = X.shape
    dj_db = 0.0
    dj_dw = np.zeros(w.shape)
    for i in range(m):

        j_hat = np.dot(w,X[i])
        f_wb = sigmoid(j_hat + b)

        dj_db += f_wb - y[i]

        for j in range(n):
            dj_dw[j] += (f_wb - y[i])*X[i][j]
    dj_dw = dj_dw/m
    dj_db = dj_db/m
    return dj_db, dj_dw

def gradient_descent(X, y, w, b, alpha, iterations):
    J_history = []
    w_history = []
    for i in range(iterations):
        dj_db, dj_dw = gradient(w, b, X, y)

        w = w - alpha * dj_dw
        b = b - alpha * dj_db

        if i < iterations:
            cost = compute_cost(w, b, X, y)
            J_history.append(cost)
            w_history.append(w)
    return w, b, J_history, w_history

a, b, c, d = gradient_descent(X, y, np.ones(3), 1,0.1, 100000)
for i in range(1,6):
    print(f"Value of J:{c[i*100 - 1]},Value of w:{d[i*100 - 1]}")
print(f"Final value of w:{a}, b:{b}")
z = np.dot(a, (data[501:, 3:6])/10000) + b
print(f"Predicted value:{z}")