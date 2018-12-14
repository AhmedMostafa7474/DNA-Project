#ifndef PROTEIN_H
#define PROTEIN_H

#include "Sequence.h"

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
class DNA;
class Protein : public Sequence
{
private:
    Protein_Type type;
public:
    // constructors and destructor
    Protein();
    Protein(char * p);
    ~Protein();
    void Print();
    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    DNA* GetDNAStrandsEncodingMe( DNA & bigDNA);
};
#endif // PROTEIN_H
