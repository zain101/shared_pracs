from heapq import merge
from time import *
from pylab import *
import time

x = range(1000,10001,100);
y = range(1,92); 
def merge_sort(m):
    if len(m) <= 1:
        return m
 
    middle = len(m) / 2
    left = m[:middle]
    right = m[middle:]
 
    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))

def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        # change the direction of this comparison to change the direction of the sort
        if left[left_idx] <= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
 
    if left:
        result.extend(left[left_idx:])
    if right:
        result.extend(right[right_idx:])
    return result




def call_that():
    z =0;
    n=1000;
    y = range(1,92);
    while n <= 10000:
        s =time.clock();
        b=range(0,n,1);
	shuffle(b);        
	merge_sort(b);
#	merge_sort(b);   
        t= time.clock() - s
        y[z] =t;
        z,n = z+1 ,n+250; 
    return y

y = call_that();
plot(x,y,'ro-');
show();
