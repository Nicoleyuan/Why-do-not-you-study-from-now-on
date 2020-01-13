#!/usr/bin/env python
# encoding: utf-8 
"""
#@File    : practice7-2.py
#@Author  : evy.zhang
#@Project : Training Test
#@Ide     : PyCharm
#@Time    : 2019/10/21 15:34
#@Description  ：随机产生验证码的函数
                验证码由大小写字母和数字构成
"""
import random


def generate_code(code_len=4):  # code_len 验证码长度 默认为4 可以更改
    all_chars = '01234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZASDFGHJKLPOIUYTREWQ'
    last_pos = (all_chars) - 1
    code = ''
    for _ in range(code_len):
        index = random.randint(0, last_pos)
        code += all_chars[index]
    return code  # 输出验证码


