// Shopping Club Mini Project

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <dos.h>
#include <sstream>
#include "Storage.h"
#include "Greeting.h"
#include "Sort.h"
#define PASSWORD "1234"
using namespace std;
using namespace store;
using namespace greeting;

class ShoppingClub
{
public:
    // Pure Virtual Functions
    virtual void AddProducts(ofstream &) = 0;
    virtual void DisplayProducts() = 0;
    virtual void ModifyProducts() = 0;
    virtual void DeleteProducts(int) = 0;
    virtual void Sort(int) = 0;
};

class AdministratorPortal : public Storage, public ShoppingClub
{
public:
    // Overloading IsEmpty()
    bool IsEmpty(ifstream &);
    bool IsEmpty(fstream &);
    void AddProducts(ofstream &);
    void DisplayProducts();
    void ModifyProducts();
    void DeleteProducts(int);
    void displayCustomerLists();
    void Sort(int);
};

bool compare(ForSorting fs1, ForSorting fs2)
{
    return fs1 <= fs2;
}

void AdministratorPortal::Sort(int dec)
{
    AdministratorPortal *sc;
    int quantity;
    float price;
    stringstream sso1, sso2;
    ForSorting fs;
    vector<string> vect;
    deque<ForSorting> forSorting;
    string content;
    ifstream ifile;
    ifile.open("Products.txt", ios::in);
    if (sc->IsEmpty(ifile))
    {
        cout << "\nNo Products Available!!\n";
        ifile.close();
        return;
    }

    if (ifile.is_open())
    {
        while (getline(ifile, content))
        {
            boost::split(vect, content, boost::is_any_of(",")); // split function used to split the string which is present in boost library

            stringstream sso1, sso2;
            sso1 << vect[1];
            sso2 << vect[2];
            sso1 >> quantity;
            sso2 >> price;
            fs.setter(vect[0], quantity, price);
            forSorting.push_back(fs);
        }
    }
    else
        cout << "\nError While Opening The File\n";

    ifile.close();

    if (dec == 1)
    {
        ForSorting::decide = 1;
        sort(forSorting.begin(), forSorting.end(), &compare);
    }
    else if (dec == 2)
    {
        ForSorting::decide = 2;
        sort(forSorting.begin(), forSorting.end(), &compare);
    }
    else
    {
        ForSorting::decide = 3;
        sort(forSorting.begin(), forSorting.end(), &compare);
    }

    ofstream ofile;
    ofile.open("Products.txt", ios::out);
    deque<ForSorting>::iterator iter;

    if (ofile.is_open())
    {
        for (iter = forSorting.begin(); iter != forSorting.end(); iter++)
        {
            // Adding Content to the File
            ofile.precision(10);
            ofile << iter->getName() << "," << iter->getQuantity() << "," << iter->getPrice() << endl;
        }
    }
    else
        cout << "\nError While Opening The File\n";

    ofile.close();
    cout << "\nSuccessfully Sorted\n";
}

template <typename T>
// Checks Whether The Entered Input is Correct or Not
T checkInput(T Input, string content)
{
    while (!cin.good())
    {
        cout << "\nWrong Input, Please Enter It Correctly!!\n";
        cin.clear();           // Clears the previous Input
        cin.ignore(100, '\n'); // Ignores the Wrong Input till 100 Characters
        cout << content;
        cin >> Input;
    }

    while (Input < 0)
    {
        cout << "\nThis Value Cannot Be Negative!!\n";
        cin.clear();           // Clears the previous Input
        cin.ignore(100, '\n'); // Ignores the Wrong Input till 100 Characters
        cout << content;
        cin >> Input;
    }
    return Input;
}

// Checks For The Empty File
bool AdministratorPortal::IsEmpty(ifstream &eFile)
{
    return eFile.peek() == ifstream::traits_type::eof();
}

// Checks For The Empty File
bool AdministratorPortal::IsEmpty(fstream &eFile)
{
    return eFile.peek() == fstream::traits_type::eof();
}

