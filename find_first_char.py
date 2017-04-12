#!/usr/bin/env python

#
# Find the first non-repeating character in a string (ABCA -> B)
#
# - Function signature?
# - Trade-offs in return value (char vs. error code vs. position)
# - What type/level of parameter validation?
# - Which testing input NULL, "\0", ...
# - UCHAR_MAX vs. 256 vs. 1 << sizeof(char) * 8
# - Space vs. Time trade-off?
# - bigOh Notation O(n)
# - Extensions
#   - Input set
#   - Generic?
#
def find_first_non_repeating_char(line):
    ctrs = {}
    for ch in line:
        ctrs.setdefault(ch, 0)
        ctrs[ch] += 1

    for ch in line:
        if ctrs[ch] == 1:
            return ch
    return None

tests = [
    "A",
    "ABAA",
    "AA",
    ]

for test in tests:
    print("{} -> {}".format(test, find_first_non_repeating_char(test)))
