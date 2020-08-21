# Armstrong Number - The Number That Is Equal To The Sum Of Cubes Of Its Digits #

try:
    userinput = int(input("Enter The Number Till You Want To Print Armstrong Numbers\n"))
    print("Armstrong Numbers Are :")

    for num in range(0, userinput):
        originalnum = num
        numstr = str(num)
        length = len(numstr)
        result = 0

        while num > 0:
            digit = num % 10
            result = result + digit ** length
            num = num // 10

        if originalnum == result:
            print(originalnum)
except Exception as e:
    print("Wrong Input")


