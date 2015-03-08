s = raw_input()
a = ""
for c in s:
  if c >= 'A' and c <= 'Z':
    a += c.lower()
  elif c >= 'a' and c <= 'z':
    a += c.upper()
  else: 
    a += c
print a
