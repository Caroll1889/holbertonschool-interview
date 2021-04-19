#!/usr/bin/python3
"""Rain
"""


def _rain(wall, n):
    """Function that calculates how much aqua will be retained"""
    total_water = 0

    for i in range(1, n - 1):
        izq = wall[i]
        for j in range(i):
            izq = max(izq, wall[j])
        der = wall[i]
        for j in range(i + 1, n):
            der = max(der, wall[j])
        total_water = total_water + (min(izq, der) - wall[i])

    return total_water


def rain(walls):
    """Function that calculates how much water will be
    retained after it rains
    """
    ret = _rain(walls, len(walls))

    return ret
