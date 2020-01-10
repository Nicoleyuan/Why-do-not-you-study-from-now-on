#!/usr/bin/env python
# encoding: utf-8 
"""
#@File    : practice7-1.py
#@Author  : evy.zhang
#@Project : Training Test
#@Ide     : PyCharm
#@Time    : 2019/10/18 9:49
#@Description  ：跑马灯文字

"""

import os
import time


def main():
    content = '丢掉手表 丢外套 丢掉背包 再丢唠叨 \
    丢掉电视 丢电脑 丢掉大脑 再丢烦恼 \
    冲啥大 冲啥小 冲啥都有人唱反调 \
    恨的多 爱的少 只想越跳越疯 越跳越高 把地球甩掉'
    while True:
        # 清理屏幕上的输出
        os.system('cls')  # os.system('clear')
        print(content)
        # 休眠200毫秒
        time.sleep(0.2)
        content = content[1:] + content[0]


if __name__ == '__main__':
    main()
