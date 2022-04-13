#include<bits/stdc++.h>
#include<unistd.h>

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

	int frames[] = {1,2,3,4,5};
	unsigned int timeout = 3;

	int n = sizeof(frames)/sizeof(frames[0]);
	cout << "\tSender side\t\t\t\t\tReceiver Side" << endl;
	for(int i=0; i<n; i++)
	{
		int frameNumber = frames[i];
		cout << "\nSending Frame : " << frameNumber;
		cout<<"                             ";
		cout << "Received  frame : " << frameNumber << endl;
	
		int waitTime = random(1, timeout+2);
		sleep(waitTime);
		
		if(waitTime<=timeout)
		{
			cout << "Acknowledgment received for frame: " << frameNumber << endl;
		}
		else
		{
			cout << "Acknowledgment not received for frame " << frameNumber << endl << endl;
			cout << "\t\tResending frame " << frameNumber << endl;
			i-=1;
		}
		
	}

	return 0;
}
