#include "RNA.h"
#include "DNA.h"
#include "Protein.h"
#include "Sequence.h"

#include <iostream>

using namespace std;
class invalidOpertator : exception
{
public:
    void print()
    {
        cout << "Enter a valid operator\n";
    }
};
RNA::RNA()
{
    //ctor
}

RNA::~RNA()
{
    //ctor
}

void RNA::Print()
{
    DNA D;
    cout<<D.ConvertToRNA().seq;
}

DNA RNA::ConvertToDNA()
{
loop5:
    //Try and catch if the input is wrong
    try
    {
        cin>>seq;
        int i=0;
        for (int i=0; i<seq.length(); i++)
        {
            if(seq[i] != 'A' && seq[i]  != 'C' && seq[i]  != 'G' && seq[i]  != 'U')
                throw  invalidOpertator();
        }
    }
    catch (invalidOpertator e)
    {
        e.print();
        cout << "Enter the sequence you want to enter : ";
        goto loop5;
    }
    DNA D;
    for (int i=0 ; i<seq.length() ; i++)                //Loop that check if there is U to convert it to T
    {
        if (seq[i] == 'U')
        {
            D.seq += 'T';
        }
        else
        {
            D.seq +=seq[i];
        }
    }
    cout << D.seq;
    return D;
}

Protein RNA::ConvertToProtein(CodonsTable & table)
{
    Codon C;
loop6:
    try
    {
        cin>>seq;
        int i=0;
        for (int i=0; i<seq.length(); i++)
        {
            if(seq[i] != 'A' && seq[i]  != 'C' && seq[i]  != 'G' && seq[i]  != 'U')
                throw  invalidOpertator();
        }
    }
    catch (invalidOpertator e)
    {
        e.print();
        cout << "Enter the sequence you want to enter : ";
        goto loop6;
    }
    Protein P;
    string value="";
    int len = seq.length();
    int l = 0 ;
    for (int i=0 ; i<len/3 ; i++)               //Divide the length of the string into values of 3 chars
    {
        for (int j=0 ; j<3 ; j++)               //Check if the 3 chars has AminoAcid
        {
            value = value + seq[l];
            l+=1;
        }
        C = table.getAminoAcid(value);
        P.seq = P.seq + C.AminoAcid;
        value="";

    }
    cout << P.seq;
    return P;
}
