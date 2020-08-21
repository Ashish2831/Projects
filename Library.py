import time

class Library:

    def __init__(self, booksList, libraryName, lendDict = {}):

        self.booksList = booksList
        self.libraryName = libraryName
        self.lendDict = lendDict

    def displayBook(self):

        for book in self.booksList:
            print(book, "\n")

    def donateBook(self):

        name = input("Enter Your Name\n")
        age = int(input("Enter Your Age\n"))
        number = int(input("Enter Your Mobile Number\n"))
        userInputForBook = input("Enter The Name Of The Book\n")
        userInputForAuthor = input("Enter The Name Of The Author\n")

        self.booksList.append(f"{userInputForBook} by {userInputForAuthor}")

        with open("DonatedBooks.txt", "a") as f2:

            currentTime = time.asctime(time.localtime(time.time()))
            f2.write(f"\n\nName : {name}\nAge : {age}\nMobile Number : {number}\nDonated Book : {userInputForBook} by {userInputForAuthor}\nTime : {currentTime}")

        return f"\nThank You Very Much!!\nYou Have Successfully Donated The Book\n"

    def lendBook(self):

        name = input("Enter Your Name\n")
        age = int(input("Enter Your Age\n"))
        number = int(input("Enter Your Mobile Number\n"))
        print("Which Book You Want To Lend, Please Write In The Same Format As You Saw In The Display")
        nameOfTheBook = input("Name : ")
        authorOfTheBook = input("Author : ")
        bookUserWantsToLend = f"{nameOfTheBook} by {authorOfTheBook}"

        if f"{nameOfTheBook} by {authorOfTheBook}" not in self.booksList:

            print(f"Sorry, But The Book Is Already Received By {self.lendDict[bookUserWantsToLend]}")

        else:

            book = f"{nameOfTheBook} by {authorOfTheBook}"
            self.lendDict.update({f"{book}" : name})
            self.booksList.remove(book)

            with open("Lend.txt", "a") as f4:

                currentTime = time.asctime(time.localtime(time.time()))
                f4.write(f"\n\nName : {name}\nAge : {age}\nMobile Number : {number}\nBook : {nameOfTheBook} by {authorOfTheBook}\nTime : {currentTime}\n")
                return f"\nYou Have Successfully Received The Book\n"

    def returnBook(self):

        name = input("Enter Your Name\n")
        age = int(input("Enter Your Age\n"))
        number = int(input("Enter Your Mobile Number\n"))
        print("Which Book You Want To Return")
        nameOfTheBook = input("Name : ")
        authorOfTheBook = input("Author : ")

        self.booksList.append(f"{nameOfTheBook} by {authorOfTheBook}")

        with open("ReturnBook.txt", "a") as f6:

            currentTime = time.asctime(time.localtime(time.time()))
            f6.write(f"\n\nName : {name}\nAge : {age}\nMobile Number : {number}\nBook : {nameOfTheBook} by {authorOfTheBook}\nTime : {currentTime}\n")

        return f"\nYou Have Successfully Returned The Book\nThanks, See You Again!!\n"

if __name__ == '__main__':

    library = Library(["ULYSSES by James Joyce", "THE GREAT GATSBY by F. Scott Fitzgerald", "A PORTRAIT OF THE ARTIST AS A YOUNG MAN by James Joyce", "LOLITA by Vladimir Nabokov", "BRAVE NEW WORLD by Aldous Huxley", "THE SOUND AND THE FURY by William Faulkner", "CATCH-22 by Joseph Heller", "DARKNESS AT NOON by Arthur Koestler", "SONS AND LOVERS by D.H. Lawrence", "THE GRAPES OF WRATH by John Steinbeck","UNDER THE VOLCANO by Malcolm Lowry", "THE WAY OF ALL FLESH by Samuel Butler", "1984 by George Orwell", "I, CLAUDIUS by Robert Graves", "TO THE LIGHTHOUSE by Virginia Woolf", "AN AMERICAN TRAGEDY by Theodore Dreiser", "THE HEART IS A LONELY HUNTER by Carson McCullers", "SLAUGHTERHOUSE-FIVE by Kurt Vonnegut", "INVISIBLE MAN by Ralph Ellison", "NATIVE SON by Richard Wright"], "National")

    while True:

        try:

            userinput = int(input(f"\n**Welcome To {library.libraryName} Library**\n\n1. Press 1 To Display Available Books\n2. Press 2 To Donate Books\n3. Press 3 To Lend Books\n4. Press 4 To Return Books\n"))

            if userinput == 1:
                library.displayBook()

            elif userinput == 2:
                print(library.donateBook())

            elif userinput == 3:
                print(library.lendBook())

            elif userinput == 4:
                print(library.returnBook())

            print("Press 'C' To Continue Or Press 'E' To Exit\n" )

            userinput = input()
            userinput = userinput.upper()

            if userinput == "C":
                continue

            elif userinput == "E":
                exit()

        except Exception as e:
            print("Please Enter valid Inputs!!")