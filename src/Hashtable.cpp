#include "Hashtable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
Hashtable::Hashtable(int s)
{

  size=s;
   ht=new ID[s];
  empty= new bool [s];
  for (int i=0; i<s; i++)
  empty[i]=true;

}

Hashtable::~Hashtable()
{
   delete [] ht;
   delete [] empty;
}


void Hashtable::insert_all_data(char s[])
{
fstream myfile1;
myfile1.open(s); // apo edw kai katw asxoloumai mono me to input.txt
    if (!myfile1)
    {
    cerr<<"Could not open file"<<endl;
    }
    else
    cout<<"File opened succesfully"<<endl;


while (!myfile1.eof( ))
{
    int key; //to prwto id
    int key2; // to diplano id pou tha kanei akmi me to prwto
    int key3;  // to varos tis akmis
    myfile1>>key;   //diavazei to id apo to arxeio
    int b;
    b=search(key);
    if (empty[b])     //otan to stoixeio key den uparxei ston pinaka me ta ID tote to ekxwrw
    {
        empty[b]=false;
        ht[b].element=key;
        myfile1>>key2;  //diavazoume twra to stoixeio me to opoio tha dimiourgisei akmi to key
        myfile1>>key3;
        ht[b].add_node_to_list(key2,key3); // kai to ekxwroume stin lista tou sugkekrimenou id
    }
     else if (ht[b].element==key)
    {
    myfile1>>key2;
    myfile1>>key3;
    ht[b].add_node_to_list(key2,key3);
    }

    //KANW AKRIVWS TIN IDIA DIADIKASIA KAI ME TO ALLO ID  EPEIDI EINAI MH KATEUTHINOMENO GRAFIMA
    //DILADI OPOU EIXA TO KEY BAZW TO KEY2 KAI TO ANTITHETO
     b=search(key2);
    if (empty[b])     //otan to stoixeio key den uparxei ston pinaka me ta ID tote to ekxwrw
    {
        empty[b]=false;
        ht[b].element=key2;
        ht[b].add_node_to_list(key,key3); // kai to ekxwroume stin lista tou sugkekrimenou id

    }

     else if (ht[b].element==key2)
    {
    ht[b].add_node_to_list(key,key3);
    }

}
  for (int i=0; i<size; i++)  //taksinomisi kathe listas tou hashtable
  {
      Node *temp;
      temp=ht[i].list_head;
      if (empty[i]==false)
      {
      ht[i].sort_list(); //taksinomisi bubblesort

      while (ht[i].list_head!=NULL)
      {


      ht[i].list_head=ht[i].list_head->next;
      }

      ht[i].list_head=temp;
      }
  }

    myfile1.close();
}


void Hashtable::insert(int key,int key2,int key3)
{
    int b;
    b=search(key);
    if (empty[b])     //otan to stoixeio key den uparxei ston pinaka me ta ID tote to ekxwrw
    {
        empty[b]=false;
        ht[b].element=key;
        ht[b].add_node_to_list(key2,key3); // kai to ekxwroume stin lista tou sugkekrimenou id
    }
    if (ht[b].element==key)
    {
    ht[b].add_node_to_list(key2,key3);
    }
    //KANW AKRIVWS TIN IDIA DIADIKASIA KAI ME TO ALLO ID  EPEIDI EINAI MH KATEUTHINOMENO GRAFIMA
    //DILADI OPOU EIXA TO KEY BAZW TO KEY2 KAI TO ANTITHETO
    ht[b].sort_list();
     b=search(key2);
    if (empty[b])     //otan to stoixeio key den uparxei ston pinaka me ta ID tote to ekxwrw
    {
        empty[b]=false;
        ht[b].element=key2;
        ht[b].add_node_to_list(key,key3); // kai to ekxwroume stin lista tou sugkekrimenou id
    }
    if (ht[b].element==key2)
    {
    ht[b].add_node_to_list(key,key3);
    }
    ht[b].sort_list();
}



int  Hashtable::search(int k)
{

    int tmp;
    tmp=(k%(size/2));   //home bucket
    int j=tmp;  //start at home bucket
    do{
    if (empty[j] || ht[j].element==k ) return j;
    j=(j+1)%size; //next bucket
    }while (j!=tmp); //returned to home ?
    return j; //table full
}


