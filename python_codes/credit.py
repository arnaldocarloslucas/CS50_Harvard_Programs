from cs50 import get_string
from cs50 import get_int
import math

# Prompt the user for the credit card number
# and check if is a number greater than 0
check = False
while (check == False):
    cn = input("Number: ")
    try:
        cn = int(cn)
        if (cn > 0):
            check = True
    except:
        check = False

lenght = len(str(cn))

sum1 = int(0)
sum2 = int(0)
cn_aux = int(cn)

check2 = False
while (check2 == False):

    digit1 = (cn_aux % 10)
    sum1 = (sum1 + digit1)
    cn_aux = int(cn_aux / 10)
    digit2 = (cn_aux % 10)
    digit2 = (digit2 * 2)

    if (digit2 >= 10):
        digit21 = (digit2 % 10)
        digit22 = int(digit2 / 10)
        digit2 = (digit21 + digit22)
        sum2 = (sum2 + digit2)
        cn_aux = int(cn_aux / 10)
    else:
        sum2 = (sum2 + digit2)
        cn_aux = int(cn_aux / 10)

    if (cn_aux == 0):
        check2 = True

check_sum = (sum1 + sum2)
is_zero = (check_sum % 10)

dic_master = {51, 52, 53, 54, 55}
dic_amex = {34, 37}

if (is_zero == 0):
    if (lenght == 13 or lenght == 16):
        if (lenght == 13):
            visa = int(cn / pow(10, 12))
            if (visa == 4):
                print("VISA")
            else:
                print("INVALID")
        elif (lenght == 16):
            visa = int(cn / pow(10, 15))
            master = int(cn / pow(10, 14))
            if (visa == 4):
                print("VISA")
            elif master in dic_master: 
                print("MASTERCARD")
            else:
                print("INVALID")
    elif (lenght == 15):
        amex = int(cn / pow(10, 13))
        if amex in dic_amex: 
            print("AMEX")
        else:
            print("INVALID")
else:
    print("INVALID")
