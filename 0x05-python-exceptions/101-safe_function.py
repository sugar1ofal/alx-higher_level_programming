#!/usr/bin/python3
from __future__ import print_function
import sys


def safe_function(fct, *args):
    try:
        fres = fct(*args)
    except Exception as f:
        print("Exception: {}".format(f), file=sys.stderr)
        return None
    else:
        return fres
