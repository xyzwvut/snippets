#!/usr/bin/env python

def is_balanced(expression):
    """Check if the braces in an expression is balanced"""
    braces = {
        '(': ')',
        '[': ']',
        '{': '}',
        '<': '>',
    }

    result = []

    for c in expression:
        if c in braces.keys():
            # open brace
            result.append(c)
        elif c in braces.values():
            # close brace
            if len(result) == 0:
                return False
            e = result.pop()
            if braces[e] != c:
                return False
        else:
            # No brace
            continue

    if len(result) == 0:
        return True
    else:
        return False

tests = [
    "()",
    "(1)",
    "(())",
    "([])",
    "1",
    "(",
    ")",
    "([)]",
]

for test in tests:
    print("{} {}".format(test, is_balanced(test)))

