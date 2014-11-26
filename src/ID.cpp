#include "ID.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

ID::ID()
{
    list_head=NULL;

}

ID::~ID()
{
    //dtor
}


void ID::add_node_to_list(int d,int w)
{
    Node *temp,*neos;
    temp=list_head;
    bool flag;
    flag=false;
    while (list_head!=NULL)   //elegxw an uparxei o geitonas mesa stin lista
    {

        if (list_head->data==d)
        {

            flag=true;
            break;
        }
        list_head=list_head->next;
        }
    list_head=temp;
    if (flag==false)    //an den uparxei tote ton ekxwrw
    {
    neos=new Node;
    neos->data=d;
    neos->weight=w;
    neos->next=list_head;
    list_head=neos;
    }
}


void ID::delete_node_from_list(int d)
{
    Node *temp,*temp1;
    temp=list_head;

    while (list_head!=NULL)         //elegxw an uparxei o geitonas stin lista kai ton diagrafw
    {
        if (list_head->data==d)
        {
            temp1=list_head->next;
            delete list_head;
            list_head=temp1;
             cout<<"delete node "<<d<<"  done"<<endl;
            break;
        }
        list_head=list_head->next;
    }

    list_head=temp;


}


void ID::sort_list()  //bubble sort se lista
{
     Node *tmpPtr = list_head;  //boithitikoi deiktes
     Node *tmpNxt = list_head->next;
     Node *tmpPtr1 = list_head;
     Node *tmpNxt1 = list_head->next;
    int tmp,tmp1;
    while(tmpNxt != NULL){
           while(tmpNxt != tmpPtr){  //auksousa taksinomisi
                    if(tmpNxt->data < tmpPtr->data){ //antimetathesi twn geitonwn se periptwsi pou
                            tmp = tmpPtr->data;   //vriskontai se lathos seira
                            tmpPtr->data = tmpNxt->data;
                            tmpNxt->data = tmp;

                             tmp1 = tmpPtr1->weight; //kanw to idio kai gia ta vari
                            tmpPtr1->weight = tmpNxt1->weight;
                            tmpNxt1->weight = tmp1;
                    }
                    tmpPtr = tmpPtr->next;
                    tmpPtr1 = tmpPtr1->next;
            }
            tmpPtr = list_head;
            tmpNxt = tmpNxt->next;
            tmpPtr1 = list_head;
            tmpNxt1 = tmpNxt1->next;
    }
}


