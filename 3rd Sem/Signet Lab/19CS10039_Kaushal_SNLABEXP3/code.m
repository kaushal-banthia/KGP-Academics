f = [159
250
300
400
1000
1420
1441
1460
1500
2000
5000
7500
10000
12000
]

gain = 20*log10([])

phase = []

semilogx(f, gain)
xlabel("Frequency (Hz)")
ylabel("Magnitude (dB)")

%semilogx(f, phase)
%xlabel("Frequency (Hz)")
%ylabel("Phase (deg)")


l = 0.1
c = 1e-7
r=3000
H=tf([1], [l*c r*c 1])
%bode(H)