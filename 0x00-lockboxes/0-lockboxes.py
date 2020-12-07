#!/usr/bin/python3
def canUnlockAll(boxes):

    all_keys = [0]
    for box in all_keys:
        for key in boxes[box]:
            if key not in all_keys:
                if key < len(boxes):
                    all_keys.append(key)

    if len(all_keys) == len(boxes):
        return True
    return(False)
