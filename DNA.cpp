#include "DNA.h"
#include "RNA.h"
#include "Sequence.h"
#include <iostream>
#include<cmath>
using namespace std;
class invalidOpertator : exception
{
public:
    void print()
    {
        cout << "Enter a valid operator\n";
    }
};
DNA::DNA()
{

}

void DNA::Print()
{
    cout << "what is the starting index: ";
    cin >> startIndex;
    cout << endl << "what is the  index: ";
    cin >> endIndex;
    for (int i=startIndex ; i<endIndex ; i++)
    {
        cout << seq[i];
    }
}

RNA DNA::ConvertToRNA()
{
loop3:
    //Try and catch if the input is wrong
    try
    {
        cin>>seq;
        int i=0;
        for (int i=0; i<seq.length(); i++)
        {
            if(seq[i] != 'A' && seq[i]  != 'C' && seq[i]  != 'G' && seq[i]  != 'T')
                throw  invalidOpertator();
        }
    }
    catch (invalidOpertator e)
    {
        e.print();
        cout << "Enter the sequence you want to enter : ";
        goto loop3;
    }
    RNA R;
    cout << "what is the starting index: ";
    cin >> startIndex;
    cout << endl << "what is the  index: ";
    cin >> endIndex;

    for (int i=startIndex ; i<endIndex ; i++)           //Loop that check if there is T to convert it to U
    {
        if (seq[i] == 'T')
        {
            R.seq += 'U';
        }
        else
        {
            R.seq+=seq[i];
        }
    }
    return R;
}

void DNA::BuildComplementaryStrand()
{
    //Function that get tge complement of DNA as it change C->G , A->T and vise versa
loop2:
    try
    {
        cin>>seq;
        int i=0;
        for (int i=0; i<seq.length(); i++)
        {
            if(seq[i] != 'A' && seq[i]  != 'C' && seq[i]  != 'G' && seq[i]  != 'T')
                throw  invalidOpertator();
        }
    }
    catch (invalidOpertator e)
    {
        e.print();
        cout << "Enter the sequence you want to enter : ";
        goto loop2;
    }

    cout << "what is the starting index: ";
    cin >> startIndex;
    cout << endl << "what is the  index: ";
    cin >> endIndex;
    int counter = 0;
    string temp;
    for (int i=startIndex ; i<endIndex ; i++)
    {
        if (seq[i] == 'C')
        {
            temp[i] = 'G';
        }
        if (seq[i] == 'G')
        {
            temp[i] = 'C';
        }
        if (seq[i] == 'A')
        {
            temp[i] = 'T';
        }
        if (seq[i] == 'T')
        {
            temp[i] = 'A';
        }
    }
    for (int i = 0; i < temp.length() / 2; i++)
    {
        swap(temp[i], temp[temp.length() - i - 1]);
    }
    for(int i=startIndex ; i<endIndex ; i++)
    {
        cout << temp[i];
    }
}

void operator+ (Sequence &s1,Sequence& s2)
{
    s1.seq=s1.seq+s2.seq;
}

bool operator== (Sequence &s1,Sequence &s2)
{

    return s1.seq==s2.seq;
}

bool operator!= (Sequence &s1,Sequence &s2)
{

    return s1.seq!=s2.seq;
}
