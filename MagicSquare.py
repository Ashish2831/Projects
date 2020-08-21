# Group A - 7

# Write A Python Program For Magic Square.
# A Magic Square Is An n x n Matrix Of The Integers 1 to n^2 Such That The Sum Of Each Row,
# Column And Diagonal Is The Same.
# The Figure Given Below Is An Example Of Magic Square For Case n = 5.
# In This Example, The Example, The Common Sum Is 65.

#                                [[  9.  3. 22. 16. 15.]
#                                 [  2. 21. 20. 14.  8.]
#                                 [ 25. 19. 13.  7.  1.]
#                                 [ 18. 12.  6.  5. 24.]
#                                 [ 11. 10.  4. 23. 17.]]

import numpy as np

n = int(input("Enter The Value Of n\n"))
arr = np.zeros([n, n])
row = int(n / 2)
column = int(n - 1)
arr[row, column] = 1
row = row - 1
column = column + 1
for val in range(2, n*n + 1):

    if row == -1 and column == n:
        row = 0
        column = n - 2
        arr[row, column] = val

    elif row == -1:
        row = n - 1
        arr[row, column] = val

    elif column == n:
        column = 0
        arr[row, column] = val

    elif arr[row, column] != 0:
        row = row + 1
        column = column - 2
        arr[row, column] = val

    arr[row, column] = val

    row = row - 1
    column = column + 1

print(f"\nMagic Square For n = {n} :\n\n", arr)

sum = n*(n*n + 1) / 2

row = 0
column = 0
diagonalSum = 0
while row < n and column < n:
    diagonalSum = diagonalSum + arr[row, column]
    row = row + 1
    column = column + 1
print("\nThe Sum Of Left Diagonal Elements Is", int(diagonalSum), "\n")

row = 0
column = n - 1
diagonalSum = 0
while row < n and column > -1:
    diagonalSum = diagonalSum + arr[row, column]
    row = row + 1
    column = column - 1
print("The Sum Of Right Diagonal Elements Is", int(diagonalSum), "\n")

print(
    f"A Magic Square Is An {n} x {n} Matrix Of The Integers 1 to {n*n} Such That The Sum Of Each Row, Column And Diagonal Is {int(sum)}.")

# First Output #

# Enter The Value Of n
# 3

# Magic Square For n = 3 :

#  [[2. 7. 6.]
#  [9. 5. 1.]
#  [4. 3. 8.]]

# The Sum Of Left Diagonal Elements Is 15

# The Sum Of Right Diagonal Elements Is 15

# A Magic Square Is An 3 x 3 Matrix Of The Integers 1 to 9 Such That The Sum Of Each Row, Column And Diagonal Is 15.


# Second Output #

# Enter The Value Of n
# 5

# Magic Square For n = 5 :

#  [[ 9.  3. 22. 16. 15.]
#  [ 2. 21. 20. 14.  8.]
#  [25. 19. 13.  7.  1.]
#  [18. 12.  6.  5. 24.]
#  [11. 10.  4. 23. 17.]]

# The Sum Of Left Diagonal Elements Is 65

# The Sum Of Right Diagonal Elements Is 65

# A Magic Square Is An 5 x 5 Matrix Of The Integers 1 to 25 Such That The Sum Of Each Row, Column And Diagonal Is 65.
