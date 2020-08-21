# Snake Water Gun Game #

import random  # Module #

print("                 ** Let's Play The Game of Snake Water Gun **                 ")
print()
print("You Have Only 10 No. of Chances To Win The Game.")
print()
no_of_chances = 10
userscore = 0
computerscore = 0

try:

    while no_of_chances > 0:

        user_input = input(
            "Press\n'S' For Snake\n'G' For Gun\n'W' For Water\nUserInput - ")
        # Computer Will Randomly Select Any Character From "SWG" #
        computer_input = random.choice("SWG")

        if user_input == computer_input:
            print("\nThe Match Is Tied , Each Gets One Point.")
            userscore = userscore + 1
            print("Your Score =", userscore)
            computerscore = computerscore + 1
            print("Computer Score =", computerscore)

        elif user_input == "S" and computer_input == "W":
            print("\nYou Won")
            userscore = userscore + 1
            print("Your Score =", userscore)
            print("Computer Score =", computerscore, "\n")

        elif user_input == "S" and computer_input == "G":
            print("\nComputer Won")
            print("Your Score =", userscore)
            computerscore = computerscore + 1
            print("Computer Score =", computerscore, "\n")

        elif user_input == "G" and computer_input == "W":
            print("\nComputer Won")
            print("Your Score =", userscore)
            computerscore = computerscore + 1
            print("Computer Score =", computerscore, "\n")

        elif user_input == "G" and computer_input == "S":
            print("\nYou Won")
            userscore = userscore + 1
            print("Your Score =", userscore)
            print("Computer Score =", computerscore, "\n")

        elif user_input == "W" and computer_input == "S":
            print("\nComputer Won")
            print("Your Score =", userscore)
            computerscore = computerscore + 1
            print("Computer Score =", computerscore, "\n")

        elif user_input == "W" and computer_input == "G":
            print("\nYou Won")
            userscore = userscore + 1
            print("Your Score =", userscore)
            print("Computer Score =", computerscore, "\n")

        elif user_input.isnumeric():
            print("Wrong Input,Please Press Only Uppercase Character.\n")

        elif user_input.islower():
            print("Wrong Input,Please Press Only Uppercase Character.\n")

        elif user_input.isdecimal():
            print("Wrong Input,Please Press Only Uppercase Character.\n")

        elif user_input.isalnum():
            print("Wrong Input,Please Press Only Uppercase Character.\n")

        no_of_chances = no_of_chances - 1

    print()
    print("Finally")
    print("Your Score Is", userscore)
    print("Computer Score Is", computerscore)

    if userscore > computerscore:
        print("\nCongratulations! You Won The Game.")

    elif userscore == computerscore:
        print("\nThe Game Is Tied.")

    else:
        print("\nSorry! You Lose The Game.")


except Exception as e:
    print("Wrong Input")
