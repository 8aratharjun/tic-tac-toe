v#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

void disp(string arr[9]);
void ref();
int horcheck(string arr[9]);
int vercheck(string arr[9]);
int diagcheck(string arr[9]);
int checkwin(string arr[9]);
int checkDraw(string arr[9]);

void fun();

//Functions
int checkDraw(string arr[9])
{
	int count =0;
	for(int i=0; i < 9;i++)
	{
		if(arr[i]!=" ")
		count++;
	}
	if(count==9)
	return 1;
	else 
	return 0;
}

int checkwin(string arr[9])
{
	int chk = horcheck(arr);
	int chk2 = vercheck(arr);
	int chk3 = diagcheck(arr);
	if(chk==1||chk2==1||chk3==1)
	return 1;
	else 
	return 0;
}

int diagcheck(string arr[9])
{
	int flag1 = 0;
	int flag2 = 0;
	
	if(arr[0]!=" "||arr[4]!=" "||arr[8]!=" ") 
	{
		if(arr[0]==arr[4]&&arr[4]==arr[8])
		{
			flag1 = 1;
		}
	}
	if(arr[2]!=" "||arr[4]!=" "||arr[6]!=" ") 
	{
		if(arr[2]==arr[4]&&arr[4]==arr[6])
		{
			flag2 = 1;
		}
	}
	if(flag1==1||flag2==1)
	return 1;
	else 
	return 0;
	
	
}
int horcheck(string arr[9])
{
	int flag = 0;
	for(int i=0;i<9;i++) //i signifies rows
	{
		if(arr[i]!=" "||arr[i+1]!=" "||arr[i+2]!=" ") 
		{
			if(arr[i]==arr[i+1]&&arr[i+1]==arr[i+2])
			{
				flag = 1;
			}
		}
		i+=2;
	}
	if(flag==1)
	return 1;
	else 
	return 0;
}

int vercheck(string arr[9])
{
	int flag = 0;
	for(int i=0;i<3;i++) //i signifies first row elements
	{
		if(arr[i]!=" "||arr[i+3]!=" "||arr[i+6]!=" ") 
		{
			if(arr[i]==arr[i+3]&&arr[i+3]==arr[i+6])
			{
				flag = 1;
			}
		}
	}
	if(flag==1)
	return 1;
	else 
	return 0;
}

void ref()
{
	int arr[9];

	for (int i= 0; i< 9;i++)
	{
		arr[i]=i+1;
	}
	
	for (int j=0; j<9; j++)
	{
		cout<<"|"<<arr[j]<<"|"<<arr[j+1]<<"|"<<arr[j+2]<<"|"<<endl;
		j+=2;
	}
	
}
void disp(string arr[9])
{
	for (int j=0; j<9; j++)
	{
		cout<<"|"<<arr[j]<<"|"<<arr[j+1]<<"|"<<arr[j+2]<<"|"<<endl;
		j+=2;
	}
}
void fun()
{
//Fun stuff
    cout<<"Thanks for playing the game"<<endl;
    cout<<"Shall I say something??"<<endl;
    cout<<"type yes or no"<<endl;
    string ans;
    cin>>ans;
    int flag =0;
    if(ans!="yes"&&ans!="no")
    flag =1;
    if(ans=="yes")
    {
        cout<<"Now is the future of past"<<endl;
        cout<<"Think about it :).........Bye"<<endl;
    }
    else if(ans=="no" | flag==1 )
    {
        cout<<"Alrighty then, bye"<<endl;
    }
}
int main()
{
	
	int game =1;
		
	string gamePos[9];
	for (int i= 0; i< 9;i++)
	{
		gamePos[i]=" ";
	}
	string name1;
	string name2;
	cout<<"Enter the name of first player"<<endl;
	cin>>name1;
	cout<<"Enter the name of second player"<<endl;
	cin>>name2;
	cout << "Welcome to Tic tac toe! ( ͡▀̿ ̿ ͜ʖ ͡▀̿ ̿ )"<<endl;
	sleep_until(system_clock::now() + seconds(5));
		
	while(game==1)
	{
		//Player A
			
		cout << name1<< " should play now"<<endl;
		ref();
		cout<< "Enter the position number by referring to the above chart"<<endl;
		int a;
		cin>>a;
		gamePos[a-1]="X";
		sleep_until(system_clock::now() + seconds(2));
		disp(gamePos);

		if(checkwin(gamePos)==1)
		{
			sleep_until(system_clock::now() + seconds(2));
			cout << "Congratulations!!! "<<name1<<" you won  ᕙ(`▿´)ᕗ  "<<endl;
			fun();
			break;
		}
		if(checkDraw(gamePos)==1)
		{
			sleep_until(system_clock::now() + seconds(2));
			cout << "The match is tie...ting ting ting"<<endl;
			fun();
			break;
		}
		
		
		
		
		//Player B
		cout << name2<<" should play now "<<endl;
		ref();
		cout<< "Enter the position number by referring to the above chart"<<endl;
		int b;

		cin>>b;
		gamePos[b-1]="O";
		sleep_until(system_clock::now() + seconds(2));
		disp(gamePos);
		if(checkwin(gamePos)==1)
		{
			sleep_until(system_clock::now() + seconds(2));
			cout << "Congratulations!!! "<<name2<<" you won  ᕙ(`▿´)ᕗ  "<<endl;
			fun();
			break;
		}
		if(checkDraw(gamePos)==1)
		{
			sleep_until(system_clock::now() + seconds(2));
			cout << "The match is tie...ting ting ting"<<endl;
			fun();
			break;
		}
	}
}