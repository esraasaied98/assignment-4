#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>
#include <iostream>
using namespace std;


class Sequence
{
    public:
        Sequence();
        Sequence (string s);
        void show ();
        virtual void Print()= 0;
//        friend bool operator ==(Sequence s,Sequence d);
  //      friend bool operator !=(Sequence s,Sequence d);
    //    friend Sequence operator +(Sequence s,Sequence d);
        friend string Align(Sequence * s1, Sequence * s2);

        virtual ~Sequence();

    protected:
        string seq;

    private:
};
string Align(Sequence * s1, Sequence * s2);
//bool operator ==(Sequence s,Sequence d);
//bool operator !=(Sequence s,Sequence d);
//Sequence operator +(Sequence s,Sequence d);
#endif // SEQUENCE_H
