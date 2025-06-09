t = 0
s = input()

expr = s[0]
for i in range(1, len(s), 2):
    expr = "(" + expr + s[i] + s[i+1] + ")"

s = "t=" + expr

ans = -2147483648

for a in range(1, 5):
    for b in range(1, 5):
        for c in range(1, 5):
            for d in range(1, 5):
                for e in range(1, 5):
                    for f in range(1, 5):
                        exec(s)
                        ans = max(ans, t)

print(ans)