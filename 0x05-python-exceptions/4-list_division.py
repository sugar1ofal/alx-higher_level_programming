#!/usr/bin/python3

def list_division(my_list_1, my_list_2, list_length):
    """Divides two lists element by element.

    Args:
        my_list_1 (list): The first list.
        my_list_2 (list): The second list.
        list_length (int): The number of elements to divide.

    Returns:
        A new list of length list_length containing all the divisions.
    """
    fnew_list = []
    for f in range(0, list_length):
        try:
            fdiv = my_list_1[f] / my_list_2[f]
        except TypeError:
            print("wrong type")
            fdiv = 0
        except ZeroDivisionError:
            print("division by 0")
            fdiv = 0
        except IndexError:
            print("out of range")
            fdiv = 0
        finally:
            fnew_list.append(fdiv)
    return (fnew_list)
