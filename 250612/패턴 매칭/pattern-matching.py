import re

S = input()
P = input()

r = re.compile(P)

if r.fullmatch(S):
    print("true")
else:
    print("false")