void AdministratorPortal::AddProducts(ofstream &enFile)
{
    int noOfProducts;
    string content = "\nHow Many Products You Want To Add\n";
    cout << content;
    cin >> noOfProducts;

    // checkInput will return the Correct Input
    noOfProducts = checkInput(noOfProducts, content);

    string *nameOfProduct = new (nothrow) string[noOfProducts]; // Array of Names
    int quantityOfProduct[noOfProducts];                        // Array of Quantities
    float priceOfProduct[noOfProducts];                         // Array of Prices

    if (!nameOfProduct)
        throw bad_alloc();

    else
    {
        for (int i = 0; i < noOfProducts; i++)
        {
            cin.ignore();
            cout << "\nEnter The Name of Item " << i + 1 << " : ";
            getline(cin, nameOfProduct[i]);

            for (int j = 0; j < nameOfProduct[i].length(); j++)
            {
                nameOfProduct[i][j] = toupper(nameOfProduct[i][j]);
            }

            char name[nameOfProduct[i].length() + 1]; // Array to store the characters of string nameOfProduct
            strcpy(name, nameOfProduct[i].c_str());   // nameOfProduct is converted into char and stored in the name Array

            char Content1[40];
            sprintf(Content1, "\nEnter The Price of %s : ", name); // sprintf function for fstring
            cout << Content1;
            cin >> priceOfProduct[i];

            // checkInput will return the Correct Input
            priceOfProduct[i] = checkInput(priceOfProduct[i], Content1);

            char Content2[40];
            sprintf(Content2, "\nEnter The Quantity of %s : ", name); // sprintf function for fstring
            cout << Content2;
            cin >> quantityOfProduct[i];

            // checkInput will return the Correct Input
            quantityOfProduct[i] = checkInput(quantityOfProduct[i], Content2);
        }
        bool flag = addToProductList(enFile, nameOfProduct, quantityOfProduct, priceOfProduct, noOfProducts);

        if (noOfProducts > 0 && flag == 1)
            cout << "\nAll Products SuccessFully Added!!\n";
    }
    delete[] nameOfProduct;
}

void AdministratorPortal::DisplayProducts()
{
    ifstream display; // Object of ifstream file
    string productsLists;
    vector<string> result;
    display.open("Products.txt", ios::in); // Function to open the file

    if (IsEmpty(display))
    {
        cout << "\nNo Products Available!!\n";
        display.close();
        return;
    }

    cout << "\n\t\t\t\t\t\t  ***** PRODUCTS LISTS *****\n\n\t\t\t\tITEM\t\t\t     Quantity\t\t\t    PRICE/ITEM\n";

    if (display.is_open()) // Checking whether the file is opened or not
    {
        while (getline(display, productsLists)) // While loop till the end of file
        {
            boost::split(result, productsLists, boost::is_any_of(","));

            if (result[0].length() > 15)
                cout << "\t\t\t\t" << result[0] << "\t\t" << result[1] << "\t\t\t\t" << result[2] << "\\-" << endl;

            else if (result[0].length() >= 8)
                cout << "\t\t\t\t" << result[0] << "\t\t\t" << result[1] << "\t\t\t\t" << result[2] << "\\-" << endl;

            else
                cout << "\t\t\t\t" << result[0] << "\t\t\t\t" << result[1] << "\t\t\t\t" << result[2] << "\\-" << endl;
        }
    }

    // Printed when the file is not opened
    else
        cout << "\nNot Able To Display Products!!\n";

    cout << "\n\n";
    display.close();
}

