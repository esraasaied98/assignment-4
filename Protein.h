#ifndef PROTEIN_H
#define PROTEIN_H
#include "Protein.h"
#include "DNA.h"
#include <iostream>
using namespace std;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
    private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p);
 	 	string  ConverToProtein();
 	 	void  Print();
 	 	void  show();
 	 	friend ostream& operator << (ostream &out, Protein p );
 	 	friend istream& operator >> (istream &in, Protein &p );
 	 	~Protein();

 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
           DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
};
ostream& operator << (ostream &out, Protein p );
istream& operator >> (istream &in, Protein &p );
#endif // PROTEIN_H
