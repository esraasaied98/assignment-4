#include "CodonsTable.h"
#include <iostream>
#include <fstream>
using namespace std;



CodonsTable::CodonsTable()
{
    //ctor
}

void CodonsTable:: LoadCodonsFromFile()
    {
        ifstream file; // build object file
        file.open("RNA_codon_table.txt"); //open file
        if(file.good()) // check if file exist or not
        {
            cout<< " the file is exist  : "<<endl;
            while(!file.eof())  // loop in character in file if arrive to the end will stop
            {
                getline(file,cod); // read space and character in file
                for(int i=0 ;  i<3 ; i++ ) // loop every three character and set it in one index
                {
                    codons[counter].value[i]=cod[i];
                }


                codons[counter].AminoAcid = cod[4]; // set the fourth character in amino acid

                for (int i=0 ; i< 3 ; i++)  // loop the three character to show it to user
                {
                    cout << codons[counter].value[i];
                }
                cout<< "  "<<codons[counter].AminoAcid<<endl;
                counter++;
                cout <<endl;

            }
        }
        file.close(); //close file
    }

/*ostream& operator << (ostream &out, CodonsTable c ) //show the function
    {
        out<<  c.LoadCodonsFromFile();
        return out;

    }*/


    Codon getAminoAcid(char * value){}
    void setCodon(char * value, char AminoAcid, int index){}





CodonsTable::~CodonsTable()
{
    //dtor
}
