a  = [108, 107, 126, 102, 107, 104, 7, 24, 26, 24, 28]
b = []
for i in range(0,11):
    b.append(a[i]^42)
print(b)
results = bytes(b).decode("ascii")
print(results)