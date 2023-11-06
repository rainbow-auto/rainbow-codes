f = []
f.append(1)
f.append(1)
f.append(1)

for i in range(3, 200):
    f.append(f[i - 1] - 2 * f[i - 3])

f.sort()

for i in range(0, 199):
    print (i, end=" ")
    print (f[i])
