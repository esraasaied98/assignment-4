#include "RNA.h"
#include "DNA.h"
#include <iostream>
#include <fstream>
using namespace std;

RNA::RNA()
{
    //ctor
}
RNA :: RNA (string seq, RNA_Type atype)

        {
            this -> seq = seq;
            this -> type = atype;
        }

RNA :: RNA( const RNA& rhs){
            this -> seq = rhs.seq;
            this -> type = rhs.type;
        }

void RNA :: show (){
 	 	cout<<"Enter Your  RNA Sequence "<<endl;
 	 	cin>>seq;
 	 	}

 void RNA ::  Print()
 {
        cerr <<" Your Sequence is: " << seq << endl << "Type: " << type << endl ;
    }
 string RNA :: check()
    {
        for(int i=0 ; i<seq.size(); i++)
        {
            try
            {
                if (seq[i]!= 'A'|| seq[i]!= 'C'||seq[i]!= 'T'||seq[i]!= 'G'||seq[i]!= 'U')
                {
                    throw " you should enter this character only (A,B,T,C,G,U) : " ;

                }

            }
            catch( char const * e)
            {
                cout<< e << " (error) "<<endl;
            }
            break;

        }
    }

void RNA :: LoadFile()
    {
        string letter ;
        ifstream file; // build object file
        file.open("RNARead.txt"); //open file
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
void RNA :: SaveFile ()
    {
        ofstream file ("RNAFile.text");
        file<<ConvertToDNA();
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



 string  RNA :: ConvertToDNA()
    {
        complementarystrand = new RNA (); // create new space in the memory
        complementarystrand -> seq = seq;
        for ( int i =0 ; i < seq.length() ; i++)
        {

            if (seq[i]== 'U')
                complementarystrand->seq[i]= 'T';
        }
        for (int i =0 ; i <seq.length() ; i++)
        {
            if (seq[i]== 'A')
                complementarystrand->seq[i] ='T' ;
            else if (seq[i] == 'T')
                complementarystrand->seq[i]= 'A';
            else if (seq[i] == 'C')
                complementarystrand->seq[i]= 'G';
            else if (seq[i] == 'G')
                complementarystrand->seq[i]= 'C';
        }



        for ( int i=0 ; i < seq.length() / 2 ; i++)
        {
            char temp = complementarystrand->seq[i];
            complementarystrand->seq[i] = complementarystrand->seq[(seq.length() - 1) - i];
            complementarystrand->seq[(seq.length() - 1)- i] = temp;

        }



    cout<< "What Is The Type Of RNA"<< endl;
    cout<< "1. mRNA" << endl << "2. pre_mRNA " << endl<< "3. mRNA_exon " << endl<< "4. mRNA_intron"<< endl;
   RNA_Type type[4]={mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
    int t;
    cin>> t;
    cout<< type[t]<< endl;

    return complementarystrand->seq ;
        }

string RNA :: ConverToProtein ()
    {
       complementarystrand = new RNA (); // create new space in the memory
        complementarystrand -> seq = seq;
        for (int i=0 ; i<seq.length(); i++)
        {
            if (seq[i]== 'A')
                cout<< "A convert to :  "<< "GCU" << " "<< "GCG"<< " "<< "GCC"<< " "
                    << "GCA"<<endl;
            if (seq[i]== 'K')
                cout<< "K convert to : "<< "AAA"<< " "<<"AAG"<<endl;
            if (seq[i]== 'N')
                cout<< "N convert to : "<< "AAC" << " "<< "AAU"<<endl;
            if (seq[i]== 'T')
                cout<< "T convert to : "<< "ACU" << " "<< "ACG"<< " "<< "ACC"<< " "
                    << "ACA"<<endl;
            if (seq[i]== 'R')
                cout<< "R convert to : "<< "AGA" << " "<< "AGG"<< " "<< "CGA"<< " "
                    << "CGC"<<"CGG"<<"CGU"<<endl;
            if (seq[i]== 'S')
                cout<< "S convert to : "<< "AGC" << " "<< "AGU"<< " "<< "UCA"<< " "
                    << "UCC"<<" "<<"UCG"<<" "<<"UCU"<<endl;
            if (seq[i]== 'I')
                cout<< "I convert to : "<< "AUC" << " "<< "AUU"<<" "<< "AUA"<<endl;
            if (seq[i]== 'M')
                cout<< "M convert to : "<< "AUG"<<endl;
            if (seq[i]== 'Q')
                cout<< "Q convert to : "<< "CAA" << " "<< "CAG"<<endl;
            if (seq[i]== 'P')
                cout<< "P convert to : "<< "CCA" << " "<< "CCC"<< " "<< "CCG"<< " "
                    << "CCU"<<endl;
            if (seq[i]== 'L')
                cout<< "L convert to : "<< "CUA" << " "<< "CUC"<< " "<< "CUG"<< " "
                    << "CUU"<<" "<<"UUA"<<" "<<"UUG"<<endl;
            if (seq[i]== 'E')
                cout<< "E convert to : "<< "GAA" << " "<< "GAG"<<endl;
            if (seq[i]== 'D')
                cout<< "D convert to : "<< "GAC" << " "<< "GAU"<<endl;
            if (seq[i]== 'G')
                cout<< "G convert to : "<< "GGA" << " "<< "GGC"<< " "<< "GGG"<< " "
                    << "GGU"<<endl;
            if (seq[i]== 'V')
                cout<< "V convert to : "<< "GUA" << " "<< "GUC"<< " "<< "GUG"<< " "
                    << "GUU"<<endl;
            if (seq[i]== 'Y')
                cout<< "Y convert to : "<< "UAC" << " "<< "UAU"<<endl;
            if (seq[i]== 'C')
                cout<< "C convert to : "<< "UGC" << " "<< "UGU"<<endl;
            if (seq[i]== 'W')
                cout<< "W convert to : "<< "UGG"<<endl;
            if (seq[i]== 'F')
                cout<< "F convert to : "<< "UUC" << " "<< "UUU"<<endl;
        }
        return complementarystrand->seq;
    }


ostream& operator << (ostream &out, RNA r ){
out<< r.seq;
return out;

}
istream &operator >> (istream &in, RNA& r)
    {
        in >> r.seq;
        return in;
    }

//        Protein :: RNA ConvertToProtein(const CodonsTable & table);

RNA::~RNA()
{
    //dtor
}
