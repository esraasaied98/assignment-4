#include "Sequence.h"
#include <iostream>
using namespace std;

Sequence::Sequence()
{
    //ctor
}

Sequence :: Sequence (string s)
    {
            this-> seq = s;
    }

/* Sequence& operator=(const  seq& rhs)
    {
       Sequence temp(rhs);
       std::swap(seq, temp.seq);
       return *this;
    }*/

/* Sequence(const Sequence& rhs)
    {

    }
    void setStr(char * s)
    {
       Sequence temp(s);
       *this = temp;
    }*/


void  Sequence :: show ()
{
            cout << "Enter Your Sequence "<<endl;
            cin>>seq;
        }

string  Align(Sequence * s1, Sequence * s2)
    {   int n=s1->seq.size();
     int m=s2->seq.size();
    int L[m+1][n+1];

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
     for (int i=0; i<=m; i++)
     {
       for (int j=0; j<=n; j++)
       {
         if (i == 0 || j == 0)
           L[i][j] = 0;
         else if (s1->seq[i-1] == s2->seq[j-1])
           L[i][j] = L[i-1][j-1] + 1;
         else
           L[i][j] = max(L[i-1][j], L[i][j-1]);
       }
     }

     // Following code is used to print LCS
     int index = L[m][n];

     // Create a character array to store the lcs string
     char lcs[index+1];
     lcs[index] = ' '; // Set the terminating character

     // Start from the right-most-bottom-most corner and
     // one by one store characters in lcs[]
     int i = m, j = n;
     while (i > 0 && j > 0)
     {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (s1->seq[i-1] == s2->seq[j-1])
        {
            lcs[index-1] = s1->seq[i-1]; // Put current character in result
            i--; j--; index--;     // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger va

        else if (L[i-1][j] > L[i][j-1])
           i--;
        else
           j--;
     }

     // Print the lcs
     cout << "LCS of " << s1->seq << " and " << s2->seq << " is " << lcs;
    return lcs;
    }

Sequence::~Sequence()
{
    //dtor
}
