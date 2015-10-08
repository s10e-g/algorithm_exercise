#!/bin/env python3

if __name__ == "__main__":
    fair = [int(str(x) + str(x)[::-1])**2 for x in range(1, 100000)]
    fair.extend([int(str(x)[:-1] + str(x)[::-1])**2 for x in range(100000)])

    fs = list(filter(lambda n: str(n)[::-1] == str(n), fair))
    fs.sort()
    print(fs)
