#!/usr/bin/env python
# encoding: utf-8 
"""
#@File    : practice6-1.py
#@Author  : evy.zhang
#@Project : Training Test
#@Ide     : PyCharm
#@Time    : 2019/10/15 16:09
#@Description  ：最大公约数与最小公倍数
"""
#最大公约数
def gcd(x,y):
    (x,y) = (y,x) if x>y else(x,y)
    for factor in range(x,0,-1):
        if x % factor == 0 and y % factor == 0:
            return factor

#最小公倍数
def lcm(x,y):
    return x * y // gcd(x,y)

input('please input x:%d',x)
input('please input y:%d',y)




