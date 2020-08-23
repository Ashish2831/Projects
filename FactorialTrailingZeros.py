def factorialTraingZeros(number):

    count = 0
    i = 5

    while (number // i) != 0:
        count = count + (number // i)
        i = i * 5

    print(f"No Of Trailing Zeros in {number} is",count)

if __name__ == '__main__':

    number = int(input("Enter The Number\n"))
    factorialTraingZeros(number)
