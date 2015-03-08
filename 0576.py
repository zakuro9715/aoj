import math 

L = input()
A = input()
B = input()
C = input()
D = input()

print int(L - max(math.ceil(float(A) / C), math.ceil(float(B) / D)))  
