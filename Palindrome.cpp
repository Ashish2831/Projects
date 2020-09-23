// FDS Group D
// Q.25) A palindrome is a string of character that‘s the same forward and backward. Typically, 
//       punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a 
//       droop” is a palindrome, as can be seen by examining the characters “poor danisina 
//       droop” and observing that they are the same forward and backward.One way to check 
//       for a palindrome is to reverse the characters in the string and then compare with them 
//       the original-in a palindrome, the sequence will be identical.Write C++ program with functions 
//          a) To print original string followed by reversed string using stack
//          b) To check whether given string is palindrome or not


#include <iostream>
#include <string.h>
#include <ctype.h>
#define MAX 50
using namespace std;

class Stack
{
    string str;
    char stk[MAX];
    int length = str.length();
    int top = -1;

public:
    void getString();
    void extractString();
    void pushData(char);
    char popData();
    void checkPalindrome();
};

void Stack ::getString()
{
    cout << "Enter The String\n";
    cin.clear();
    cin.ignore(100, '\n');
    getline(cin, str);

    cout << "\nEntered String is : \n";
    cout << str << endl;
}

void Stack ::extractString()
{
    if (str == "")
    {
        cout << "There is no string to Extract\n";
        return;
    }

    string ch = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            ch.push_back(str[i]);
        }
    }

    str = ch;
    length = ch.length();
    cout << "\nExtracted String : \n";
    cout << str << endl;

    cout << "\nReversed Extracted String : \n";
    for (int j = length - 1; j >= 0; j--)
    {
        cout << str[j];
    }
    cout << "\n";
}

void Stack ::pushData(char ch)
{
    top++;

    if (top == MAX)
    {
        cout << "Stack OverFlow\n";
    }

    else
    {
        stk[top] = ch;
    }
}

char Stack ::popData()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
    }

    else
    {

        char chr = stk[top];
        top--;
        return chr;
    }
}

void Stack ::checkPalindrome()
{
    if (str == "")
    {
        cout << "There is no string to check Palindrome\n";
        return;
    }

    int count = 0;

    for (int i = 0; i < length; i++)
    {
        pushData(str[i]);
    }

    for (int j = 0; j < length; j++)
    {
        if (tolower(str[j]) == tolower(popData()))
        {
            count++;
        }
    }

    if (count == length)
    {
        cout << "The Entered String is Palindrome\n";
    }

    else
    {
        cout << "The Entered String is Not Palindrome\n";
    }
}

int main()
{
    Stack st;
    int userInput1;
    char userInput2;

    while (true)
    {
        cout << "1. Press 1 To Get String\n2. Press 2 To Extract String\n3. Press 3 Check Palindrome\n";
        cin >> userInput1;

        while (!cin.good() >> userInput1)
        {
            cout << "Wrong Input, Please Enter Integers Only!!\n";
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\n1. Press 1 To Get String\n2. Press 2 To Extract String\n3. Press 3 Check Palindrome\n";
            cin >> userInput1;
        }

        switch (userInput1)
        {
        case 1:
            st.getString();
            break;

        case 2:
            st.extractString();
            break;

        case 3:
            st.checkPalindrome();
            break;

        default:
            cout << "Please Enter Correct Input\n";
            continue;
        }

        while (true)
        {
            cout << "\nPress 'c' To Continue And 'e' To Exit\n";
            cin >> userInput2;

            if (tolower(userInput2) == 'c')
            {
                break;
            }

            else if (tolower(userInput2) == 'e')
            {
                exit(0);
            }

            else
            {
                cout << "Please Enter Correct Input\n";
                cin.clear();
                cin.ignore(100, '\n');
                continue;
            }
        }
    }
    return 0;
}

// Output

// 1. Press 1 To Get String
// 2. Press 2 To Extract String
// 3. Press 3 Check Palindrome
// 1
// Enter The String
// Oozy rat in a Sanitary Zoo!!

// Entered String is :
// Oozy rat in a Sanitary Zoo!!

// Press 'c' To Continue And 'e' To Exit
// c
// 1. Press 1 To Get String
// 2. Press 2 To Extract String
// 3. Press 3 Check Palindrome
// 2

// Extracted String :
// OozyratinaSanitaryZoo

// Reversed Extracted String :
// ooZyratinaSanitaryzoO

// Press 'c' To Continue And 'e' To Exit
// c
// 1. Press 1 To Get String
// 2. Press 2 To Extract String
// 3. Press 3 Check Palindrome
// 3
// The Entered String is Palindrome

// Press 'c' To Continue And 'e' To Exit
// c
// 1. Press 1 To Get String
// 2. Press 2 To Extract String
// 3. Press 3 Check Palindrome
// 1
// Enter The String
// Oozy!cat@in#a$Sanitary%Zoo&..

// Entered String is :
// Oozy!cat@in#a$Sanitary%Zoo&..

// Press 'c' To Continue And 'e' To Exit
// c
// 1. Press 1 To Get String
// 2. Press 2 To Extract String
// 3. Press 3 Check Palindrome
// 2

// Extracted String :
// OozycatinaSanitaryZoo

// Reversed Extracted String :
// ooZyratinaSanitacyzoO

// Press 'c' To Continue And 'e' To Exit
// c
// 1. Press 1 To Get String
// 2. Press 2 To Extract String
// 3. Press 3 Check Palindrome
// 3
// The Entered String is Not Palindrome

// Press 'c' To Continue And 'e' To Exit
// e
