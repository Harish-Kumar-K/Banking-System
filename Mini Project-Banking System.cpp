#include<iostream>
#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
using namespace std;

class account
{
	long int acno;
	char name[50];
	int deposit;
	char type;
	int pin;
public:
	void create_account(account);
	void show_account()const;
	void modify_pin();
	void dep(int);
	void draw(int);
	int retdeposit()const;
	char rettype()const;
	int retacno()const;
	int retpin()const;
	void modify();	
};

void account::create_account(account ac)
{
	acno=ac.retacno()+1;
	cout<<"\n your account no is:"<<acno;
	cout<<"\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	if(type!='c' && type!='s')
		throw"\n The input for type of account is invalid.....\n account is not created \n ";
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	if(type=='s'&&deposit<500)
	   throw"\n The deposit amount is not accepted";
	if(type=='c'&&deposit<1000)
	   throw"\n The deposit amount is not accepted";
	cout<<"\n Enter your 4 digit PIN: ";
	int p,q;
	cin>>p;
	if(p<999||p>9999)
	  throw"\n The entered PIN is not accepted";
	cout<<"\n Re-enter your 4 digit PIN: ";
	cin>>q;
	if(p!=q)
	{cout<<"\n Re-entered PIN is mismatched";
	 throw"\n Account is not created";
    }  
	pin=p;   
	cout<<"\nAccount Created..";
}

void account::show_account()const
{   
	cout<<"\nAccount No. : "<<retacno();
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}

void account::modify_pin()
{   
	cout<<"\n Your account No. is: "<<acno;
	cout<<"\n Enter your new 4 digit PIN: ";
	int p,q;
	cin>>p;
	if(p<999||p>9999)
	 throw"\n The entered PIN is not accepted";
	cout<<"\n Re-enter your new PIN: ";
	cin>>q;
	if(p==q)
	{
		pin=p;
		cout<<"\n PIN successfully changed";
	}
	else
	{
		cout<<"\n Re-entered PIN is mismatched"<<"\n PIN change unsuccessful";
	}
}

void account::dep(int x)
{
	if(x>0)
	  deposit+=x;
	else if(x==0)
	  throw"\n No amount deposited";  
	else
	  throw"\n The deposited amount cannot be negative";
	cout<<"\n Deposit successful...";
}

void account::draw(int x)
{
	if((500+x)>deposit)
	 throw"\n Balance is not available:(Minimum balance must be 500)";
	else if(x==0)
	 throw"\n Amount cannot be withdrawn";
	deposit-=x;
	cout<<"\n Withdraw successful...Collect your amount";
}

void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	int n;
	cout<<"\nModify Type of Account : ";
	cin>>n;
	if(n=='c')
	{
		if(deposit<1000)
			throw"\n The modification of type of account is not successful \n";
		else
			type='c';
	}
	else if(n=='s')
	{
		if(deposit<500)
			throw"\n The modification of type of account is not successful \n";
		else
			type='s';
	}
	else
		throw"\n The modification of type of account is not successful....because of inappropriate input \n";	
}

int account::retdeposit()const
{
	return deposit;
}

char account::rettype()const
{
	return type;
}

int account::retacno()const
{
	return acno;
}

int account::retpin()const
{
	return pin;
}

int menu1()
{int r1;
 cout<<"\n\t\t\t\t\t =======================";
 cout<<"\n\t\t\t\t\t WELCOME TO ABC BANK";
 cout<<"\n\t\t\t\t\t =======================";
 cout<<"\n\t\t\t\t\t 1.TO CREATE NEW ACCOUNT";
 cout<<"\n\t\t\t\t\t 2.TO ACCESS EXISTING ACCOUNT";
 cout<<"\n\t\t\t\t\t 3.EXIT";
 cout<<"\n\t\t\t\t\t =======================";
 cout<<"\n ENTER YOUR CHOICE ";
 cin>>r1;
 if((r1==1)||(r1==2)||(r1==3))
  return r1;
 else
 {
 	cout<<"\n Enter the correct choice...";
 	exit(1);
 }
}

