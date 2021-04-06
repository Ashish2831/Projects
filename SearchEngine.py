def matching(userSentence, givenSentence, match):

    userSentence = userSentence.split()
    givenSentence = givenSentence.split()

    for word1 in userSentence:
        for word2 in givenSentence:
            if word1.lower() == word2.lower():
                return True


if __name__ == '__main__':

    Sentences = ["ULYSSES by James Joyce", "THE GREAT GATSBY by F. Scott Fitzgerald", "A PORTRAIT OF THE ARTIST AS A YOUNG MAN by James Joyce", "LOLITA by Vladimir Nabokov", "BRAVE NEW WORLD by Aldous Huxley", "THE SOUND AND THE FURY by William Faulkner", "CATCH-22 by Joseph Heller", "DARKNESS AT NOON by Arthur Koestler", "SONS AND LOVERS by D.H. Lawrence", "THE GRAPES OF WRATH by John Steinbeck","UNDER THE VOLCANO by Malcolm Lowry", "THE WAY OF ALL FLESH by Samuel Butler", "1984 by George Orwell", "I, CLAUDIUS by Robert Graves", "TO THE LIGHTHOUSE by Virginia Woolf", "AN AMERICAN TRAGEDY by Theodore Dreiser", "THE HEART IS A LONELY HUNTER by Carson McCullers", "SLAUGHTERHOUSE-FIVE by Kurt Vonnegut", "INVISIBLE MAN by Ralph Ellison", "NATIVE SON by Richard Wright"]
    
    userinput = input("Please Input Your Query String\n")

    match = 0
    userList = []
    givenList = []

    for i in range(len(Sentences)):

        count = False
        count = matching(userinput, Sentences[i], match)

        if count == True:
            userList.append(userinput)
            givenList.append(Sentences[i])
            match = match + 1

    print(match, "Results Found")

    allMatches = dict(zip(givenList, userList))
    for key in allMatches:
        print(f"'{key}' Matches With UserInput Query '{allMatches[key]}'")
