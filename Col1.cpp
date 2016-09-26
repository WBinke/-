#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
bool isNum(string s1)
{
	string tempStr1,tempStr2,tempStr3,finalStr;
	char er,ea;
	long long int a,b;
	while((s1).length()!=0)
	{	
		if((s1).length()>=18)
		{
			tempStr1=(s1).substr((s1).length()-18,18);
			s1=(s1).substr(0,(s1).length()-18); 
		}
		else if((s1).length()!=0)
		{
			tempStr1=(s1).substr(0,(s1).length());
			s1=(s1).substr(0,0);
		}
		
	
		stringstream myTurn;
		stringstream hh;
		myTurn<<tempStr1;
		if(!(myTurn>>a))
			return false;
		if(myTurn>>er)
			return false;
	
	}
	return true;
}
bool judStr(string s,int flag)
{	
	if(flag==0)
	{
		if((s[0]>='0'&&s[0]<='9')||s[0]=='+'||s[0]=='-')
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')
			return true;
		else
			return false;
	}	
}
string add(string *s1,string *s2)
{	
	string tempStr1,tempStr2,tempStr3,finalStr;
	string exzero="00000000000000000000000000";
	long long int a,b,c;
	int jinFlag=0;
	
	while((*s1).length()!=0&&(*s2).length()!=0)
	{	
		if((*s1).length()>=18)
		{
			tempStr1=(*s1).substr((*s1).length()-18,18);
			*s1=(*s1).substr(0,(*s1).length()-18); 
		}
		else
		{
			tempStr1=(*s1).substr(0,(*s1).length());
			*s1=(*s1).substr(0,0);
		}
		
		
		if((*s2).length()>=18)
		{
			tempStr2=(*s2).substr((*s2).length()-18,18);
			*s2=(*s2).substr(0,(*s2).length()-18); 
		}
		else
		{
			tempStr2=(*s2).substr(0,(*s2).length());
			*s2=(*s2).substr(0,0);
		}
		stringstream myTurn;
		myTurn<<tempStr1;
		myTurn>>a;
		//cout<<"a"<<a<<endl;
		myTurn.clear();
		myTurn<<tempStr2;
		myTurn>>b;
		//cout<<"b"<<b<<endl;
		myTurn.clear();
		c=a+b+jinFlag;
		myTurn<<c;
		//cout<<"c"<<c<<endl;
		myTurn>>tempStr3;
		//cout<<"tempstr3:"<<tempStr3<<endl;
		//cout<<"length"<<tempStr3.length()<<endl;
		if((((*s1).length()!=0)||((*s2).length()!=0))&&(tempStr3.length()!=19))
		{
			tempStr3=exzero.substr(1,18-tempStr3.length())+tempStr3;
			//cout<<"gg"<<endl;
		}
		if(tempStr3.length()==19)
		{
			jinFlag=tempStr3[0]-48;
			tempStr3=tempStr3.substr(1,18);
			finalStr=tempStr3+finalStr;
		}
		else
		{
			finalStr=tempStr3+finalStr;
		}
		if(jinFlag!=0&&((*s1).length()!=0&&(*s2).length()==0))
		{
			*s2=jinFlag+48;
			jinFlag=0;
		}
		if(jinFlag!=0&&((*s1).length()==0&&(*s2).length()!=0))
		{
			*s1=jinFlag+48;
			jinFlag=0;
		}	
		//cout<<"finalstr1:"<<finalStr<<endl;
	}
	if((*s1).length()!=0)
	{
		finalStr=(*s1)+finalStr;
	}
	if((*s2).length()!=0)
	{
		finalStr=(*s2)+finalStr;
	}
	//cout<<"finalstr"<<finalStr<<endl;
	return finalStr;
}
string myMinus(string *s1,string *s2)
{
	long long int a,b,c;
	int jinFlag=0,myflag=0,fuFlag=0;
	string tempStr1,tempStr2,tempStr3,finalStr;
	if(((*s1).length()==(*s2).length())&&((*s1)[0]<(*s2)[0]))
		fuFlag=1;
	while((*s1).length()!=0&&(*s2).length()!=0)
	{	
		if((*s1).length()>=18)
		{
			tempStr1=(*s1).substr((*s1).length()-18,18);
			*s1=(*s1).substr(0,(*s1).length()-17);
			if((*s1).length()!=1)
				{
					(*s1)[(*s1).length()-1]='0'; 
					
				}
			if(tempStr1[0]=='0')
			{
				tempStr1[0]='1';
				myflag=1;
			}
		}
		else
		{	
			tempStr1=(*s1).substr(0,(*s1).length());
			//cout<<"s1:"<<*s1<<endl;
			//cout<<"tempStr1:"<<tempStr1<<endl;
			*s1=(*s1).substr(0,0);
		}
		
		
		if((*s2).length()>=17)
		{
			tempStr2=(*s2).substr((*s2).length()-17,17);
			*s2=(*s2).substr(0,(*s2).length()-17); 
		}
		else
		{
			tempStr2=(*s2).substr(0,(*s2).length());
			*s2=(*s2).substr(0,0);
		}
		stringstream myTurn;
		myTurn<<tempStr1;
		myTurn>>a;
		//cout<<"a"<<a<<endl;
		myTurn.clear();
		myTurn<<tempStr2;
		myTurn>>b;
		//cout<<"b"<<b<<endl;
		myTurn.clear();
		c=a-b+jinFlag;
		myTurn<<c;
		//cout<<"c"<<c<<endl;
		myTurn>>tempStr3;
		//cout<<"temp"<<tempStr3<<endl;
		if(tempStr3.length()==18)
		{	
			if(myflag==0)
				jinFlag=tempStr3[0]-48;
			else
				jinFlag=0;
			if((*s1).length()==1)
			{
				jinFlag=0;
			}
			tempStr3=tempStr3.substr(1,17);
			//cout<<"tempstr"<<tempStr3<<endl;
		}
		else if((*s1).length()!=0)
		{
			while(tempStr3.length()!=17)
			{
				tempStr3='0'+tempStr3;
			}
			if(myflag==0)
				jinFlag=0;
			else
				jinFlag=-1;
			//cout<<"tempstr"<<tempStr3<<endl;
		}
		finalStr=tempStr3+finalStr;
		if(jinFlag==-1&&(*s2).length()==0)
		{
			*s2='1';
			jinFlag=0;
		}	
		//cout<<"final"<<finalStr<<endl;
	}
	if((*s1).length()!=0)
	{
		(*s1)[(*s1).length()-1]=jinFlag+48;
		finalStr=(*s1)+finalStr;
	}
	while(finalStr[0]=='0'&&finalStr.length()!=1)
	{
		finalStr=finalStr.substr(1,finalStr.length()-1);
	}
	if(fuFlag==1)
		finalStr='-'+finalStr;
	return finalStr;
}
string myMul(string *s1,string *s2)
{	
	long int length1,length2;
	int j=1;
	string kong,tempStr1,tempStr2,tempStr3,tempStr4,tempStr5,finalStr;
	length1=(*s1).length();
	length2=(*s2).length();
	for(int i=0;i<(length2/20)+1;i++)
		kong=kong+"00000000000000000000";
	while(j<=length2)
	{
		tempStr1=*s1+kong.substr(0,length2-j);
		tempStr2=tempStr1;
		//cout<<"tempStr1:"<<tempStr1<<endl;
		tempStr3=tempStr1;
		if((*s2)[j-1]!='0')
		{
			tempStr4=tempStr1;
		}	
		else
		{
			tempStr4='0';
		}
		for(int i=0;i<((*s2)[j-1]-49);i++)
		{
			tempStr4=add(&tempStr1,&tempStr2);
			tempStr1=tempStr4;
			tempStr2=tempStr3;
		}
		//cout<<"tempStr4:"<<tempStr4<<endl;
		finalStr=add(&tempStr4,&tempStr5);
		tempStr5=finalStr;
		j++;
		//cout<<"finalStr:"<<finalStr<<endl;
	}
	while(finalStr[0]=='0'&&finalStr.length()!=1)
	{
		finalStr=finalStr.substr(1,finalStr.length()-1);
	}
	return finalStr;
	
	
}
string myDiv(string *s1,string *s2)
{
	long int length1,length2;
	length1=(*s1).length();
	length2=(*s2).length();
	long int j=length1-length2;
	int num=-1;
	if(j<0||(j==0&&((*s1)[0]<(*s2)[0])))
	{
		return "0 "+(*s1);
	}
	string kong,tempStr1,tempStr2,tempStr3,tempStr4,tempStr5,finalStr;
	
	tempStr1=(*s1);
	
	tempStr3=tempStr1;
	for(int i=0;i<((length1-length2)/20)+1;i++)
		kong=kong+"000000000000000000000000000000000000";
	tempStr4=kong.substr(0,j+1);
	while(j!=-1)
	{	
		cout<<"j"<<j<<endl;
		tempStr2=(*s2)+kong.substr(0,j);
		//cout<<"tempStr2:"<<tempStr2<<endl;
		while(tempStr3[0]!='-')
		{	
			if(tempStr1.length()<tempStr2.length())
			{
				num=num+1;
				tempStr5=tempStr3;
				break;
			}
			tempStr5=tempStr3;
			tempStr3=myMinus(&tempStr1,&tempStr2);
			tempStr2=(*s2)+kong.substr(0,j);
			num=num+1;
			tempStr1=tempStr3;
			cout<<"tempStr3:"<<tempStr3<<"      "<<num<<endl;
			cout<<"tempStr2:"<<tempStr2<<endl;
			
				
			
			//cout<<"num"<<num<<endl;
			if(num>10)
				break;	
		}
		if(num>10)
			break;
		tempStr4[length1-length2-j]=num+48;
		tempStr1=tempStr5;
		//cout<<"tempStr1:"<<tempStr1<<endl;
		j=j-1;
		num=-1;
		tempStr3=tempStr5;
		//cout<<"tempStr4:"<<tempStr4<<endl;
		//cout<<"tempStr3:"<<tempStr3<<endl;
	}
	finalStr=tempStr4+' ';
	finalStr=finalStr+tempStr1;
	while(finalStr[0]=='0'&&finalStr.length()!=1)
		finalStr=finalStr.substr(1,finalStr.length()-1);
	return finalStr;
}
int main()
{
	string str1,str2,str3,temp,tempstr1,tempstr2;
	int flag;
	while(getline(cin,str1))
	{	
		getline(cin,str2);
		getline(cin,str3);
	
		if(judStr(str1,0)&&judStr(str2,0)&&judStr(str3,1)&&isNum(*((&str2)+1)))
		{	
			if(str1[0]=='+')
				str1=str1.substr(1,str1.length()-1);
			if(str2[0]=='+')
				str2=str2.substr(1,str2.length()-1);
			if(str1[0]=='-'&&str2[0]=='-')
			{	
				str1=str1.substr(1,str1.length()-1);
				str2=str2.substr(1,str2.length()-1);
				flag=1;
			}
			else if(str1[0]=='-'&&str2[0]!='-')
			{	
				str1=str1.substr(1,str1.length()-1);
				flag=2;
			}
			else if(str1[0]!='-'&&str2[0]=='-')
			{	
				str2=str2.substr(1,str2.length()-1);
				flag=3;
			}
			else
			{
				flag=0;
			}
			while(str1[0]=='0'&&str1.length()!=1)
			{
				
				str1=str1.substr(1,str1.length()-1);
			}
			while(str2[0]=='0'&&str2.length()!=1)
			{
				str2=str2.substr(1,str2.length()-1);
			}
			
			if(str3[0]=='+')
			{
				if(flag==0)
				{
					cout<<add(&str1,&str2)<<endl;
				}
				else if(flag==1)
				{
					cout<<'-'<<add(&str1,&str2)<<endl;
				}
				else if(flag==2)
				{
					temp=str1;
					str1=str2;
					str2=temp;
					flag=0;
					str3[0]='-';
				}
				else
				{
					flag=0;
					str3[0]='-';
				}
			}
				
			if(str3[0]=='-')
			{
				tempstr1=str1;
				tempstr2=str2;
				if(flag==0)
				{
					if(str1.length()<str2.length()||(str1.length()==str2.length()&&str1[0]<str2[0]))
						cout<<myMinus(&str1,&str2)<<endl;
					else if((myMinus(&tempstr1,&tempstr2))[0]=='-')
					{
						cout<<'-'<<myMinus(&str2,&str1)<<endl;
					}
					else
					{
						cout<<myMinus(&str1,&str2)<<endl;
					}
				}
				else if(flag==1)
				{	
					if(str2.length()<str1.length()||(str1.length()==str2.length()&&str2[0]<str1[0]))
						cout<<myMinus(&str2,&str1)<<endl;
					else if((myMinus(&tempstr2,&tempstr1))[0]=='-')
					{
						cout<<'-'<<myMinus(&str1,&str2)<<endl;
					}
					else
					{
						cout<<myMinus(&str2,&str1)<<endl;
					}
				}
				else if(flag==2)
				{
					cout<<'-'<<add(&str1,&str2)<<endl;
				}
				else
				{
					cout<<add(&str1,&str2)<<endl;
				}
			}
			
			if(str3[0]=='*')
			{
				if(str1.length()<str2.length())
				{
					temp=str1;
					str1=str2;
					str2=temp;
				}
				if(flag==0)
				{
					cout<<myMul(&str1,&str2)<<endl;
				}
				else if(flag==1)
				{
					cout<<myMul(&str1,&str2)<<endl;
				}
				else
				{	
					temp=myMul(&str1,&str2);
					if(temp[0]!='0')
						cout<<'-'<<temp<<endl;
					else
						cout<<temp<<endl;
				}
			}
			if(str3[0]=='/')
			{
				if(str2[0]=='0'||flag!=0)
					cout<<"ERROR INPUT"<<endl;
				else if(flag==0)
					cout<<myDiv(&str1,&str2)<<endl;
					
			}
			
		}
		else
		{
			cout<<"ERROR INPUT"<<endl;
			
		}
		
	}
	
	return 0;
} 
