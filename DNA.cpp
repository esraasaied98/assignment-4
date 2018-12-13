#include "DNA.h"
#include "RNA.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class RNA;

DNA::DNA()
{
    //ctor
}

DNA :: DNA(string seq, DNA_Type atype)
{

     this -> seq = seq;
     this -> type = atype;

}


DNA :: DNA(const DNA& rhs)
{
    seq = rhs.seq;
    type = rhs.type;
    startIndex = rhs.startIndex;
    endIndex = rhs.endIndex;
}

void DNA :: show ()
{
    cout<< "Enter Your  DNA Sequence "<<endl;
    cin>>seq;
}

void DNA :: Print()
{
    // cerr << "Type: " << type << endl
    cout  << "Your Sequence Is : " << seq << endl << "The DNA Is : " << complementary_strand->seq << endl ;

}

string DNA :: ConvertToRNA()
{
    complementary_strand = new DNA() ; //msa7a gdeda f memory
    complementary_strand -> seq = seq;
    for(int i =0 ; i < seq.length(); i++)
    {
        if (seq[i] == 'T')
            complementary_strand->seq[i]= 'U';

    }
    for ( int i=0 ; i < seq.length() / 2 ; i++)
    {
        char temp = complementary_strand->seq[i];
        complementary_strand->seq[i] = complementary_strand->seq[(seq.length() - 1) - i];
        complementary_strand->seq[(seq.length() - 1)- i] = temp;
    }

    return complementary_strand->seq;
}


string  DNA :: BuildComplementaryStrand()
{
    complementary_strand = new DNA (); //msa7a gdeda f memory
    complementary_strand -> seq = seq;

    for(int i =0 ; i < seq.length(); i++)
    {
        if (seq[i]== 'A')
            complementary_strand->seq[i] ='T' ;
        else if (seq[i] == 'T')
            complementary_strand->seq[i]= 'A';
        else if (seq[i] == 'C')
            complementary_strand->seq[i]= 'G';
        else if (seq[i] == 'G')
            complementary_strand->seq[i]= 'C';
    }

    for ( int i=0 ; i < seq.length() / 2 ; i++)
    {
        char temp = complementary_strand->seq[i];
        complementary_strand->seq[i] = complementary_strand->seq[(seq.length() - 1) - i];
        complementary_strand->seq[(seq.length() - 1)- i] = temp;

    }
    cout<< "What Is The Type"<< endl;
    cout<< "1. promoter" << endl << "2. motif " << endl<< "3. tail " << endl<< "4. noncoding"<< endl;
   DNA_Type type[4]={promoter, motif, tail, noncoding};
    int t;
    cin>> t;
    cout<< type[t]<< endl;




    return complementary_strand->seq;

}
void DNA :: SaveFile ()
    {
        ofstream file ("DNAFile.text");
        file<<BuildComplementaryStrand()<<endl<<ConvertToRNA();
        if(file.is_open())
        {
            cout<< "file is open "<<endl;

        }
        else
        {
            cout<< "file not open "<<endl;
        }
        file.close();

    }
void DNA :: LoadFile()
    {
        string letter ;
        ifstream file; // build object file
        file.open("DNARead.txt"); //open file
        if(file.good()) // check if file exist or not
        {
            cout<< "the file is exist  : "<<endl;
            while(!file.eof())  // loop in character in file if arrive to the end will stop
            {
                getline(file,letter);   // read space and character in file
            }
            seq=letter;
            cout<<"the seq in file is: "<<seq;
        }
    }
    string DNA :: check()
    {
        for(int i=0 ; i<seq.size(); i++)
        {
            try
            {
                if (seq[i]!= 'A'|| seq[i]!= 'C'||seq[i]!= 'T'||seq[i]!= 'G')
                {
                    throw " you should enter this character only (A,B,T,C,G) : " ;

                }

            }
            catch( char const * e)
            {
                cout<< e << " (error) "<<endl;
            }
            break;
        }
    }




ostream& operator << (ostream &out, DNA d )
{
    out<< d.seq ;

    return out;

}
istream &operator >> (istream &in, DNA& d)
{
    in >> d.seq;

    return in;
}

DNA::~DNA()
{
    //dtor
}
