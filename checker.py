#!/bin/python3

"""
Check the sanity of test cases.
"""

import os
import sys

BEGIN = 1001  # The first line that checker should read
END = 4002  # The last line that checker should read
CASE = "RandomGeneratorNegRel-20"  # The case that checker should read

# open 'build/RandomGenerator-20-case.txt'
with open(os.path.join(os.getcwd(), 'build', CASE+'-case.txt'), 'r') as f:
    lines = f.readlines()
    items = []
    for line in lines[BEGIN:END]:
        # Split the line by ' ', get a list of strings
        floats = line.strip().split(' ')
        if len(floats) < 3:
            print("Pass 1 line")
            continue
        # Convert the strings to floats
        floats = [float(x) for x in floats]
        items.append(floats)

    # Check if there exists two items can fit in a bin
    # "fit in a bin" means that for each dimension, the sum of the two items is less than 1
    for i in range(len(items)):
        for j in range(i + 1, len(items)):
            # first check that they are the same dimension
            if len(items[i]) != len(items[j]):
                print("Error: two items have different dimensions")
                sys.exit(1)
            fit = True
            # check if they can fit in a bin
            for k in range(len(items[i])):
                if items[i][k] + items[j][k] > 1:
                    fit = False
                    break
            if fit:
                print(f"Find two items can fit in a bin, which are {i} and {j}")
                sys.exit(0)
    print("No two items can fit in a bin")
