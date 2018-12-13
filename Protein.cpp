#include "Protein.h"
#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

Protein::Protein()
{
    //ctor
}

string s;
    int c = 0 ;
    vector<string> arr;

    string Protein :: ConverToProtein()
    {
        cout<< seq.length()<<endl;
        for (int i =0 ; i<seq.length() ; i+=3)
        {
            if(seq.substr(i,3).size()<3)
                break; // chose first three character and set it in index
            arr.push_back(seq.substr(i,3)); // increase vector of array

        }

        for (int i =0 ; i<arr.size() ; i++)
        {
            if (arr[i]=="STP")
                break;


            if(arr[i]=="AAA"||arr[i]=="AAG")
                arr[i]="K";
            if(arr[i]=="AAC"||arr[i]=="AAU")
                arr[i]="N";
            if(arr[i]=="ACA"||arr[i]=="ACC"||arr[i]=="ACU"||arr[i]=="ACG")
                arr[i]="T";
            if(arr[i]=="AGA"||arr[i]=="AGG"||arr[i]=="CGA"||arr[i]=="CGC"||arr[i]=="CGG"||arr[i]=="CGU")
                arr[i]="R";
            if(arr[i]=="AGC"||arr[i]=="AGU"||arr[i]=="UCA"||arr[i]=="UCC"||arr[i]=="UCG"||arr[i]=="UCU")
                arr[i]="S";
            if(arr[i]=="AUG")
                arr[i]="M";
            if(arr[i]=="CAA"||arr[i]=="CAG")
                arr[i]="Q";
            if(arr[i]=="CAC")
                arr[i]="H";
            if(arr[i]=="CCA"||arr[i]=="CCC"||arr[i]=="CCU"||arr[i]=="CCG")
                arr[i]="P";
            if(arr[i]=="CUA"||arr[i]=="CUC"||arr[i]=="CUU"||arr[i]=="CUG"||arr[i]=="UUG"||arr[i]=="UAA")
                arr[i]="L";
            if(arr[i]=="GAA"||arr[i]=="GAG")
                arr[i]="E";
            if(arr[i]=="GAC"||arr[i]=="GAU")
                arr[i]="D";
            if(arr[i]=="GCA"||arr[i]=="GCC"||arr[i]=="GCU"||arr[i]=="GCG")
                arr[i]="A";
            if(arr[i]=="GGA"||arr[i]=="GGC"||arr[i]=="GGU"||arr[i]=="GGG")
                arr[i]="G";
            if(arr[i]=="GUA"||arr[i]=="GUC"||arr[i]=="GUG"||arr[i]=="GUU")
                arr[i]="V";
            if(arr[i]=="UAC"||arr[i]=="UAU")
                arr[i]="Y";
            if(arr[i]=="UGC"||arr[i]=="UGU")
                arr[i]="C";
            if(arr[i]=="UGG")
                arr[i]="W";
            if(arr[i]=="UAG"||arr[i]=="UGA"||arr[i]=="UAA")
                arr[i]=" ";

            cout<<arr[i]<< " " ;
        }


    }

    void Protein :: Print()
    {
        cout<< ConverToProtein();
    }
    void  Protein :: show()
    {
        cin>> seq;

    }
    // constructors and destructor


    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA)
    {




    }

ostream& operator << (ostream &out, Protein p )
    {
        out<<p.seq;
        return out;

    }
istream& operator >> (istream &in, Protein &p )
    {
        in>> p.seq;
        return in ;

    }


Protein::~Protein()
{
    //dtor
}
