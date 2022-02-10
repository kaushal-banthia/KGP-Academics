import matplotlib.pyplot as plt
import numpy as np
vin = np.array([-14,
-12,
-10,
-5,
-2,
0,
2,
5,
10,
12,
14

])

vout = np.array([-12,
-12,
-10,
-5,
-2,
0,
2,
5,
10,
12,
12

])

fig = plt.figure()

ax = plt.gca()

ax.plot(vin, vout)
ax.grid(True)
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')
ax.spines['top'].set_color('none')
plt.xlabel("Vin (in V)---->")
plt.ylabel("Vout (in V)---->")
plt.title("Rf = 10kΩ")
props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)
ax.text(0, 1, 'Made by Kaushal Banthia (19CS10039)\n in Python using Matplotlib', transform=ax.transAxes, fontsize=8,
        verticalalignment='top', bbox=props)

plt.text(12, 12, '(12, 12)', fontsize = 10)
plt.text(-12, -12, '(-12, -12)', fontsize = 10)
plt.scatter([12, -12], [12, -12],  c = 'red', s = 50)
plt.show()