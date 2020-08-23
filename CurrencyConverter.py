# Include 'Currency.txt' From Here https://codewithashishpython.blogspot.com/2020/08/currencytxt.html

with open("Currency.txt","r") as f:
    currencyList = f.readlines()

currencyDict = {}

for line in currencyList:
    parseList = line.split("\t")
    currencyDict[parseList[0]] = parseList[1]

amount = int(input("Enter The Amount\n"))
print("\nYour Available Options Are:\n")

[print(currency) for currency in currencyDict.keys()]

nameOfCurrency = input("\nEnter The Name Of Currency You Want To Convert Into From The Above Available Options\n")

print(f"{amount} USD Is Equal To {amount * float(currencyDict[nameOfCurrency])} {nameOfCurrency}")