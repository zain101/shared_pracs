from time import *;
import time
from pylab import *
x = range(1000,10001,250);
y = range(1,38);

def selection_sort(b):
    size = len(b)
    for i in range(size):
         min = b[i];
         for j in range(i+1,size):
             if(b[i] > b[j]):
                 tmp = b[i];
                 b[i] = b[j];
                 b[j] = tmp;


def call_that():
    z =0;
    n=1000;
    y = range(1,38);
    while n <= 10000:
        s =time.clock();
        b=range(n,0,-1);
        selection_sort(b);
#	merge_sort(b);   
        t= time.clock() - s
        y[z] =t;
        z,n = z+1 ,n+250; 
    return y

y = call_that();
#print y
plot(x,y,'ro-')
xlabel('no of iterations');
ylabel('time in seconds');
show();