void AdministratorPortal::ModifyProducts()
{
    ifstream modify;
    modify.open("Products.txt");
    if (IsEmpty(modify))
    {
        cout << "\nNo Products Available!!\n";
        modify.close();
        return;
    }
    modify.close();

    int noOfProducts;
    string content = "\nHow Many Products You Want To Modify\n";
    cout << content;
    cin >> noOfProducts;

    // checkInput will return the Correct Input
    noOfProducts = checkInput(noOfProducts, content);

    string *nameOfTheProduct = new (nothrow) string[noOfProducts]; // Array of Names
    int quantityOfTheProducts[noOfProducts];                       // Array of Quantities
    float priceOfTheProduct[noOfProducts];                         // Array of Prices

    if (!nameOfTheProduct)
        throw bad_alloc();

    else
    {
        for (int i = 0; i < noOfProducts; i++)
        {
            cin.ignore();
            cout << "\nEnter The Name of The Product " << i + 1 << " You Want To Modify : ";
            getline(cin, nameOfTheProduct[i]);

            for (int j = 0; j < nameOfTheProduct[i].length(); j++)
            {
                nameOfTheProduct[i][j] = toupper(nameOfTheProduct[i][j]);
            }

            char name[nameOfTheProduct[i].length() + 1]; // Array to store the characters of string nameOfTheProduct
            strcpy(name, nameOfTheProduct[i].c_str());   // nameOfProduct is converted into char and stored in the name Array

            char Content1[40];
            sprintf(Content1, "\nEnter The Modified Quantity of %s : ", name);
            cout << Content1;
            cin >> quantityOfTheProducts[i];

            // checkInput will return the Correct Input
            quantityOfTheProducts[i] = checkInput(quantityOfTheProducts[i], Content1);

            char Content2[40];
            sprintf(Content2, "\nEnter The Modified Price of %s : ", name); // Sprintf Function for fstring
            cout << Content2;
            cin.precision(4);
            cin >> priceOfTheProduct[i];

            // checkInput will return the Correct Input
            priceOfTheProduct[i] = checkInput(priceOfTheProduct[i], Content2);

            string product;
            vector<string> result;

            fstream infile; // Object of fstream file
            infile.open("Products.txt", ios::in | ios::app);

            if (infile.is_open()) // Checking whether the file is opened or not
            {
                while (infile.good()) // While loop till the end of file
                {
                    getline(infile, product);

                    boost::split(result, product, boost::is_any_of(",")); // split function used to split the string which is present in boost library

                    if (nameOfTheProduct[i] == result[0])
                    {
                        result[1] = to_string(quantityOfTheProducts[i]); // Removing the quantity of items which the Administrtor doesn't want in the file
                        result[2] = to_string(priceOfTheProduct[i]);
                        deleteLine(infile, "Products.txt", product);
                        // Adding content to the file
                        infile.precision(4);
                        infile << result[0] << "," << result[1] << "," << stof(result[2]) << endl;
                    }
                }
            }

            // Printed when the file is not opened
            else
            {
                cout << "\nError While Opening The File!!\n";
                return;
            }
            infile.close();
        }

        if (noOfProducts > 0)
            cout << "\nAll Products SuccessFully Modified!!\n";
    }
    delete[] nameOfTheProduct;
}

void AdministratorPortal::DeleteProducts(int index)
{
    string *nameOfTheProduct = new (nothrow) string; // Dynamic initialization of string to store name of the product

    // nothrow will convert the pointer implicitely to false if memory is not allocated
    if (!nameOfTheProduct)
        throw bad_alloc();

    cout << "\nEnter The Name of Item " << index + 1 << " To Delete\n";
    cin >> (*nameOfTheProduct);

    for (int j = 0; j < (*nameOfTheProduct).length(); j++)
    {
        (*nameOfTheProduct)[j] = toupper((*nameOfTheProduct)[j]);
    }

    string product;
    vector<string> result; // Vector Containing Elements of String DataType

    fstream infile;                       // Object of fstream class
    infile.open("Products.txt", ios::in); // Function to open file

    if (infile.is_open()) // Checking whether the file is opened or not
    {
        while (infile.good()) // While loop till the end of file
        {
            getline(infile, product);

            string input(product);
            boost::split(result, input, boost::is_any_of(",")); // split function used to split the string which is present in boost library

            if (*nameOfTheProduct == result[0])
                deleteLine(infile, "Products.txt", product);
        }
    }

    else
    {
        cout << "\n\nNot Able To Delete Products!!\n";
        return;
    }
    // delete nameOfTheProduct;
    infile.close();
}

class CustomerDetails : public AdministratorPortal
{
    Storage st;
    string nameOfCustomer;
    string mobileNumberOfCustomer;
    char cityOfCustomer[10];
    int numOfItems;

public:
    CustomerDetails();    // Default Constructer
    ~CustomerDetails() {} // Destructer
    void Purchase();      // Function Declaration
};

