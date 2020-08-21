# Health Management System #

import time

userinput = int(input("Press\n1 For Brock\n2 For Roman\n3 For Dean\n"))

if userinput == 1:
    print("Do You Want Log Or Retrieve ?")
    userinputforbrock = int(input("Press\n1 For Log\n2 For Retrieve\n"))

    if userinputforbrock == 1:
        print("What Do You Want To Log For Brock ?")
        userinputforlog = int(input("Press\n1 For Diet\n2 For Exercise\n"))

        timevar = time.asctime(time.localtime(time.time()))

        if userinputforlog == 1:
            userinputfordiet = str(input("Add Diet Food\n"))
            f1 = open("Diet For Brock.txt","a")
            f1.write(timevar)
            f1.write(" - ")
            f1.write(userinputfordiet)
            f1.write("\n")
            print()
            print("Your Diet Food Added Successfully")

        if userinputforlog == 2:
            userinputforexercise = str(input("Add Exercise\n"))
            f2 = open("Exercise For Brock.txt","a")
            f2.write(timevar)
            f2.write(" - ")
            f2.write(userinputforexercise)
            f2.write("\n")
            print()
            print("Your Exercise Added Successfully.")

    if userinputforbrock == 2:
        print("What Do You Want To Retrieve For Brock ?")
        userinputforretrieve = int(input("Press\n1 For Diet\n2 For Exercise\n"))

        if userinputforretrieve == 1:
            f1 = open("Diet For Brock.txt","r")
            print(f1.read())
            print("Your Diet Food Retrieved Successfully")

        if userinputforretrieve == 2:
            f2 = open("Exercise For Brock.txt","r")
            print(f2.read())
            print("Your Exercise Retrieved Successfully.")

if userinput == 2:
    print("Do You Want Log Or Retrieve ?")
    userinputforroman = int(input("Press\n1 For Log\n2 For Retrieve\n"))

    if userinputforroman == 1:
        print("What Do You Want To Log For Roman ?")
        userinputforlog = int(input("Press\n1 For Diet\n2 For Exercise\n"))

        timevar = time.asctime(time.localtime(time.time()))

        if userinputforlog == 1:
            userinputfordiet = str(input("Add Diet Food\n"))
            f3 = open("Diet For Roman.txt", "a")
            f3.write(timevar)
            f3.write(" - ")
            f3.write(userinputfordiet)
            f3.write("\n")
            print()
            print("Your Diet Food Added Successfully")

        if userinputforlog == 2:
            userinputforexercise = str(input("Add Exercise\n"))
            f4 = open("Exercise For Roman.txt", "a")
            f4.write(timevar)
            f4.write(" - ")
            f4.write(userinputforexercise)
            f4.write("\n")
            print()
            print("Your Exercise Added Successfully.")

    if userinputforroman == 2:
        print("What Do You Want To Retrieve For Roman ?")
        userinputforretrieve = int(input("Press\n1 For Diet\n2 For Exercise\n"))

        if userinputforretrieve == 1:
            f3 = open("Diet For Roman.txt", "r")
            print(f3.read())
            print("Your Diet Food Retrieved Successfully")

        if userinputforretrieve == 2:
            f4 = open("Exercise For Roman.txt", "r")
            print(f4.read())
            print("Your Exercise Retrieved Successfully.")

if userinput == 3:
    print("Do You Want Log Or Retrieve ?")
    userinputfordean = int(input("Press\n1 For Log\n2 For Retrieve\n"))

    if userinputfordean == 1:
        print("What Do You Want To Log For Dean ?")
        userinputforlog = int(input("Press\n1 For Diet\n2 For Exercise\n"))

        timevar = time.asctime(time.localtime(time.time()))

        if userinputforlog == 1:
            userinputfordiet = str(input("Add Diet Food\n"))
            f5 = open("Diet For Dean.txt", "a")
            f5.write(timevar)
            f5.write(" - ")
            f5.write(userinputfordiet)
            f5.write("\n")
            print()
            print("Your Diet Food Added Successfully")

        if userinputforlog == 2:
            userinputforexercise = str(input("Add Exercise\n"))
            f6 = open("Exercise For Dean.txt", "a")
            f6.write(timevar)
            f6.write(" - ")
            f6.write(userinputforexercise)
            f6.write("\n")
            print()
            print("Your Exercise Added Successfully.")

    if userinputfordean == 2:
        print("What Do You Want To Retrieve For Brock ?")
        userinputforretrieve = int(input("Press\n1 For Diet\n2 For Exercise\n"))

        if userinputforretrieve == 1:
            f5 = open("Diet For Brock.txt", "r")
            print(f5.read())
            print("Your Diet Food Retrieved Successfully")

        if userinputforretrieve == 2:
            f6 = open("Exercise For Brock.txt", "r")
            print(f6.read())
            print("Your Exercise Retrieved Successfully.")





