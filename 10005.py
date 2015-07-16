import os

code = """
main(){puts("Hello World");}
"""

with open('hello.c', 'w') as f:
    f.write(code)
os.system('gcc hello.c')
for i in range(1000):
    os.system('./a.out')