CustomerDetails::CustomerDetails()
{
    cout << "\n***** Customer Details *****\n";
    cin.ignore();

label1:
    cout << "\nName : ";
    getline(cin, nameOfCustomer); // getline functions takes the input with spaces

    try
    {
        const char *ch = nameOfCustomer.c_str();
        for (int i = 0; i < nameOfCustomer.length(); i++)
        {
            if (isalpha(ch[i]) || ch[i] == ' ')
            {
                // Do Nothing
            }

            else
                throw nameOfCustomer;
        }
    }
    catch (string &e)
    {
        cout << "\nNot a Valid Name " << e << endl;
        goto label1;
    }

label2:
    cout << "\nMobile No. : ";
    getline(cin, mobileNumberOfCustomer);

    try
    {
        const char *ch = mobileNumberOfCustomer.c_str();
        for (int i = 0; i < mobileNumberOfCustomer.length(); i++)
        {
            if (isdigit(ch[i]))
            {
                // DO Nothing
            }

            else
                throw mobileNumberOfCustomer;
        }
    }
    catch (string &e)
    {
        cout << "\nNot a Valid Number " << e << endl;
        goto label2;
    }

label3:
    cout << "\nCity : ";
    cin.getline(cityOfCustomer, 100, '\n');

    try
    {
        for (int i = 0; i < strlen(cityOfCustomer); i++)
        {
            if (isalpha(cityOfCustomer[i]))
            {
                // Do Nothing
            }

            else
                throw cityOfCustomer;
        }
    }
    catch (char *&e)
    {
        cout << "\nNot a Valid Name " << e << endl;
        goto label3;
    }

    string content = "\nHow Many Items Do You Want To Buy??\n";
    cout << content;
    cin >> numOfItems;
    // checkInput will return the Correct Input
    numOfItems = checkInput(numOfItems, content);
}

void AdministratorPortal::displayCustomerLists()
{
    ifstream customer;
    string customerLists;
    AdministratorPortal sc; // Object of Shoping Club Class
    customer.open("Customer.txt", ios::in);

    if (sc.IsEmpty(customer))
    {
        cout << "\nNo Customers!!\n";
        return;
    }

    cout << "\n\t\t\t\t********** CUSTOMER LISTS **********\n\n";
    if (customer.is_open()) // Checking whether the file is opened or not
    {
        while (!customer.eof()) // While loop till the end of file
        {
            getline(customer, customerLists);
            cout << customerLists << endl;
        }
    }

    // Printed when the file is not opened
    else
        cout << "\nNot Able To Show Customer Lists!!\n";
}

void CustomerDetails::Purchase()
{
    string *nameOfItems = new (nothrow) string[numOfItems]; // Array of Names
    int quantityOfItems[numOfItems];                        // Array of Quantities
    float priceOfItems[numOfItems];                         // Array of Prices
    fstream infile;                                         // Object of fstream
    bool flag;

    if (!nameOfItems && !quantityOfItems && !priceOfItems)
        throw bad_alloc();

    else
    {
        for (int i = 0; i < numOfItems; i++)
        {
            flag = false;
            cin.ignore();
            cout << "\nEnter The Name of Item " << i + 1 << endl;
            getline(cin, nameOfItems[i]);

            for (int j = 0; j < nameOfItems[i].length(); j++)
            {
                nameOfItems[i][j] = toupper(nameOfItems[i][j]);
            }

            char name[nameOfItems[i].length() + 1]; // Array to store the characters of string nameOfItems
            strcpy(name, nameOfItems[i].c_str());   // nameOfItems is converted into char and stored in the name Array

            char Content1[40];
            sprintf(Content1, "\nEnter The Quantity of %s\n", name); // Sprintf for fstring
            cout << Content1;
            cin >> quantityOfItems[i];

            // checkInput will return the Correct Input
            quantityOfItems[i] = checkInput(quantityOfItems[i], Content1);

            char Content2[40];
            sprintf(Content2, "\nEnter The Price of %s\n", name);
            cout << Content2;
            cin >> priceOfItems[i];

            // checkInput will return the Correct Input
            priceOfItems[i] = checkInput(priceOfItems[i], Content2);

            string product;
            vector<string> result;

            infile.open("Products.txt", ios::in | ios::app); // Function to open file

            if (infile.is_open()) // Checking whether the file is opened or not
            {
                if (IsEmpty(infile))
                {
                    cout << "\nNo Products Available!!\n";
                    return;
                }

                while (getline(infile, product)) // While loop till the end of file
                {
                    string input(product);
                    boost::split(result, input, boost::is_any_of(",")); // Split function used to split the string present in boost library

                    if (nameOfItems[i] == result[0])
                    {
                        stringstream sso1; // Object of StringStream
                        stringstream sso2; // Object of StringStream
                        flag = true;

                        sso1 << result[1];
                        int quantity;
                        sso1 >> quantity;

                        sso2 << result[2];
                        float price;
                        sso2 >> price;

                        while (!(price == priceOfItems[i]))
                        {
                            cout << "\nPrice is not Matching, Please Enter Correct Price!!\n";
                            cout << Content2;
                            cin >> priceOfItems[i];
                        }

                        if (quantityOfItems[i] > quantity) // Checks the sufficient quantity of items present in the stock
                        {
                            cout << "\nNot Sufficient " << name << "s\n";
                            return;
                        }
                        // Removing the quantity of items purchased by the customer from the file
                        result[1] = to_string(quantity - quantityOfItems[i]);
                        st.deleteLine(infile, "Products.txt", product);
                        // Adding content to the file
                        infile << result[0] << "," << result[1] << "," << result[2] << endl;
                    }
                }
            }

            // Printed when the file is not opened
            else
                cout << "\nError in Opening The File!!\n";

            infile.close();

            if (!flag)
            {
                cout << "\nNo Product of This Name!!\n";
                return;
            }
        }
        system("CLS");
        receiptGenerater(nameOfItems, quantityOfItems, priceOfItems, numOfItems, nameOfCustomer);
        addToCustomerList(nameOfItems, quantityOfItems, priceOfItems, numOfItems, nameOfCustomer, mobileNumberOfCustomer, cityOfCustomer);
    }
    delete[] nameOfItems;
}

