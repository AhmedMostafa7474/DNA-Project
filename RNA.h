#ifndef RNA_H
#define RNA_H

#include <iostream>
#include <string>
#include <fstream>

#include "Sequence.h"
#include "CodonsTable.h"
#include "Protein.h"

using namespace std;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class DNA;
class Protein;

class RNA : public Sequence
{
private:
    RNA_Type type;
public:
    // constructors and destructor
    RNA();
    RNA(string seq, RNA_Type atype);
    RNA(RNA& rhs);
    ~RNA();
    // function to be overridden to print all the RNA information
    void Print();
    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    Protein ConvertToProtein(CodonsTable & table);
    // function to convert the RNA sequence back to DNA
    DNA ConvertToDNA();
};

#endif // RNA_H
