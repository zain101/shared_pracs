#!/bin/bash

def file2list(filename):
    fp = open(filename, 'r')
    whole = fp.read()
    s= ''
    l = []
    for a in whole:
      if( a == '\n'):
        l.append(s)
        s= '';
      if (a != '\n'):
        s += a
    fp.close()
    return l

if __name__ == "__main__":
    z = file2list("zain");
    print z
