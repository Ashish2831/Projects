#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

namespace store
{
    class Storage
    {
    public:
        bool addToProductList(ofstream &enFile, string name[], int quantity[], float price[], int num);
        void deleteLine(fstream &, string, string);
        void receiptGenerater(string nameOfItems[], int quantityOfItem[], float priceOfItems[], int size, string nameOfCustomer);
        void addToCustomerList(string nameOfItems[], int quantityOfItem[], float priceOfItems[], int numOfItems, string nameOfCustomer, string mobileNumberOfCustomer, char cityOfCustomer[]);
    };

    bool Storage::addToProductList(ofstream &enFile, string name[], int quantity[], float price[], int num)
    {
        if (enFile.is_open()) // Checking whether the file is opened or not
        {
            for (int i = 0; i < num; i++)
            {
                // Adding Content to the File
                enFile.precision(20);
                enFile << name[i] << "," << quantity[i] << "," << float(price[i]) << endl;
            }
            return 1;
        }

        // Printed when the file is not opened
        else
        {
            cout << "Not Able To Add Products\n";
            return 0;
        }
    }

    // Deletes the line from the File
    void Storage::deleteLine(fstream &fin, string fileName, string deleteLine)
    {
        fin.seekg(0);
        ofstream temp;
        temp.open("temp.txt", ios::app); // Temporary file to store the content of original file after Deletion
        string line;

        while (getline(fin, line))
        {
            if (line != deleteLine)
                temp << line << endl;
        }

        temp.close();
        fin.close();

        // c_str converts string into const char
        remove(fileName.c_str());             // Function to Remove the file after Deletion
        rename("temp.txt", fileName.c_str()); // Function to Rename the file after Deletion
        fin.open("Products.txt", ios::in | ios::app);
    }

    // Function to Generate Receipt
    void Storage::receiptGenerater(string nameOfItems[], int quantityOfItem[], float priceOfItems[], int size, string nameOfCustomer)
    {
        float sum = 0;
        time_t tt;           // Arithmetic datatype used to return time
        struct tm *ti;       // Variable to store return value of localtime
        time(&tt);           // To find current calender time
        ti = localtime(&tt); // Returns the value of localtime zone
        cout << "\n\t************ Receipt ************\n\n\t" << asctime(ti) << "\n\tName : " << nameOfCustomer << "\n\n\tITEM\t\t\t     QUANTITY\t\t\t\tPRICE \n";
        for (int i = 0; i < size; i++)
        {
            if (nameOfItems[i].length() > 15)
            {
                cout.precision(20);
                cout << "\t" << nameOfItems[i] << "\t\t" << quantityOfItem[i] << "\t\t\t\t" << priceOfItems[i] * quantityOfItem[i] << "\\-" << endl;
                sum = sum + (priceOfItems[i] * quantityOfItem[i]);
            }

            else if (nameOfItems[i].length() >= 8)
            {
                cout.precision(20);
                cout << "\t" << nameOfItems[i] << "\t\t\t" << quantityOfItem[i] << "\t\t\t\t" << priceOfItems[i] * quantityOfItem[i] << "\\-" << endl;
                sum = sum + (priceOfItems[i] * quantityOfItem[i]);
            }

            else
            {
                cout.precision(20);
                cout << "\t" << nameOfItems[i] << "\t\t\t\t" << quantityOfItem[i] << "\t\t\t\t" << priceOfItems[i] * quantityOfItem[i] << "\\-" << endl;
                sum = sum + (priceOfItems[i] * quantityOfItem[i]);
            }
        }
        cout.precision(20);
        cout << "\n\tTotal Price = " << sum << "/-" << endl;
    }

    void Storage::addToCustomerList(string nameOfItems[], int quantityOfItem[], float priceOfItems[], int numOfItems, string nameOfCustomer, string mobileNumberOfCustomer, char cityOfCustomer[])
    {
        ofstream file; // Object of ofstream class
        file.open("Customer.txt", ios ::app);
        float sum = 0;
        time_t tt;
        struct tm *ti;
        time(&tt);
        ti = localtime(&tt);

        if (file.is_open()) // Checking whether the file is opened or not
        {
            // Adding content to the file
            file << "\n\nName : " << nameOfCustomer << endl
                 << "Mobile No. : " << mobileNumberOfCustomer << endl
                 << "City : " << cityOfCustomer << endl
                 << "\n\t************ Receipt ************\n\n\t" << asctime(ti) << "\n\tName : " << nameOfCustomer << "\n\n\tITEM\t\t\t      QUANTITY\t\t\t\tPRICE\n";

            for (int i = 0; i < numOfItems; i++)
            {
                if (nameOfItems[i].length() > 15)
                {
                    file.precision(20);
                    file << "\t" << nameOfItems[i] << "\t\t" << quantityOfItem[i] << "\t\t\t\t" << priceOfItems[i] * quantityOfItem[i] << "\\-" << endl;
                    sum = sum + (priceOfItems[i] * quantityOfItem[i]);
                }

                else if (nameOfItems[i].length() >= 8)
                {
                    file.precision(20);
                    file << "\t" << nameOfItems[i] << "\t\t\t" << quantityOfItem[i] << "\t\t\t\t" << priceOfItems[i] * quantityOfItem[i] << "\\-" << endl;
                    sum = sum + (priceOfItems[i] * quantityOfItem[i]);
                }

                else
                {
                    file.precision(20);
                    file << "\t" << nameOfItems[i] << "\t\t\t\t" << quantityOfItem[i] << "\t\t\t\t" << priceOfItems[i] * quantityOfItem[i] << "\\-" << endl;
                    sum = sum + (priceOfItems[i] * quantityOfItem[i]);
                }
            }
            file << "\n\tTotal Price = " << sum << "/-";
        }

        else
            cout << "\nThere is Some Issue in Opening the File\n";

        file.close();
    }
} // namespace store