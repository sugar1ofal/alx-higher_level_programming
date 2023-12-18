#!/usr/bin/python3

def safe_print_division(a, b):
    """Returns the division of a by b."""
    try:
        fdiv = a / b
    except (TypeError, ZeroDivisionError):
        fdiv = None
    finally:
        print("Inside result: {}".format(fdiv))
    return (fdiv)
