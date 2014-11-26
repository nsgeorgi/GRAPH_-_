#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Hashtable.h"
#include "Node.h"
#include "ID.h"
#include <queue>
#include <time.h>

using namespace std;

int main()
{
string str;
char a[256];
fstream myfile;
myfile.open("commands.txt"); // Προσπαθούμε να ανοίξουμε το αρχείο "commmands.txt"
    if (!myfile) // Αν το f πάρει τιμή false τότε το αρχείο δεν άνοιξε
    {
    cerr<<"Could not open file"<<endl;
    }
    else
    cout<<"File opened succesfully"<<endl;

getline(myfile,str,' ');

myfile.getline(a,256);
cout<<a<<endl;
Hashtable h(100.000);//dinoume ws parametro to size tou hashtable
h.insert_all_data(a);   // EKXWROUME STO HASHTABLE  OLA TA ID POU IPARXOUN STO ARXEIO

getline(myfile,str,' ');
int key;
int key2;
int key3;

ofstream myfile2;  //ANOIGW TO OUTPUT.TXT GIA NA GRAPSW TO MST KAI M&M
myfile2.open("output.txt");
    if (!myfile2) // Αν το f πάρει τιμή false τότε το αρχείο δεν άνοιξε
    {
    cerr<<"Could not open file"<<endl;
    }
    else
    cout<<"File opened succesfully"<<endl;

    while (!myfile.eof( ))      //if not at end of file, continue reading numbers
     {
         if (str.compare("INSERT_LINK")==0)   //EISAGWGI STOIXEIOU
            {

            myfile>>key;
            myfile>>key2;
            myfile>>key3;

            h.insert(key,key2,key3);
            }

           //THELEI TAKSINOMISI I LISTA !!!
        else if (str.compare("DELETE_LINK")==0) //DIAGRAFI STOIXEIOU
            {

            myfile>>key;
            myfile>>key2;

            h.delete_(key,key2);
            h.delete_(key2,key);
            }

        else if (str.compare("MST")==0) // elaxisto dentro
            {

            double duration;

            clock_t start;
            start = clock();
            myfile2<<"MST  "<< h.prim();
           duration=(clock() - start) / (double) CLOCKS_PER_SEC;
           myfile2<<"  it took "<<duration<<" seconds to find minimum spanning tree"<<endl;
            }
        else  if (str.compare("NCN")==0)   // mutual friends duo korufwn
            {

                myfile>>key;
                myfile>>key2;
                myfile2<<"NCN  "<<h.merging(key,key2)<<" mutuals of ["<<key<<"  "<<key2<<"]"<<endl;
            }
        myfile.getline(a,256);
        getline(myfile,str,' ');


     }

    myfile.close();
    myfile2.close();
    system("PAUSE");
    return 0;
}
