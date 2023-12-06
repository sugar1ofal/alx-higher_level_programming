#!/usr/bin/python3

def search_replace(my_list, search, replace):
    """
    A function that replaces all occurrences
    of an element by another in a new list
    """
    f_list = []
    for f in my_list:
        if f == search:
            f_list.append(replace)
        else:
            f_list.append(f)
    return f_list
