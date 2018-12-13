#include <iostream>
#include<cstring>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "CodonsTable.h"
#include "Protein.h"


using namespace std;

int main()
{
    /* DNA s;
    /// DNA_Type a[]={promoter, motif, tail, noncoding};
     cout<< "Enter Your  Sequence: " << endl;
     cin>> s;

     cout<< "Your Sequence Is: " << s<<endl;
     cout<< "The DNA Is: "<<s.BuildComplementaryStrand()<< endl;
     cout<< "The RNA Is: " << s.ConvertToRNA()<< endl;
    */

    int choice ;
    DNA s;
    RNA o ;
    Protein p;
    CodonsTable c ;
    cout<< "Hello User What Do You Want ? \n(1)Convert Your Sequence From DNA to RNA Choose. \n(2)Convert Your Sequence From RNA to DNA. \n"
        << "(3)Read From File To Show To You The Code Table.\n"<< "(4)Convert Your Sequence To Protein.\n"<<"*************************************************\n"
        <<"Now Choose What Do You Want! "<<endl;
    cin>>choice;
    if (choice==1 )
    {
        int c;
        cout<< "Please Press\n(1)If You Want To Convert And Show It For You \n"<< "(2)If You Want To Load From File And Convert \n"
            << "(3)If You Want To Save File After Convert \n"<<"**************************************************"<<endl;
        cin>>c;
        if (c==1)
        {
            cout<< " Enter Your Sequence From DNA To RNA "<<endl;
            cin>>s;
            s.check();
            cout<< "Complementary Is : " << s.BuildComplementaryStrand()<<endl;
            cout<<"The Sequence After Converted  : "<< s.ConvertToRNA()<<endl;

        }
        else if (c==2)
        {
            s.LoadFile();
            cout<<endl;
            cout<< "Complementary Is : " << s.BuildComplementaryStrand()<<endl;
            cout<<"The Sequence After Converted  : "<< s.ConvertToRNA()<<endl;

        }
        else if (c==3)
        {
            cout<< "Enter Your Sequence From DNA To RNA "<<endl;
            cin>>s;
            cout<< "Complementary Is : " << s.BuildComplementaryStrand()<<endl;
            cout<<"The Sequence After Converted  : "<< s.ConvertToRNA()<<endl;
            s.SaveFile();

        }
        else if(choice==4)
        {
            cout << "Enter Your Sequence To Convert To Protein "<<endl;
            cin>>p;
            cout<< "Converted To : "<< " ";
            cout<< p.ConverToProtein()<<endl;
        }
    }
    else if (choice==2)
    {
        int h;
        cout << "What Do You Want Here \n"<<"(1)Convert To DNA And Show It To User\n"
             <<"(2)Load From File And Convert To DNA\n"<<"(3)Save File After Convert DNA In File\n"
             <<"(4)Convert To Protein And Show It To User"<<endl;
        cin>>h;
        if (h==1)
        {
            cout << "Enter Your Sequence To Convert From RNA To DNA "<<endl;
            cin >> o;
            cout<< "The Sequence After Converted  " <<  o.ConvertToDNA()<<endl;

        }
        else if (h==2)
        {
            o.LoadFile();
            cout<<endl;
            cout<< "The Sequence After Converted  " <<  o.ConvertToDNA()<<endl;
        }
        else if (h==3)
        {
            cout << "Enter Your Sequence To Convert From RNA To DNA "<<endl;
            cin >> o;
            cout<< "The Sequence After Converted  " <<  o.ConvertToDNA()<<endl;
            o.SaveFile();
        }
        else if (h==4)
        {
            cout << "Enter Your Sequence To Convert From RNA To DNA "<<endl;
            cin >> o;
            o.ConverToProtein();
        }

    }
    else if (choice==3 )
    {
        c.LoadCodonsFromFile();
    }
    else if (choice==4)
    {
        cout<< "enter your seq "<<endl;
        cin>>p;
        p.ConverToProtein();
    }
    /*
    Sequence* s1;
    Sequence* s2;
    s1 = new DNA("aaatb",motif);
    s2 = new DNA("atbc",motif);
    Align(s1,s2);
    cout<<2;*/




    return 0;
}
