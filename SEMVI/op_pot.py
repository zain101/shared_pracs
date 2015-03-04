#!/bin/python
import shelve
from global_var import *

def isPot(v):
    x = []
    s = shelve.open("table.dat")
    a= s["pot"]
    for x in a:
      if v in x:
      	print "pot "+ v
        return True
    return False

def workForPot(v):
    #print "got "+ v
    global a
    global program_label
    if(v == "start"):
    	program_label= v 
    elif(v == 'DS'):
      forDS()
    elif(v == 'DC'):
      forDC()
    elif(v == 'EQU'):
      forEQU()
    elif(v == 'USING'):
      forUSING(a)
    elif(v == 'DROP'):
      forDROP()
    elif(v == 'END'):
      forEND()

def forDS():
    pass
    
def forDC():
    pass
    
def forEQU():
    pass

def forUSING(a):
	global base
	global index
	global skip
	if(a[1]== '*'):
		index= 0
	else:
		index= a[1]
	base= a[3]
	skip= 3
	
    
def forDROP():
    pass
def forEND():
    pass
    
if __name__ == "__main__":
	pass

