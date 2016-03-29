#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function

import sys

from itertools import product


def nos_to_decimal(nos):
    assert isinstance(nos, basestring)
    n = len(nos)
    result = 0
    for i in xrange(1, n+1):
        c = nos[i-1]
        if c == "0":
            result += i
        elif c == "1":
            result -= i
        elif c == "2":
            result *= i
        else:
            raise RuntimeError(
                "Unknown char: {}. Expected 0, 1, or 2.".format(c))
    return result


def decimal_to_nos(num):
    i = 1
    valid = []
    while not valid:
        combos = product("012", repeat=i)
        for combo in combos:
            combo = "".join(combo)
            dec = nos_to_decimal(combo)
            if dec == num:
                valid.append(combo)
        i += 1

    return min(valid, key=lambda x: -x.count("0"))


def main():
    input_ = sys.argv[1]
    find_nos = len(sys.argv) > 2

    if find_nos:
        print(decimal_to_nos(int(input_)))
    else:
        print(nos_to_decimal(input_))

    return 0


if __name__ == "__main__":
    sys.exit(main())

