#! /usr/bin/env python3

import random
import string
import subprocess
from typing import Text


for _ in range(10):
	random_string = "".join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 10000)))

	myprog = subprocess.run(f"./ft_ssl {random_string}", capture_output=True, text=True, shell=True)
	sysprog = subprocess.run(f"echo -n {random_string} | md5sum", capture_output=True, text=True, shell=True)

	myresult = myprog.stdout.strip()
	sysresult = (sysprog.stdout.split())[0]

	if (myresult == sysresult):
		print(f"\033[92mSuccsses\33[0m")
		print(f"✅ usr {myresult}")
	else :
		print(f"\033[91mFail\33[0m")
		print(f"❌ usr {myresult}", end="")
	print(f"   sys {sysresult}\n")


