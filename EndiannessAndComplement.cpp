/*************************
* Name: Amine Ghoorchiyani
* ID: 50553657
* How to compile: g++ program1.cpp
**************************/
#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 32;

void endianness();
void get_two_complement();
void print_menu();

int main()
{
    int menu;
   
    print_menu(); 
    cout << "Enter a number to select the menu: "; 
    cin >> menu;

    do
    {
        if(menu == 1)
        {
            endianness();
        }
        else if(menu == 2)
        {
            get_two_complement();
        }    
        else
        {
           cout << "wrong input!!!\n";
        }

        print_menu();
        cout << "Enter a number to select the menu: "; 
        cin >> menu;
    } while(menu != 0);
    cout << "Bye !!!" << endl;
    exit(0);
}

void endianness()
{
    cout << "My system uses the following endianness..." << endl;
    //write the code here
    //print either little or big below
    int number = 1;
    char* ptr = (char*)&number; // cast it into char*
    
    if(ptr[0] == 1) // 01 becomes 1
    {
        cout << "Little-endian.\n";
    }
    else
    {
        cout << "Big-endian.\n";
    }
    //end of code
} 

void get_two_complement()
{
    // m_of_2 represents multiplication of 2
    int number, m_of_2 = 1;
    int binary[SIZE] = {0}; 
    int index = 0;
    bool stop = false, negative = false;
    
    cout << "Input the number to convert two's complement: ";
    cin >> number;
    cout << number << "'s two's complement is: "; 
    //write the code here
    
    if(number < 0 && number != -2147483648)
    {
        number *= -1; // first treat is as a positive integer 
        negative = true;
    }
    
    if(number != -2147483648)
    {
        // find a right number of mulptiplication of two that is <= number
        while(number > m_of_2 && !stop) 
        {
            // less than number and cannot be underflown
            if((m_of_2 * 2) <= number && (m_of_2 * 2) > -2147483648)
            {
                m_of_2 *= 2;
                index++; // keeps track of two to the nth power
            }
            else // m_of_2 > number
            {
                stop = true;
            }
        }
            
        do // set 1 to the corret position of binary representation
        {
            if((number - m_of_2) >= 0) 
            {
                number -= m_of_2;
                //  set 1 to the current nth power
                binary[SIZE - index - 1] = 1; 
            }
            m_of_2 /= 2; // two to the n - 1 power
            index--; 
        } while(m_of_2 != 0);
    }
    else // number == -2147483648
    {
        binary[0] = 1;
    }
    
    if(negative)
    {
        for(int index = 0; index < SIZE; index++)
        {
            if(binary[index] == 0) // flip 0s and 1s
            {
                binary[index] = 1;
            }
            else // binary[index] == 1
            {
                binary[index] = 0;
            }
        }
        
        if(binary[SIZE - 1] == 0) // + 1 at first digit
        {
            binary[SIZE - 1] = 1;
        }
        else // binary[SIZE - 1] == 1
        {
            // adjust the digits
            int index = SIZE - 1;
            while(binary[index] == 1)
            {
                binary[index] = 0;
                index--;
            }
            if(binary[index] == 0)
            {
                binary[index] = 1;
            }  
        } 
    }
    
    // display binary representation of number
    int count = 0;
    for(int index = 0; index < SIZE; index++)
    {
        count++;
        cout << binary[index];
        if(count % 4 == 0)
        {
            cout << ' ';
        }
    }
    cout << '\n';
    
    //end of code 
    cout << endl << "[format]:" << endl;
    cout << number << "'s two's complement is: "; 
    cout << "0000 0000 0000 0000 0000 0000 0000 0000"<< endl;
} 

void print_menu()
{
    cout << "********************************" << endl; 
    cout << "****    Homwwork 1: Menu    ****" << endl;
    cout << "*  1. Check endianness         *" << endl;
    cout << "*  2. Convert two's complement *" << endl;
    cout << "*  0. Exit the program         *" << endl;
    cout << "********************************" << endl; 
}