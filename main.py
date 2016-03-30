#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

from itertools import product


def nos_to_decimal(nos):
    assert isinstance(nos, str)
    n = len(nos)
    result = 0
    for i in range(n):
        c = nos[i]
        if c == "0":
            result += i + 1
        elif c == "1":
            result -= i + 1
        elif c == "2":
            result *= i + 1
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

    return max(valid, key=lambda x: x.count("0"))


def compress_file(filename):
    pass


def get_args():
    from argparse import ArgumentParser
    parser = ArgumentParser()

    parser.add_argument("input", type=str)
    parser.add_argument("--nos", action="store_true", default=False)
    parser.add_argument("--compress", action="store_true", default=False)
    parser.add_argument("--decompress", action="store_true", default=False)

    return parser.parse_args()


def main():
    args = get_args()

    if args.nos:
        print(decimal_to_nos(int(args.input)))
    else:
        print(nos_to_decimal(args.input))

    return 0


if __name__ == "__main__":
    sys.exit(main())