// Driver Function
int main()
{
    char EntryInput;
    cout << "\nPress E To Enter Into Shopping Club\n";
    cin >> EntryInput;

    while (EntryInput != 'e' && EntryInput != 'E')
    {
        cout << "\nPlease Enter Correct Input!!\n";
        cout << "\nPress E To Enter Into Shopping Club\n";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> EntryInput;
    }

    if (tolower(EntryInput) == 'e')
    {
        greeting ::Welcome();
        goto label;
    }
label:
    char userInput;
    int userInput1; // UserInput For Main Menu
    int userInput2; // UserInput For Adminstrator Portal
    int userInput3; // UserInput For Sorting
    char userInput4;
    string content("\n\t\t************ MAIN MENU ************\n\n\t\t1. Administrator Portal\n\t\t2. Customer\n\t\t3. Exit\n>>>> ");
    string content1("\n\t\t********** ADMINISTRATOR PORTAL **********\n\n\t\t1. Add New Products\n\t\t2. Display All Products\n\t\t3. Modify Exiting Products\n\t\t4. Delete Products\n\t\t5. Sorting\n\t\t6. Customer Lists\n\t\t7. Back To MAIN MENU\n>>>> ");
    string content2("\n\t\t******** Sorting ********\n\n\t\t1. Sort Based On Quantity\n\t\t2. Sort Based On Price\n\t\t3. Sort Based On Names\n\t\t4. Back To Administrator Portal\n>>>> ");
    string password;
    AdministratorPortal *sc = new (nothrow) AdministratorPortal; // Object of class Shopping Club
    CustomerDetails *cd = NULL;                                  // NULL Pointer

    if (!sc)
        throw bad_alloc();

    while (true)
    {
    label1:
        cout << content;
        cin >> userInput1;

        // checkInput returns the Correct Input
        userInput1 = checkInput(userInput1, content);

        switch (userInput1)
        {
        case 1:
            cout << "\nPlease Enter Your Password\n";
        label2:
            cin >> password;

            if (password == PASSWORD)
            {
                while (true)
                {
                label6:
                    ofstream oFile; // Object of ofstream class
                    cout << content1;
                    cin >> userInput2;

                    // checkInput will return the correct Input
                    userInput2 = checkInput(userInput2, content1);

                    switch (userInput2)
                    {
                    case 1:
                        oFile.open("Products.txt", ios::app);
                        sc->AddProducts(oFile);
                        oFile.close();
                        break;

                    case 2:
                        sc->DisplayProducts();
                        break;

                    case 3:
                        sc->ModifyProducts();
                        break;

                    case 4:
                    {
                        ifstream deleteP;
                        deleteP.open("Products.txt");
                        if (sc->IsEmpty(deleteP))
                        {
                            cout << "\nNo Products Available!!\n";
                            deleteP.close();
                            break;
                        }
                        deleteP.close();
                        int numOfItemsToDelete;
                        string content = "\nHow Many Products You Want To Delete\n";
                        cout << content;
                        cin >> numOfItemsToDelete;

                        // checkInput will return the Correct Input
                        numOfItemsToDelete = checkInput(numOfItemsToDelete, content);

                        for (int index = 0; index < numOfItemsToDelete; index++)
                        {
                            sc->DeleteProducts(index);
                        }

                        if (numOfItemsToDelete > 0)
                            cout << "\nAll Products SuccessFully Deleted!!\n";
                    }
                    break;

                    case 5:
                        while (true)
                        {
                            cout << content2;
                            cin >> userInput3;
                            userInput3 = checkInput(userInput3, content1);
                            switch (userInput3)
                            {
                            case 1:
                                sc->Sort(1);
                                break;
                            case 2:
                                sc->Sort(2);
                                break;
                            case 3:
                                sc->Sort(3);
                                break;
                            case 4:
                                goto label6;
                                break;

                            default:
                                cout << "\nPlease Enter Correct Input!!\n";
                                break;
                            }
                        }
                        break;

                    case 6:
                        system("CLS");
                        sc->displayCustomerLists();
                    label4:
                        cout << "\nPress 'c' To Continue and 'e' to Exit\n";
                        cin >> userInput4;

                        if (tolower(userInput4) == 'c')
                            goto label6;
                        else if (tolower(userInput4) == 'e')
                            goto label3;
                        else
                        {
                            cout << "\nPlease Enter Correct Input!!\n";
                            goto label4;
                        }
                        break;

                    case 7:
                        goto label1;
                        break;

                    default:
                        cout << "\nPlease Enter Correct Input!!\n";
                        break;
                    }
                }
            }

            else
            {
                cout << "\nWrong Password!!\n\nPlease Enter Your Password Again\n";
                goto label2;
            }
            break;

        case 2:
        {
            while (true)
            {
                int menu;
                string content = "\n\t\t****** CUSTOMER ******\n\n\t\t1. Display Products\n\t\t2. Purchase Products\n\t\t3. Back To Main Menu\n>>>> ";
                cout << content;
                cin >> menu;

                // checkInput will return the Correct Input
                menu = checkInput(menu, content);

                switch (menu)
                {
                case 1:
                    sc->DisplayProducts();
                    break;

                case 2:
                    cd = new (nothrow) CustomerDetails(); // Dynamic Allocation in Heap Memory
                    if (!cd)
                    {
                        cout << "\nMemory Allocation Failed!!\n";
                        return 0;
                    }
                    cd->Purchase();
                label5:
                    cout << "\nPress 'c' To Continue and 'e' to Exit\n";
                    cin >> userInput;

                    if (tolower(userInput) == 'c')
                        goto label1;
                    else if (tolower(userInput) == 'e')
                        goto label3;
                    else
                    {
                        cout << "\nPlease Enter Correct Input!!\n";
                        goto label5;
                    }
                    break;

                case 3:
                    goto label1;

                default:
                    cout << "\nPlease Enter Correct Input!!\n";
                    break;
                }
            }
        }
        break;

        case 3:
            goto label3;
            break;

        default:
            cout << "\nPlease Enter Correct Input!!\n";
            goto label1;
        }
    }

label3:
    greeting::Thankyou();
    delete sc;
    delete cd;
    return 0;
}

