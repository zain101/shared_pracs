#!/bin/python3
import pickle, shelve

mot = [{"add": 1, "len": 4 }, {"sub": 1, "len": 4}, {"load": 1, "len": 4}]

for a in mot:
    print(a);
    if("add" in a):
        print a.get("len")

z= ['i am\n', 'a programmer\n']
print("**************************************************************** File Operations")

file2 = open("readme.txt", "a")
file2.writelines(z)
file2.close()
file_read = open("readme.txt", "r")
whole = file_read.read()
#print(file_read.read(1))
#print(file_read.read(5))
print(whole)

file_read.close()

print("***************************************************************** Pickeling")
variety= ["sweet", "sour", "chilly"]
shape= ["whole", "spear", "chip"]
brand= ["claussen", "Heinz"]
file3 = open("pickel1.dat", "wb")
pickle.dump(variety, file3)
pickle.dump(shape, file3)
pickle.dump(brand, file3)
file3.close()

file3 = open("pickel1.dat", "rb")
v= pickle.load(file3)
s= pickle.load(file3)
b= pickle.load(file3)
file3.close()
print(v)
print(s)
print(b)

print("******************************************************************** Shelveing")
s = shelve.open("pickle2.dat")
s["variety"]= ["a", "b", "c"]
s["shape"]= ["e", "f"]

s.sync() #make sure that data is written from buffer to disk;

print("variety -", s["variety"])
print("shape -", s["shape"])
s.close()
