#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

//Function decalrations
void disp(string arr[9]);
void ref();
int horcheck(string arr[9]);
int vercheck(string arr[9]);
int diagcheck(string arr[9]);
int checkwin(string arr[9]);
int winCheck(string arr[9],int c);
void fun();
int playerb(string arr[9]);
int playerbHori(string arr[9]);
int playerbVerti(string arr[9]);
int playerbDiag(string arr[9]);
int playerbCornerCenterCheck(string arr[9]);
int checkDraw(string arr[9]);

//Function definitions
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
int winCheck(string arr[9],int c)
{
	///hori
	int b = 0;
	for(int i=0;i<9;i+=3) //i signifies rows
	{
		if((arr[i]!=" "&&arr[i+1]!=" ")||(arr[i+1]!=" "&&arr[i+2]!=" ")||(arr[i+2]!=" "&&arr[i]!=" "))
		{
			if(arr[i]==arr[i+1] || arr[i+1]==arr[i+2] || arr[i]==arr[i+2])
			{
				for(int j=i; j<(i+3); j++)
				{
					if(arr[j]==" ")
					{
						b=j+1;
						cout<<"WINNING_the b that is being exported from"<<i<<"th row :"<<b<<endl;
					}
					else 
					cout<<"WINNING_Something's wrong"<<endl;
				}				
				
			}
			else
			cout<<i<<"WINNING_th row... neither of two elements equal"<<endl;
		}
		else
		cout<<i<<"WINNING_th row is empty"<<endl;
	}
	

	//////////////////////////////////Verti/////////////////////////////////
	for(int i=0;i<3;i++) //i signifies first row elements
	{
		if((arr[i]!=" "&&arr[i+3]!=" ")||(arr[i+3]!=" "&&arr[i+6]!=" ")||(arr[i+6]!=" "&&arr[i]!=" "))
		{
			if(arr[i]==arr[i+3]&&arr[i+6]==" ")  
			{
				b=i+7;
			}
			else
			cout<<i<<"WINNING_th coloumn... neither of two elements are equal"<<endl;
			if (arr[i+3]==arr[i+6]&&arr[i]==" ")
			{
				b=i+1;
			}
			else
			cout<<i<<"WINNING_th coloumn... neither of two elements are equal"<<endl;
			if(arr[i]==arr[i+6]&&arr[i+3]==" ")
			{
				b=i+4;
			}
			else
			cout<<i<<"WINNING_th coloumn... neither of two elements are equal"<<endl;

		}
		else
		cout<<i<<"WINNING_th coloumn is empty"<<endl;
	}

	////////////////////////////////Diag/////////////////////////////////////////
	if(arr[0]!=" "&&arr[4]!=" "&&arr[8]!=" ") 
	{		
		if(arr[0]==arr[4]&& arr[8]==" " )  
		{
			b=9;
		}
		if(arr[4]==arr[8]&& arr[0]==" " )  
		{
			b=1;
		}
		if(arr[0]==arr[8]&& arr[4]==" " )  
		{
			b=5;
		}		
	}
	else
	cout<<"WINNING_the left to right diagonal is empty"<<endl;
	if(arr[2]!=" "&&arr[4]!=" "&&arr[6]!=" ") 
	{		
		if(arr[2]==arr[4]&& arr[6]==" " )  
		{
			b=7;
		}
		if(arr[4]==arr[6]&& arr[2]==" " )  
		{
			b=3;
		}
		if(arr[2]==arr[6]&& arr[4]==" " )  
		{
			b=5;
		}		
	}
	else
	cout<<"WINNING_the right to left diagonal is empty"<<endl;



	///Final return///////////////////////////////
	cout<<"Before entering into wincheck: "<<c<<endl;
	cout<<"After entering into wincheck: "<<b<<endl;
	if(b==0)
	{
		cout<<"final decision"<<c<<endl;
		return c;		
	}
	else
	
	cout<<"final decision"<<b<<endl;
	return b;
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
	for(int i=0;i<9;i+=3) //i signifies rows
	{
		if(arr[i]!=" "||arr[i+1]!=" "||arr[i+2]!=" ") 
		{
			if(arr[i]==arr[i+1]&&arr[i+1]==arr[i+2])
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

//Player b calculations
int playerbHori(string arr[9])
{
	int b = 0;
	for(int i=0;i<9;i+=3) //i signifies rows
	{
		if((arr[i]!=" "&&arr[i+1]!=" ")||(arr[i+1]!=" "&&arr[i+2]!=" ")||(arr[i+2]!=" "&&arr[i]!=" "))
		{
			if(arr[i]==arr[i+1] || arr[i+1]==arr[i+2] || arr[i]==arr[i+2])
			{
				if(arr[i]=="X"||arr[i+1]=="X"||arr[i+2]=="X")
				{
					for(int j=i; j<(i+3); j++)
					{
						if(arr[j]==" ")
						{
							b=j+1;
							cout<<"the b that is being exported from"<<i<<"th row :"<<b<<endl;
						}
						else 
						cout<<"Something's wrong"<<endl;
					}
					
				}
				else
				cout<<i<<"th row contains winning O's"<<endl;
			}
			else
			cout<<i<<"th row... neither of two elements equal"<<endl;
		}
		else
		cout<<i<<"th row is empty"<<endl;
	}
	return b;
}
int playerbVerti(string arr[9])
{
	int b=0;
	for(int i=0;i<3;i++) //i signifies first row elements
	{
		if((arr[i]!=" "&&arr[i+3]!=" ")||(arr[i+3]!=" "&&arr[i+6]!=" ")||(arr[i+6]!=" "&&arr[i]!=" "))
		{
			if(arr[i]==arr[i+3]&&arr[i+6]==" ")  
			{
				if(arr[i]=="X"||arr[i+6]=="X"||arr[i+2]=="X")
				{
					b=i+7;
				}
				else
				cout<<i<<"th coloumn contains winning zeroes"<<endl;
			}
			else
			cout<<i<<"th coloumn... neither of two elements are equal"<<endl;
			if (arr[i+3]==arr[i+6]&&arr[i]==" ")
			{
				b=i+1;
			}
			else
			cout<<i<<"th coloumn... neither of two elements are equal"<<endl;
			if(arr[i]==arr[i+6]&&arr[i+3]==" ")
			{
				b=i+4;
			}
			else
			cout<<i<<"th coloumn... neither of two elements are equal"<<endl;

		}
		else
		cout<<i<<"th coloumn is empty"<<endl;
	}
	
	return b;
}
int playerbDiag(string arr[9])
{
	int b=0;
	if(arr[0]!=" "&&arr[4]!=" "&&arr[8]!=" ") 
	{
		if(arr[0]!="X"||arr[4]!="X"||arr[8]!="X") 
		{
		
			if(arr[0]==arr[4]&& arr[8]==" " )  
			{
				b=9;
			}
			if(arr[4]==arr[8]&& arr[0]==" " )  
			{
				b=1;
			}
			if(arr[0]==arr[8]&& arr[4]==" " )  
			{
				b=5;
			}
		}
		else
		cout<<"The left to right diagonal contains winning O's"<<endl;
	}
	else
	cout<<"the left to right diagonal is empty"<<endl;
	if(arr[2]!=" "&&arr[4]!=" "&&arr[6]!=" ") 
	{
		if(arr[2]!="X"||arr[4]!="X"||arr[6]!="X") 
		{
			if(arr[2]==arr[4]&& arr[6]==" " )  
			{
				b=7;
			}
			if(arr[4]==arr[6]&& arr[2]==" " )  
			{
				b=3;
			}
			if(arr[2]==arr[6]&& arr[4]==" " )  
			{
				b=5;
			}
		}
		else
		cout<<"The right to left diagonal contains winning o's"<<endl;
	}
	else
	cout<<"the right to left diagonal is empty"<<endl;
	
	return b;
}



int playerbCornerCenterCheck(string arr[9])
{	
	int b=0;
	if(arr[0]==" ")
	b=1;
	if(arr[2]==" ")
	b=3;
	if(arr[6]==" ")
	b=7;
	if(arr[8]==" ")
	b=9;

	//Center check
	if(arr[4]==" ")
	b=5;

	cout<<"Finalized from cornercenter check: "<<b<<endl;
	return b;
	
}

int playerb(string arr[9])
{
	int b = 0;

	//To prevent immediate losing
	int flag1 = playerbHori(arr);
	int flag2 = playerbVerti(arr);
	int flag3 = playerbDiag(arr);
	if(flag1!=0)
	{
		b = flag1;
		cout<<"hori success"<<endl;
	}
	if(flag2!=0)
	{
		b = flag1;
		cout<<"verti success"<<endl;
	}
	if(flag3!=0)
	{
		b = flag1;
		cout<<"Diag success"<<endl;
	}

	//To Secure the corners incaseof not losing
	if(flag1==0&&flag2==0&&flag3==0)
	{
		cout<<"all orientations failed"<<endl;
		b= playerbCornerCenterCheck(arr);
	}
	else
	cout<<"Finalized from orientation flags: "<<b<<endl;
	return b;
}
//Main
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
	//sleep_until(system_clock::now() + seconds(5));
		
	while(game==1)
	{
		//Player A
			
		cout << name1<< " should play now"<<endl;
		ref();
		cout<< "Enter the position number by referring to the above chart"<<endl;
		int a;
		cin>>a;
		gamePos[a-1]="X";
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
		cout<<"Computer thinking"<<endl<<endl;
		sleep_until(system_clock::now() + seconds(5)); //To prevent the frustration of computer acting quickly
		b=playerb(gamePos);
		b=winCheck(gamePos,b);
		cout<<"Computer's choice: "<<b<<endl;
		gamePos[b-1]="O";
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