// Output 

// Press E To Enter Into Shopping Club
// whghfw

// Please Enter Correct Input!!

// Press E To Enter Into Shopping Club
// w

// Please Enter Correct Input!!

// Press E To Enter Into Shopping Club
// e

//                 ************ MAIN MENU ************

//                 1. Administrator Portal
//                 2. Customer
//                 3. Exit
// >>>> we

// Wrong Input, Please Enter It Correctly!!

//                 ************ MAIN MENU ************

//                 1. Administrator Portal
//                 2. Customer
//                 3. Exit
// >>>> 1

// Please Enter Your Password
// 1234

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

// No Products Available!!

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 3

// No Products Available!!

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 4

// No Products Available!!

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 5

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 1

// No Products Available!!

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 2

// No Products Available!!

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 3

// No Products Available!!

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 4

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 1

// How Many Products You Want To Add
// 10

// Enter The Name of Item 1 : Pen

// Enter The Price of PEN : 5

// Enter The Quantity of PEN : 500

// Enter The Name of Item 2 : Pencil

// Enter The Price of PENCIL : 6

// Enter The Quantity of PENCIL : 600

// Enter The Name of Item 3 : Eraser

// Enter The Price of ERASER : 4

// Enter The Quantity of ERASER : 400

// Enter The Name of Item 4 : Marker

// Enter The Price of MARKER : 15

// Enter The Quantity of MARKER : 1500

// Enter The Name of Item 5 : Notebooks

// Enter The Price of NOTEBOOKS : 55

// Enter The Quantity of NOTEBOOKS : 5500

// Enter The Name of Item 6 : Rubber Stamp

