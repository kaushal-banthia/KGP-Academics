import matplotlib.pyplot as plt
import numpy as np

vout = np.array([0.234,
0.349,
0.461,
0.565,
0.657,
0.732,
0.798,
0.861,
0.924
])

vin = np.array([0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5])
gain = vout/vin
# magnitude = 20*np.log10(vout/0.1)
# print(magnitude)
# f = np.array([3,
# 7,
# 10,
# 15,
# 50,
# 200,
# 800,
# 10*10**3,
# 100*10**3,
# 750*10**3,
# 1*10**6,
# 5*10**6,
# 10*10**6,
# 15*10**6,
# 20*10**6,
# ])
fig, ax = plt.subplots()
plt.scatter(vin, gain, s = 30, c = 'r')
plt.plot(vin, gain, c = 'b')

# plt.plot([1, 10**8], [2.343, 2.343])
# plt.scatter([4.691, 15.66 * 10**6], [2.343, 2.343], s = 100, c = 'y')
plt.text(0.31, 2.19, '(0.30, 2.19)\nVsm = 0.30 V', fontsize = 10)
# plt.text((15.66-14)*10**6, 2.343-0.2, 'Upper Cutoff Frequency(15.66*10^6, 2.343)', fontsize = 6)
plt.xlabel('Input Voltage (in V)')
plt.ylabel('Gain')
# plt.xscale('log')
plt.title('Gain vs Input Voltage (in V) for identifying Signal Handling Capacity')
props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)
ax.text(0.15, 0.10, 'Made by Kaushal Banthia (19CS10039)\n in Python using Matplotlib', transform=ax.transAxes, fontsize=8,
        verticalalignment='top', bbox=props)
# plt.grid()
plt.show()