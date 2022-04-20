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
	int fr;
	int wi;
	cout << "Enter number of frames: ";
	cin >> fr;
	cout << "Enter window size: ";
	cin >> wi;
	
	int frames[fr];
	vector<int> window;
	for(int i=0; i<fr; i++)
	{
		frames[i] = i+1;
	}
	
	int st = 0;
	unordered_map<int,int> mp;
	int cap = wi;
	int timeout = 2;
	while(st<fr)
	{
		cout << "Sending frames: ";
		window.clear();
		wi = cap;
		if(!mp.empty())
		{
			wi-=mp.size();
			for(auto &h:mp)
			{
				window.push_back(h.first);
			}
			mp.clear();
		}
		for(int k = st; k<st+wi and k<fr; k++)
		{
			window.push_back(frames[k]);
		}
		sort(window.begin(), window.end());
		for(auto &h:window)
		cout << h << " ";
		cout << endl;
		// receiver
		sleep(timeout);
		for(auto &h:window)
		{
		
			int ran = random(1,timeout+2);
			if(ran>timeout)
			{
				mp[h] = 1;
				cout << h << " is improper!" << endl;
			}
			else
			{
				cout << h << " is received!" << endl;
			}
		}

		cout << endl;
		st += wi;
	}
	
	while(!mp.empty())
	{
		window.clear();
		for(auto &h:mp)
		window.push_back(h.first);
		cout << "Sending frames: ";
		sort(window.begin(), window.end());
		for(auto &h:window)
		cout << h << " ";
		cout << endl;
		mp.clear();
		sleep(timeout);
		for(auto &h:window)
		{
		
			int ran = random(1,timeout+2);
			if(ran>timeout)
			{
				mp[h] = 1;
				cout << h << " is improper!" << endl;
			}
			else
			{
				cout << h << " is received!" << endl;
			}
		}
		
		cout << endl;
	}
	
	return 0;
}
