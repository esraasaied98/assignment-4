#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include <iostream>
using namespace std;

struct Codon
{
    char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};
class CodonsTable {
private:
        Codon codons[64];
   	public:
   	    string cod ;
    string cod2;
    int counter = 0;
 	 	// constructors and destructor
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile();
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);
        friend ostream& operator << (ostream &out, CodonsTable c );
};
ostream& operator << (ostream &out, CodonsTable c );

#endif // CODONSTABLE_H
