#include "CodonsTable.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}

CodonsTable::~CodonsTable()
{

}

void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    ifstream infile;
    infile.open(codonsFileName.c_str(),ios::in);
    int i=0;
    while (infile)              //Put all the codons in the struct
    {
        infile >> codons[i].value;
        infile >> codons[i].AminoAcid;
        i++;
    }

    infile.close();
}

Codon CodonsTable::getAminoAcid(string value)               //Check each 3 chars which AminoAcid she had
{
    for (int i=0 ; i<64 ; i++)
    {
        if (value == codons[i].value)
        {
            return codons[i];
        }
    }

}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{

}

