from sys import stdin
import math


def exp(a,x):
    if x == 1 :
        return a
    elif x%2 == 1 :
        return exp(a,x-1)*a
    else:
        dp = exp(a,x/2)
        return dp*dp



def process(line) :

    t,a,b = map(int,line.split())
    digit = int(math.log10(t)*(a-b))

    if t==1 or a%b != 0 :
        print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits." % (t, a, t, b))

    elif digit >= 102 :
        print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits." % (t, a, t, b))


    elif a==b :
        print("(%d^%d-1)/(%d^%d-1) 1" % (t,a,t,b))

    else :

        sum = (exp(t,a)-1) // (exp(t,b)-1)
        ok = int(math.log10(sum))
        ok += 1
        if ok < 100 :
            print("(%d^%d-1)/(%d^%d-1) %d" % (t, a, t, b,sum))
        else :
            print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits." % (t, a, t, b) )



for line in stdin :
    process(line)



