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
	cout << "Sender side\t\t\t\t\t\tReceiver Side" << endl;
	for(int i=0; i<n; i++)
	{
		int frameNumber = frames[i];
		cout << "Sending Frame on sender side: " << frameNumber << endl;
		cout << "Received the frame on receiver side: " << frameNumber << endl;
		
		cout << "Acknowledgment sent from receiver for frame " << frameNumber << endl;
		int waitTime = random(1, timeout+2);
		cout << waitTime << endl;
		//sleep(waitTime);
		
		if(waitTime<=timeout)
		{
			cout << "Acknowledgment receiver for sender of frame: " << frameNumber << endl;
		}
		else
		{
			cout << "Acknowledgment not received for frame " << frameNumber << endl;
			cout << "Resending frame " << frameNumber << endl;
			i-=1;
		}
		
	}

	return 0;
}
