#! /usr/bin/env python3

import random
import string
import subprocess
import sys
import hashlib

print("\033[96m************** md5 ***************\033[0m\n")
for _ in range(10):

	random_string = "".join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 10)))

	myprog = subprocess.run(f"./ft_ssl md5 -s {random_string} -q", capture_output=True, text=True, shell=True)

	myresult = myprog.stdout.strip()
	sysresult = hashlib.md5(random_string.encode("utf-8")).hexdigest()

	if (myresult == sysresult):
		print(f"\033[92mSuccsses\33[0m")
		print(f"✅ usr |{myresult}|")
	else :
		print(f"\033[91mFail\33[0m")
		print(f"❌ usr |{myresult}|")
	print(f"   sys |{sysresult}|\n")


print("\033[96m************** sha256 ***************\033[0m\n")
for _ in range(10):

	random_string = "".join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 10)))

	myprog = subprocess.run(f"./ft_ssl sha256 -s {random_string} -q", capture_output=True, text=True, shell=True)

	myresult = myprog.stdout.strip()
	sysresult = hashlib.sha256(random_string.encode("utf-8")).hexdigest()

	if (myresult == sysresult):
		print(f"\033[92mSuccsses\33[0m")
		print(f"✅ usr |{myresult}|")
	else :
		print(f"\033[91mFail\33[0m")
		print(f"❌ usr |{myresult}|")
	print(f"   sys |{sysresult}|\n")