void Hashtable::delete_(int key,int key2)
{
    int b;
    b=search(key); //anazitw tin thesi tou kleidiou
    if (!empty[b])     //otan to stoixeio key uparxei ston pinaka me ta ID tote  diagrafw ton geitona tou
    {
        empty[b]=true;
     ht[b].delete_node_from_list(key2);
    }

    //akolouthw tin idia diadikasia gia to antitheto zeugari
    b=search(key2);
    if (!empty[b])

    {
        empty[b]=true;
     ht[b].delete_node_from_list(key);
    }


}



int Hashtable::prim()
{
    bool flag=false; // simaia
    int k=1;
    int m=0;
    int min_cost=0; // elaxisto dentro
    int current=0;
    int visited[50000]; //komboi pou exoume episkeftei
    for (int i=0 ; i<size; i++) //psaxnoume na vroume enan komvo gia  na arxisoume na ftiaxnoune
    {                           //to elaxisto dentro . molis vroume enan tuxaio kombo tote ton ekxwroume
                                //ston pinaka visited kai vazoume -1 oles tis alles theseis
        if (empty[i]==false)
        {
            current=i;
         visited[0]=ht[current].element;
         break;
        }
    }

    for (int i=1; i<50000; i++)
    {
        visited[i]=-1;
    }
     struct N n;

    priority_queue<N> q;        //oura proteraiotitas gia na dialegoume kathe fora tin akmi me to elaxisto kostos
    for (int i=0; i<size; i++)
    {
        Node *temp=ht[current].list_head;
        while(ht[current].list_head!=NULL)  // ston kombo pou briskomai mpainw stin lista me tous geitones tou
       {                                    // kai gia kathe geitona ftiaxnw ena struct
            n.value=ht[current].list_head->data;
            n.w=ht[current].list_head->weight;
            ht[current].list_head=ht[current].list_head->next;
            do
            {
               if (n.value==visited[m])  //ama to struct to exoume episkefthei ksana tote den to
               {                         //ekxwrw stin oura alliws  to kanw push
                   flag=true;
                   break;
               }

               m++;
            }while(visited[m]!=-1);
            m=0;
            if (flag==false) {q.push(n);  }
            flag=false;
        }

        ht[current].list_head=temp;

        do
            {
               if (q.top().value==visited[m] && !q.empty()) // kanw elegxw an  to elaxisto kostos  pou tha dialeksw, to exw ksanaepiskefthei
               {

                   q.pop(); // an nai , tote kanw pop kai pernw to epomeno ws elaxisto kostos
                   m=0;
                   continue;
               }

               m++;
            }while(visited[m]!=-1);
            m=0;

             if (q.empty()) { break; }  //termatiki sunthiki algorithmou

        min_cost=min_cost+q.top().w; // prosthetw sto elaxisto kostos to baros tou elaxistou stoixeia tis ouras
        visited[k]=q.top().value; // to elaxisto stoixeio to vazw ws stoixeio pou exw episkefthei kai meta tha to kanw pop
        k++;

        current=search(q.top().value); //current tha ginei o kombos pou epeleksa apo tin oura
        q.pop(); //kai kanw pop to stoixeio pou eixa epileksei apo tin oura proteraiotitas
    }
q = priority_queue <N>(); // kanw reset tin oura
    return min_cost;  //epistrefw to elaxisto kostos
}


int Hashtable::merging(int key,int key2)
{
    int k,k2;
    Node *temp,*temp2;
    int mutuals=0;
    k=search(key); // psaxnw tin thesi tou prwtou kleidiou
    k2=search(key2); // psaxnw tin thesi tou deuterou kleidiou
    temp=ht[k].list_head;
    temp2=ht[k2].list_head;
    while(ht[k].list_head!=NULL && ht[k2].list_head!=NULL)
    {

        if (ht[k].list_head->data == ht[k2].list_head->data) // an exoun ton idio kombo tote
        {    //paw sto epomeno stoixeio kai apo tis 2 alusides
        ht[k].list_head=ht[k].list_head->next;
        ht[k2].list_head=ht[k2].list_head->next;
        mutuals++;  //oi mutuals auksanontai kata 1
        }
        else if (ht[k].list_head->data < ht[k2].list_head->data)
        { //metakinoumaste kathe fora tin alusida pou periexei megalutero stoixeio se sugkrisi metin alli
            ht[k].list_head=ht[k].list_head->next;
        }
        else
         ht[k2].list_head=ht[k2].list_head->next;
    }
    ht[k].list_head=temp;
    ht[k2].list_head=temp2;
    return mutuals;
}