int menu2()
{
	int r2;
	system("CLS");
	cout<<"\n 1.WITHDRAW AMOUNT";
	cout<<"\n 2.DEPOSIT AMOUNT";
	cout<<"\n 3.MODIFY PIN";
	cout<<"\n 4.DISPLAY ACCOUNT DETAILS";
	cout<<"\n 5.MODIFY ACCOUNT";
	cout<<"\n 6.DELETE ACCOUNT";
	cout<<"\n 7.EXIT";
	cout<<"\nENTER YOUR CHOICE ";
	cin>>r2;
	return r2; 
}

void write_account();	
void display_sp(int,int);
void delete_account(int,int);	
void deposit_withdraw(int,int, int); 
void modify_account(int,int);
void write_pin(int,int);

int main()
{
	do
	{try
	{
	    account obj;
		int ch1,ch2,num,p;
		while(1)
		{			
			ch1=menu1();
			switch(ch1)
			{
				case 1:write_account();break;
				case 2:ch2=menu2();
						 switch(ch2)
				         {case 1:cout<<"\n Enter account no.: ";
				                 cin>>num;
				                 cout<<"\n Enter your PIN :";
				                 cin>>p;
				                 deposit_withdraw(num,p,2);
				                 break;
				          case 2:cout<<"\n Enter account no.: ";
						         cin>>num;
						         cout<<"\n Enter your PIN :";
				                 cin>>p;
								 deposit_withdraw(num,p,1);
								 break;
						  case 3:cout<<"\n Enter account no.: ";
						         cin>>num;
						         cout<<"\n Enter your PIN :";
				                 cin>>p;
								 write_pin(num,p);
								 break;
						  case 4:cout<<"\n Enter account no.: ";
						         cin>>num;
						         cout<<"\n Enter your PIN :";
				                 cin>>p;
								 display_sp(num,p);
								 break;
						  case 5:cout<<"\n Enter account no.: ";
						         cin>>num;
						         cout<<"\n Enter your PIN :";
				                 cin>>p;
						         modify_account(num,p);
						         break;
						  case 6:cout<<"\n Enter account no.: ";
						         cin>>num;
						         cout<<"\n Enter your PIN :";
				                 cin>>p;
						         delete_account(num,p);
						         break;
						  case 7:exit(1);
						  default:cout<<"\n Please enter correct choice...";	 		 		 	       
						 }
						 break;
				case 3:exit(1);	
				default:cout<<"\n Please enter correct choice..... \n";
				        break;
		
				}	 				        
			}
		}
	
	catch(const char *s)
	{
		cout<<s;
	}
}while(1);
	return 0;
}

void write_account()
{
	account ac,ac1;
	ifstream inFile;
	inFile.open("account.txt",ios::binary|ios::app|ios::in);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	inFile.seekg(0,ios::beg);
	while(!inFile.eof())
	{
		inFile.read(reinterpret_cast<char *> (&ac), sizeof(account));
	}
	inFile.close();
	ofstream outFile;
	outFile.open("account.txt",ios::binary|ios::app|ios::out);
		if(!outFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.seekp(0,ios::end);
	ac1.create_account(ac);
	outFile.write(reinterpret_cast<char *> (&ac1), sizeof(account));
	outFile.close();
}

void delete_account(int n,int p)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	bool found=false;
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n && ac.retpin()==p)
				found=true;
		if(found==false)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt","account.txt");
	cout<<"\n\n\tRecord Deleted ..";
}

void write_pin(int n,int p)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !!";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpin()==p)
		{	
			ac.modify_pin();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void modify_account(int n,int p)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !!";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpin()==p)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void display_sp(int n,int p)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nACCOUNT DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n && ac.retpin()==p)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number with the entered pin does not exist";
}

void deposit_withdraw(int n, int p, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpin()==p)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited ";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
        }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
