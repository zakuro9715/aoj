s = raw_input()
text = []
a = 0
while 1:
  text += raw_input().split()
  if text[len(text) - 1] == "END_OF_TEXT":
    break;
for t in text:
  if s == t.lower():
    a += 1
print a
