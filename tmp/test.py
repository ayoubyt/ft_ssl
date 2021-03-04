#! /usr/bin/env python3

import random
import string

random_string = "".join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 10000)))

print(random_string)