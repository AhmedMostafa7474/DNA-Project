#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Sequence.h"
//#include "RNA.h"

#include <string>
#include <iostream>

using namespace std;

class Sequence
{
protected:

public:
    string seq;
    // constructors and destructor
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    void setseq();
    virtual ~Sequence();
    // pure virtual function that should be overridden because every
    // type of sequence has its own details to be printed
    virtual void Print()= 0;
    void print2();
    // friend function that will find the LCS (longest common
    // subsequence) between 2 sequences of any type, according to
    // polymorphism
    friend string Align(Sequence * s1, Sequence * s2);
    friend ostream& operator<< (ostream& out,Sequence & s);
    friend istream& operator>> (istream& in,Sequence & s);
    friend bool operator== (Sequence &s1,Sequence &s2);
    friend bool operator!= (Sequence &s1,Sequence& s2);
    friend void operator+ (Sequence &s1,Sequence& s2);

};

#endif // SEQUENCE_H
