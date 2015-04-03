import pymongo
from pymongo import MongoClient
import copy
client = MongoClient()
import itertools


a = "Samsung LED TV";
x  = a.split(" ");
db = client.crawler
collection = db.flipkart


combi =[]
for i in range(2, len(x)+1):
	for j in itertools.combinations(x,i):
		combi.append(list(j))


print combi
print "\n\n\n\n"


j= len(combi)
z = []
inter= []
k=0
for b in combi:
    x = collection.find({'keywords' : {'$all' : b }})
    z.append(list(x))

k=0
for i in z:
    print ("Intersection result for "+ str(combi[k]) + "  combination is :\n\n")
    print i
    k=k+1
    xx = raw_input()
