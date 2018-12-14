#include "Sequence.h"
#include "RNA.h"
#include "DNA.h"
class invalidOpertator : exception
{
public:
    void print()
    {
        cout << "Enter a valid operator\n";
    }
};
Sequence::Sequence()
{
    //ctor
}

Sequence::~Sequence()
{

}

void Sequence::print2()
{
    //Objects of all classes needed
    Protein P ;
    RNA R;
    DNA D;
    Codon C;
    CodonsTable CT;
    Sequence *s,*s1;
    int choose = 0,choose2 = 0,choose3= 0;
    cout << "|||||||||||||| WELCOME TO OUR BIOLOGICAL SYTEM ||||||||||||||" << endl << endl;
loop:
    cout << endl << "Enter the conversion you want to make : "<<endl;
    cout << "1-Convert from DNA to RNA" << endl;
    cout << "2-Convert from RNA to DNA" << endl;
    cout << "3-Convert from RNA to Protein" << endl;
    cout << "4-Convert DNA to complement" << endl;
    cout << "5-Convert Protein to DNA" << endl;
    cout << "6-LCS" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "Enter the sequence you want to enter : ";
        R.Print(); // Function that convert DNA to RNA
        break;
    case 2:
        cout << "Enter the sequence you want to enter : ";
        R.ConvertToDNA(); // Function that convert RNA to DNA
        break;

    case 3:
        cout << "Enter the sequence you want to enter : ";
        CT.LoadCodonsFromFile("RNA_codon_table.txt");   // Function that load the codons from the file
        R.ConvertToProtein(CT); // Function that convert RNA to Protein
        break;
    case 4:
        cout << "Enter the sequence you want to enter : ";
        D.BuildComplementaryStrand();   // Function that convert DNA to its complement
        break;

    case 5 :
        P.GetDNAStrandsEncodingMe(D);   //Function that get GigDNA and AminoAcid the get the DNA from this AminoAcid
        break;
    case 6 :
        cout << "Enter the two sequence you want to enter : ";
        Align(s,s1);    // Function that get the LCS
    }
    goto loop;
}

void Sequence::setseq()
{
    cin >> seq;
}

string Align(Sequence * s1, Sequence * s2)
{
    string seq ;
    string seq2 ;
    cout << "S1 = ";
    cin >>seq;  // get the first sequence
    cout << endl << "S2 = ";
    cin >>seq2; // get the second sequence
    int index=0;
    int j ;
    string LCS ;
    for (int i=0 ; i< seq2.length() ; i++)  //loop that loop on the size of the second sequence
    {

        for ( j=index ; j<seq.length() ; j++)   //loop that loop on the size of the first sequence
        {
            if (seq2[i]==seq[j])
            {
                LCS=LCS+seq2[i];
                index = j;
                break;
            }
        }
    }
    cout <<LCS;
    return LCS;
}

istream& operator>> (istream& in,Sequence & s)
{
    in >> s.seq;
    return in;
}


