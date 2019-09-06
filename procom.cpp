/*producer consumer problem using semaphores*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int buffer[10],bufsize,in,out,produce,consume,choice=0;
in =0;out=0;bufsize=10;
while(choice != 3)
{
  cout<<"\n1.produce \t 2.consume \t 3.Exit\n";
  cout<<"\nEnter your choice : ";
  cin>>choice;
  switch(choice)
  {
    case 1: if((in + 1)%bufsize == out)
             cout<<"\nBUffer is Full";
            else
            {
              cout<<"\nEnter the value: ";
              cin>>produce;
              buffer[in] = produce;
 	      in = (in+1)%bufsize;
            }
            break;
    case 2 : if(in == out)
              cout<<"\nBuffer is empty";
             else
             {
               consume = buffer[out];
               cout<<"\nThe consumed value is "<<consume;
               out = (out + 1) % bufsize;
	     }
             break;
    case 3 : exit(0);
  }
}
}
