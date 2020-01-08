"""
正整数反转:
例如：将12345变成54321
"""

num = int(input('num = '))
reversed_num = 0
while num > 0:
    reversed_num = reversed_num * 10 + num % 10
    num //= 10
print(reversed_num)

#有个error：若以0结尾 反转结果开头0消失 如12340反转后是4321而不是04321

