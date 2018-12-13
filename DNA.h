#ifndef DNA_H
#define DNA_H
#include <iostream>
#include "Sequence.h"
using namespace std;

class RNA;


enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
    private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;

    public:
        DNA();
        DNA(string seq, DNA_Type atype);
        DNA(const DNA& rhs);

        void show ();
        void Print();
        string check();
        void sete(DNA_Type w[]);
        string ConvertToRNA();
        string BuildComplementaryStrand();
        void LoadFile();
        void SaveFile ();
        friend ostream& operator << (ostream &out, DNA s );
        friend istream &operator >> (istream &in, DNA& s);

        virtual ~DNA();




};
ostream& operator << (ostream &out, DNA d);
istream& operator >> (istream &in, DNA& d);

#endif // DNA_H
