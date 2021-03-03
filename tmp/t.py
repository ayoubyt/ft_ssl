import re

s = """
[ABCD  0  6 49]
[DABC  7 10 50]
[CDAB 14 15 51]
[BCDA  5 21 52]
[ABCD 12  6 53]
[DABC  3 10 54]
[CDAB 10 15 55]
[BCDA  1 21 56]
[ABCD  8  6 57]
[DABC 15 10 58]
[CDAB  6 15 59]
[BCDA 13 21 60]
[ABCD  4  6 61]
[DABC 11 10 62]
[CDAB  2 15 63]
[BCDA  9 21 64]
"""

s = re.sub(r"[\[\]]", "", s)
a1 = s.lower().split("\n")
a1 = [e.split() for e in a1 if e]

for e in a1:
	e[0] = ", ".join(["c->" + ee for ee in list(e[0])])
	e[1] = f"c->buff[idx * 64 + {e[1]}]"
	e[3] = f"g_t[{int(e[3]) - 1}]"


for e in a1:
	print(f"R4O({', '.join(e)});")
