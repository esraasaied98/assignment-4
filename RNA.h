#ifndef RNA_H
#define RNA_H
#include "CodonsTable.h"
#include "Sequence.h"
#include "Protein.h"
#include "DNA.h"
#include <iostream>
using namespace std;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class Protein ;
class DNA;
class RNA : public Sequence
{
    public:
        RNA();
        RNA (string seq, RNA_Type atype);
        RNA( const RNA& rhs);
        void  show ();
        string ConvertToDNA();
        string ConverToProtein ();
        void Print();
        string check();
        void LoadFile();
        void SaveFile ();
        friend ostream& operator << (ostream &out, RNA r );
        friend istream &operator >> (istream &in, RNA& r);
       // Protein ConvertToProtein(const CodonsTable & table);

        virtual ~RNA();

    protected:

    private:
        RNA_Type type;
        RNA*complementarystrand;
};
ostream& operator << (ostream &out, RNA r );
istream &operator >> (istream &in, RNA& r);

#endif // RNA_H
