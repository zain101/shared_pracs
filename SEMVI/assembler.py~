#!/bin/python


import  shelve
from file2list import *
from op_pot import *
from global_var import *
import os


LC = 0
L= 0
base= 0
index = 0
tmp= []
first_occurance = 1
program_label= ""
same_line= 1
a= []
z= []
skip= 0
flag = False
	

s = shelve.open("table.dat")
s["mot"]= []
s["pot"]= []
s["symbol"]= []
s["literal"]= []
s["base"]= []
s.sync()


def maketables():
	print ("preparing tables.................................................")
	s= shelve.open("table.dat")
	s["mot"]= [{"A": "1", "LEN": "4", "value" : "001011"}, {"S": "1", "LEN": "4", "value": "0001001"}, {"L": "1", "LEN": "4", "value": "0001001"}, {"ST": "1", "LEN": "4", "value": "0001001"}]
	s["pot"]= [{"DS": "1"},{"START": "1"}, {"DC": "1"}, {"EQU": "1"}, {"USING": "1"}, {"DROP": "1"}, {"END": "1"}]
	s["symbol"]= []
	s["literal"]= []
	s["base"]= []

	s.sync()
	a= s["pot"]
	
def display(a):
	s = shelve.open("table.dat")
	if (a == "symbol"):
		z= s[a]
		for i in z:
			i["value"]= 0
			print i
	else:
		z= s[a]
		for i in z:
			print i	

def conv2format(prog):
    l= []
    s= ''
    for z in prog:
        s= z
        s= s.split()
        l.append(s)
    return l
    
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

def isMot(v):
		x = []
		s = shelve.open("table.dat")
		a= s["mot"]
		for x in a:
			if v in x:
				print "mot " + v
				return True
		return False

def isLit(v):
    return False

def isSym(v):
	pass

def workForMot(z):
	global flag
	global LC
	if(flag):
		LC = LC+4
	flag= True
   
def valueForMot(z):
	x = []
	s = shelve.open("table.dat")
	a= s["mot"]
	for x in a:
		if z in x:
			return x["value"]
			   
def workForLit(z):
    pass


def workForSym(z):
	str= ""
	val= 0
	global a
	global first_occurance, LC
	s= shelve.open("table.dat")
	if (first_occurance == 1):
		if(a[1]== 'DC'):
			str = a[2]
			if(str[0]== 'F'):
				LC= LC+ 4
				skip= 2	
				val = str[2]
				
		elif(a[1]== 'DS'):
			str= a[2]
			if(True):
				LC= LC+4
				skip= 2
				val= str[0]+str[1]	
		insert_in_table("sym", z, val);	
		
		
		
    	
def insert_in_table(str, z, val):
	global LC
	if(str == "sym"):
		s= shelve.open("table.dat")	
		s["symbol"]+= [{"name":z, "LC":LC, "value": val}]
		s.sync()
	    	
def valueOfSymbol():
	pass
	
def pass1(read):
	global LC
	global first_occurance
	global a
	global z
	global skip
	for a in read:
		tmp = a
		first_occurance= 1
		i= 0
		for z in a:
			i= i+1
			if(i == 2):
				first_occurance= 0
			if(skip != 0):
				skip= skip-1
			elif(z == ','):
				pass	
			elif(isPot(z)):
				workForPot(z)
			elif(isMot(z)):
				workForMot(z);
			elif(isLit(z)):
				pass
			else:
				workForSym(z)
			

def valueFor(z):
	s= shelve.open("table.dat")
	c = s["symbol"]
	for i in c:
		if z in i.values():
			return i["value"]
	else:
		return z[2]
	
def pass2(read):
	global LC
	global first_occurance
	global a
	global z
	global skip
	tmp1 = 0
	file2= open('output.txt', 'w')
	out= []	
	for a in read:
		tmp = a
		out+= ["\n"]
		first_occurance= 1
		i= 0
		tmp = str(LC)
		out += [tmp+ '  ']
		for z in a:
			try:
				tmp1 = int(z)
			except ValueError:
				pass
			i= i+1
			if(i == 2):
				first_occurance= 0
			if(skip != 0):
				if(type(tmp1) == int):
					tmp1 = bin(tmp1)
					out+= [tmp1[2:]]
				elif(z==','):
					out+= [' ']
				else:
					out+= [z+' ']
				skip= skip-1
			elif(z == ',' or z == '1' or z == 'R1'):
				if(z==','):
					out+= [' ']
				else:
					out+= [z+' ']	
			elif(isPot(z)):
				workForPot(z)
				out+= [z+' ']
			elif(isMot(z)):
				workForMot(z);
				z = valueForMot(z);
				out+= [z+' ']
			elif(isLit(z)):
				pass
			else:
				workForSym(z)
				if(first_occurance == 1):
					out+=  ['']
				else:
					z= valueFor(z)	
					z = int(z)
					z = bin(z)
					z= str(z)				
					out+= [z[2:]+' ']
				first_occurance= 0
	file2.writelines(out);
	file2.close()

if __name__ == "__main__":
	os.system("clear")
	s= shelve.open("table.dat")	
	prog = file2list("zain")
	print prog
	prog = conv2format(prog)
	print prog
	maketables()
	print "\n MOT TABLE..........................................\n"
	display("mot")
	print "\n POT TABLE..........................................\n"
	display("pot")
	print("\n\npress enter to begin pass 1 ")
	q= raw_input()
	print "\nPASS 1 .............................................\n"
	pass1(prog)
	print "\n\nIntermidiate result symbol-table, base-table, LC {press enter} \n"
	q= raw_input()
	display("symbol")
	print "\nbase-table\n"
	print s["base"]
	print "location counter",LC
	print("\n\npress enter to begin pass 2 ")
	q= raw_input()
	LC = 0
	print "\nPASS 2 .............................................\n"
	pass2(prog)
	s["base"]+= [{"base": base}]
	print("\n\nProgram successfully executed press enter to view tables and assembled file\n")
	q= raw_input()
	print "\n\nSYMBOL TABLE .............................................\n"	
	tmp= s["symbol"]
	for a in tmp:
		print a
	print "\n\nBASE TABLE .............................................\n"
	print s["base"]
	print "\n\nLOCATION COUNTER .............................................\n"
	print LC-4
	print "\n\nInput File.............................................\n"
	os.system("cat zain")
	print "\n\n Assembled File.............................................\n"	
	os.system("vim output.txt")
	print ""
	s.close()
