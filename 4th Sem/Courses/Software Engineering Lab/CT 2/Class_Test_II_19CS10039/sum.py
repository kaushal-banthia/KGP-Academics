import numpy as np
from datetime import datetime
import random

a = []
for i in range(100000):
    a.append(random.random())

time = datetime.now()
b = [i + 1 for i in a]
print(datetime.now() - time)
c = np.array(a)
time = datetime.now()
d = c + 1
print(datetime.now() - time)