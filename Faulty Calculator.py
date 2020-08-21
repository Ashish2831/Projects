#Faulty Calculator Which Will Give Wrong Output For 44+5 , 64-9 , 24*8 and 88/6

#Initializing Variables For Operator And Numbers

#Try Except Are Used For Exception Handling

try:
    First_Number = int(input("Enter The First Number\n"))
    Second_Number = int(input("Enter The Second Number\n"))
    Operator = input("Select Operator\n+\n-\n*\n/\n%\n//\n**\n")

#Conditions

    if Operator == "+":
        if (First_Number == 44 and Second_Number == 5) or (First_Number == 5 and Second_Number == 44):
            print("Answer = 54")
        else:
            print("Answer =",First_Number + Second_Number)

    elif Operator == "-":
        if First_Number == 64 and Second_Number == 9:
            print("Answer = 49")
        else:
            print("Answer =",First_Number - Second_Number)

    elif Operator == "*":
        if (First_Number == 24 and Second_Number == 8) or (First_Number == 8 and Second_Number == 24):
            print("Answer = 568")
        else:
            print("Answer =",First_Number * Second_Number)

    elif Operator == "/":
        if First_Number == 88 and Second_Number == 6:
            print("Answer = 11.11")
        else:
            print("Answer =",First_Number/Second_Number)

    elif Operator == "%":
        print("Answer =",First_Number%Second_Number)

    elif Operator == "//":
        print("Answer =",First_Number//Second_Number)

    elif Operator == "**":
        print("Answer =",First_Number**Second_Number)

except Exception as e:
    print("Wrong Input, Please Enter Valid Input.")

