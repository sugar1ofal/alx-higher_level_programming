#!/usr/bin/python3

def safe_print_list(my_list=[], x=0):
    """Print x elememts of a list.

    Args:
        my_list (list): The list to print elements.
        x (int): The number of elements of my_list to print.

    Returns:
        The number of elements printed.
    """
    fet = 0
    for f in range(x):
        try:
            print("{}".format(my_list[f]), end="")
            fet += 1
        except IndexError:
            break
    print("")
    return (fet)
