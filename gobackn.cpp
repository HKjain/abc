#include<bits/stdc++.h>
#include<ctime>
#include<unistd.h>
#include<cstdlib>
using namespace std;


int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}


int main()
{
 int nf,N;
 int no_tr=0;
 srand(time(NULL));
 cout<<"Enter the number of frames : ";
 cin>>nf;
 cout<<"Enter the Window Size : ";
 cin>>N;
 int timeout = 2;
 int i=1;
 while(i<=nf)
 {
     int x=0;
     for(int j=i;j<i+N && j<=nf;j++)
     {
         cout<<"Sent Frame "<<j<<endl;
         no_tr++;
     }
     
     int wait = random(1, timeout);
     sleep(wait);
     for(int j=i;j<i+N && j<=nf;j++)
     {
	int rnum = random(1,30);
	int flag = rnum%2;
	if(!flag)
	{
		cout<<"Acknowledgment for Frame "<<j<< " received!" << endl;
		x++;
	}
	else
	{   
		if(rnum<=10)
		cout<<"Frame "<<j<<" Damaged!"<<endl;
		else if(rnum<=20)
		cout<<"Frame "<<j<<" Not Received"<<endl;
		else if(rnum<=30)
		cout<<"Frame "<<j<<" Acknowledgement not Received"<<endl;
		cout<<"Retransmitting Window..."<<endl;
		break;
	}
     }
     cout<<endl;
     i+=x;
 }
 cout<<"Total number of transmissions : "<<no_tr<<endl;
 return 0;
}