// Enter The Price of RUBBER STAMP : 20

// Enter The Quantity of RUBBER STAMP : 2000

// Enter The Name of Item 7 : Highlighter

// Enter The Price of HIGHLIGHTER : 25

// Enter The Quantity of HIGHLIGHTER : 2500

// Enter The Name of Item 8 : Stapler

// Enter The Price of STAPLER : 8

// Enter The Quantity of STAPLER : 200

// Enter The Name of Item 9 : Ball Point

// Enter The Price of BALL POINT : 12

// Enter The Quantity of BALL POINT : 400

// Enter The Name of Item 10 : Calculator

// Enter The Price of CALCULATOR : 800

// Enter The Quantity of CALCULATOR : 8000

// All Products SuccessFully Added!!

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 PEN                             500                             5\-
//                                 PENCIL                          600                             6\-
//                                 ERASER                          400                             4\-
//                                 MARKER                          1500                            15\-
//                                 NOTEBOOKS                       5500                            55\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 STAPLER                         200                             8\-
//                                 BALL POINT                      400                             12\-
//                                 CALCULATOR                      8000                            800\-


//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 3

// How Many Products You Want To Modify
// 2

// Enter The Name of The Product 1 You Want To Modify : pen

// Enter The Modified Quantity of PEN : 550

// Enter The Modified Price of PEN : 5.5

// Enter The Name of The Product 2 You Want To Modify : pencil

// Enter The Modified Quantity of PENCIL : 660

// Enter The Modified Price of PENCIL : 6.6

// All Products SuccessFully Modified!!

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 ERASER                          400                             4\-
//                                 MARKER                          1500                            15\-
//                                 NOTEBOOKS                       5500                            55\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 STAPLER                         200                             8\-
//                                 BALL POINT                      400                             12\-
//                                 CALCULATOR                      8000                            800\-
//                                 PEN                             550                             5.5\-
//                                 PENCIL                          660                             6.6\-


//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 5

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 1

// Successfully Sorted

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 4

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 STAPLER                         200                             8\-
//                                 BALL POINT                      400                             12\-
//                                 ERASER                          400                             4\-
//                                 PEN                             550                             5.5\-
//                                 PENCIL                          660                             6.6\-
//                                 MARKER                          1500                            15\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 NOTEBOOKS                       5500                            55\-
//                                 CALCULATOR                      8000                            800\-


//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 5

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 2

// Successfully Sorted

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 4

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 ERASER                          400                             4\-
//                                 PEN                             550                             5.5\-
//                                 PENCIL                          660                             6.6\-
//                                 STAPLER                         200                             8\-
//                                 BALL POINT                      400                             12\-
//                                 MARKER                          1500                            15\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 NOTEBOOKS                       5500                            55\-
//                                 CALCULATOR                      8000                            800\-


//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 5

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 3

// Successfully Sorted

//                 ******** Sorting ********

//                 1. Sort Based On Quantity
//                 2. Sort Based On Price
//                 3. Sort Based On Names
//                 4. Back To Administrator Portal
// >>>> 4

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 BALL POINT                      400                             12\-
//                                 CALCULATOR                      8000                            800\-
//                                 ERASER                          400                             4\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 MARKER                          1500                            15\-
//                                 NOTEBOOKS                       5500                            55\-
//                                 PEN                             550                             5.5\-
//                                 PENCIL                          660                             6.6\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 STAPLER                         200                             8\-

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 6

//                                 ********** CUSTOMER LISTS **********

// Name : Ashish Patil
// Mobile No. : 7812653152
// City : Pune

//         ************ Receipt ************

//         Thu Dec 17 23:12:08 2020

//         Name : Ashish Patil

//         ITEM                          QUANTITY                          PRICE
//         PEN                             500                             2750\-
//         NOTEBOOK                        500                             27500\-

//         Total Price = 30250/-

// Press 'c' To Continue and 'e' to Exit
// c

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 7

//                 ************ MAIN MENU ************

//                 1. Administrator Portal
//                 2. Customer
//                 3. Exit
// >>>> 2

//                 ****** CUSTOMER ******

//                 1. Display Products
//                 2. Purchase Products
//                 3. Back To Main Menu
// >>>> 1

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 BALL POINT                      400                             12\-
//                                 CALCULATOR                      8000                            800\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 MARKER                          1500                            15\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 STAPLER                         200                             8\-
//                                 PEN                             550                             5.5\-
//                                 PENCIL                          660                             6.6\-
//                                 NOTEBOOKS                       5500                            55\-
//                                 ERASER                          400                             4\-

