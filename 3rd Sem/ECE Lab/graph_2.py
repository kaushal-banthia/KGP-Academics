import matplotlib.pyplot as plt
import numpy as np

r = 10000 #10000 ohms
c = 46.91 * (10 ** -9)#46.91 nF
l = 1 #1H
f = np.linspace(1, 10**5, 10**5)
w = f*(2*np.pi)
#low pass rc
#amp = 20 * np.log10(1/((1 + r*r*w*w*c*c)**0.5))
#high pass cr
#amp = 20 * np.log10((r*c*w)/((1 + r*r*c*c*w*w)**0.5))
#low pass lr
#amp = 20 * np.log10(r/(r*r + l*l*w*w)**0.5)
#high pass rl
amp = 20 * np.log10((l*w)/(r*r + l*l*w*w)**0.5)

f_point = np.array([50, 149, 438, 1294, 3818, 11627, 25000])
vout = np.array([0.157,
0.466,
1.327,
3.154,
4.616,
4.955,
4.989
])
vin = np.array([5, 5, 5, 5, 5, 5, 5])
amp_point = 20 * np.log10(vout/vin)

fig, ax = plt.subplots()
ax.plot(f, amp, 'r')
ax.scatter(f_point, amp_point, color = 'b', s = 50)
#for i_x, i_y in zip(f_point, amp_point):
plt.text(f_point[0]+20, amp_point[0], '({}, {:.3f})'.format(f_point[0], amp_point[0]), fontsize=6)
plt.text(f_point[1]+30, amp_point[1], '({}, {:.3f})'.format(f_point[1], amp_point[1]), fontsize=6)
plt.text(f_point[2]+100, amp_point[2], '({}, {:.3f})'.format(f_point[2], amp_point[2]), fontsize=6)
plt.text(f_point[3]-1050, amp_point[3], '({}, {:.3f})'.format(f_point[3], amp_point[3]), fontsize=6)
plt.text(f_point[4]-1400, amp_point[4]-2.5, '({}, {:.3f})'.format(f_point[4], amp_point[4]), fontsize=6)
plt.text(f_point[5]-7000, amp_point[5]+1.5, '({}, {:.3f})'.format(f_point[5], amp_point[5]), fontsize=6)
plt.text(f_point[6]+5000, amp_point[6]+1, '({}, {:.3f})'.format(f_point[6], amp_point[6]), fontsize=6)

plt.xscale('log')
plt.xlabel('Frequency (Hz)')
plt.ylabel('20log(Vout/Vin)')
plt.title('Frequency Response for High Pass RL Filter')
plt.legend(['Theoretical', 'Observed'])
props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)
ax.text(0.05, 0.80, 'R = 10000 Ω\nL = 1 H', transform=ax.transAxes, fontsize=14,
        verticalalignment='top', bbox=props)
plt.grid()
plt.show()
