/*
 * Assignment-1 OOP
 * Sara Tamer Bihery - 20210155 - Group-B
 *Presented to: Dr. Mohamed El-Ramly
 * Task-2 , Sheet-1 , Problem-4
 *
*/

#include <bits/stdc++.h>

using namespace std;

static void numbers(string prefix, int k);
string toBinary(int x , int k);
static void BinaryPrint(int n);

int main() {
    numbers("110011" , 2);
    BinaryPrint(5);
    return 0;
}
//function to convert the decimal number into binary and print it
static void BinaryPrint(int n)
{
    int decimal, binary = 0, remainder, product = 1 ;
    decimal = n;
    while (decimal != 0)
    {
        remainder = decimal % 2;
        binary = binary + (remainder * product);
        decimal = decimal / 2;
        product *= 10;
    }
    cout << binary;
}
// function to convert decimal number to binary and fill the 'k' bits by zeros
// and return it into string
string toBinary(int x , int k){
    string b ;

    int decimal, binary = 0, remainder, product = 1 , dif = 0;
    decimal = x;
    while (decimal != 0)
    {
        remainder = decimal % 2;
        binary = binary + (remainder * product);
        decimal = decimal / 2;
        product *= 10;
    }

    b = to_string(binary);
    dif = 0;
    dif = k - b.length();
    string zeros;

    for(int i = dif ; i > 0 ; i--)
    {
        zeros.append("0");
    }
    zeros.append(b);
    return zeros;
}
// recursive function to print all possible combination between the prefix and binary numbers as a suffix
static void numbers(string prefix, int k)
{
    string temp;
    static int i = 0;
    static int s = pow(2, k);

    if(i != s)
    {
        temp = prefix;
        temp += toBinary(i, k);
        cout << temp << '\n';
        i++;
        return numbers(prefix ,k);
    }
}