//                 ****** CUSTOMER ******

//                 1. Display Products
//                 2. Purchase Products
//                 3. Back To Main Menu
// >>>> 2

// ***** Customer Details *****

// Name : Rushikesh Susar

// Mobile No. : 8258612783ew

// Not a Valid Number 8258612783ew

// Mobile No. : 8258612783

// City : Pune

// How Many Items Do You Want To Buy??
// 4

// Enter The Name of Item 1
// pen

// Enter The Quantity of PEN
// 50

// Enter The Price of PEN
// 5

// Price is not Matching, Please Enter Correct Price!!

// Enter The Price of PEN
// 5.5

// Enter The Name of Item 2
// pencil

// Enter The Quantity of PENCIL
// 60

// Enter The Price of PENCIL
// 6.6

// Enter The Name of Item 3
// eraser

// Enter The Quantity of ERASER
// 40

// Enter The Price of ERASER
// 4

// Enter The Name of Item 4
// notebooks

// Enter The Quantity of NOTEBOOKS
// 100

// Enter The Price of NOTEBOOKS
// 55

//         ************ Receipt ************

//         Mon Dec 28 16:27:51 2020

//         Name : Rushikesh Susar

//         ITEM                         QUANTITY                           PRICE
//         PEN                             50                              275\-
//         PENCIL                          60                              396\-
//         ERASER                          40                              160\-
//         NOTEBOOKS                       100                             5500\-

//         Total Price = 6331/-

// Press 'c' To Continue and 'e' to Exit
// c

//                 ************ MAIN MENU ************

//                 1. Administrator Portal
//                 2. Customer
//                 3. Exit
// >>>> 1

// Please Enter Your Password
// 1234

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 6

//                                 ********** CUSTOMER LISTS **********

// Name : Ashish Patil
// Mobile No. : 7812653152
// City : Pune

//         ************ Receipt ************

//         Thu Dec 17 23:12:08 2020

//         Name : Ashish Patil

//         ITEM                          QUANTITY                          PRICE
//         PEN                             500                             2750\-
//         NOTEBOOK                        500                             27500\-

//         Total Price = 30250/-


// Name : Rushikesh Susar
// Mobile No. : 8258612783
// City : Pune

//         ************ Receipt ************

//         Mon Dec 28 16:27:51 2020

//         Name : Rushikesh Susar

//         ITEM                          QUANTITY                          PRICE
//         PEN                             50                              275\-
//         PENCIL                          60                              396\-
//         ERASER                          40                              160\-
//         NOTEBOOKS                       100                             5500\-

//         Total Price = 6331/-

// Press 'c' To Continue and 'e' to Exit
// c

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 BALL POINT                      400                             12\-
//                                 CALCULATOR                      8000                            800\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 MARKER                          1500                            15\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 STAPLER                         200                             8\-
//                                 PEN                             500                             5.5\-
//                                 PENCIL                          600                             6.6\-
//                                 ERASER                          360                             4\-
//                                 NOTEBOOKS                       5400                            55\-

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 4

// How Many Products You Want To Delete
// 4

// Enter The Name of Item 1 To Delete
// pen

// Enter The Name of Item 2 To Delete
// pencil

// Enter The Name of Item 3 To Delete
// eraser

// Enter The Name of Item 4 To Delete
// notebooks

// All Products SuccessFully Deleted!!

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 2

//                                                   ***** PRODUCTS LISTS *****

//                                 ITEM                         Quantity                       PRICE/ITEM
//                                 BALL POINT                      400                             12\-
//                                 CALCULATOR                      8000                            800\-
//                                 HIGHLIGHTER                     2500                            25\-
//                                 MARKER                          1500                            15\-
//                                 RUBBER STAMP                    2000                            20\-
//                                 STAPLER                         200                             8\-

//                 ********** ADMINISTRATOR PORTAL **********

//                 1. Add New Products
//                 2. Display All Products
//                 3. Modify Exiting Products
//                 4. Delete Products
//                 5. Sorting
//                 6. Customer Lists
//                 7. Back To MAIN MENU
// >>>> 7

//                 ************ MAIN MENU ************

//                 1. Administrator Portal
//                 2. Customer
//                 3. Exit
// >>>> 3
// Process returned 0 (0x0)   execution time : 294.326 s