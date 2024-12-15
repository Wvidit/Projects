import tensorflow as tf
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense
model = Sequential([
    Dense(units = 25, activation = 'sigmoid')
    Dense(units = 15, activation = 'sigmoid')
    Dense(units = 1, activation = 'sigmoid')
])

from tensorflow.keras.losses import BinaryCrossentropy

model.compile(lss = BinaryCrossentropy)

model.fit(X, Y, epoch = 1000)