# Guess The Number
"""This Is The Game In Which You Have To Guess The Number Which Is Hidden In The Code,
If You Guess It Correctly You Will Win The Game."""

print("              * Let's Play The Game Of Guessing The Number *\n             ")
print("No. Of Guesses Is Limited Only To 9\n")

#Initializing No. Of Guesses
numberofguesses = 9

#Conditions
while numberofguesses > 0:

    userinput = int(input("Guess The Number\n"))

    if userinput < 10:
        print("No,The Number Is Greater Than Your Input! Please Guess Again.")

        numberofguesses = numberofguesses - 1
        print("Number Of Guesses Remaining =",numberofguesses,"\n")

    if 10 < userinput < 18:
        print("No,The Number Is Little Greater Than Your Input! Please Guess Again.")

        numberofguesses = numberofguesses - 1
        print("Number Of Guesses Remaining =",numberofguesses,"\n")

    if userinput == 18:
        print("Congratulations!! You Won The Game.")
        break

    if 18 < userinput < 30:
        print("No,The Number Is Little Smaller Than Your Input! Please Guess Again.")

        numberofguesses = numberofguesses - 1
        print("Number Of Guesses Remaining =", numberofguesses,"\n")

    if userinput > 30:
        print("No,The Number Is Smaller Than Your Input! Please Guess Again.")

        numberofguesses = numberofguesses - 1
        print("Number Of Guesses Remaining =", numberofguesses,"\n")

if numberofguesses == 0:
    print("Sorry,You Lose The Game")