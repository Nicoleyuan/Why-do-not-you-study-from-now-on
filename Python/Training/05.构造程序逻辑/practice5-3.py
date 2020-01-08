#!/usr/bin/env python
# encoding: utf-8 
"""
#@File    : practice3.py
#@Author  : evy.zhang
#@Project : Training Test
#@Ide     : PyCharm
#@Time    : 2019/10/15 14:37
#@Description  ：百钱百鸡问题
                百钱百鸡是我国古代数学家张丘建在《算经》一书中提出的数学问题：
                鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。
                百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
"""

for x in range(0,20):
    for y in range(0,33):
        z = 100 - x - y
        if 5*x + y*3 + z/3 == 100:
            print('公鸡：%d只,母鸡：%d只,小鸡：%d只' %(x,y,z))
