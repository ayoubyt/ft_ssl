import string

# with open("test.txt", "wb") as f:
#     f.write(b"AA\x00AA")

i = 0
for c in string.ascii_uppercase:
    print(f"base64map_list['{c}'] = {i};")
    i = i + 1
for c in string.ascii_lowercase:
    print(f"base64map_list['{c}'] = {i};")
    i = i + 1
for c in string.digits:
    print(f"base64map_list['{c}'] = {i};")
    i = i + 1
