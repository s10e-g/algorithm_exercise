#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define MEMSIZE 1000100

char *str = NULL;
int *nextAarray = NULL;
int strLength;

bool isSame(int subLength)
{
	int i, k = strLength - subLength;
	for(i=0; i<subLength; i++, k++)
	{
		if(str[i] != str[k])	return false;
	}
	return true;
}

bool equals(char *p,int i,int j)
{
	int k=0;
	int s=i-j;
	for(;k<=j-1&&s<=i-1;k++,s++)
	{
		if(p[k]!=p[s])
			return false;
	}
	return true;
}

void getnextAarray(char *p,int *nextAarray, int lp)
{
	int i,j,temp;
	for(i=0;i<lp;i++)
	{
		if(i==0)
		{
			nextAarray[i]=-1;     //nextAarray[0]=-1
		}
		else if(i==1) 
		{
			nextAarray[i]=0;      //nextAarray[1]=0
		}
		else
		{
			temp=i-1;
			for(j=temp;j>0;j--)
			{
				if(equals(p,i,j))
				{
					nextAarray[i]=j;
					break;
				}
			}
			if(j==0)
				nextAarray[i]=0;
		}
	}
}


int KMPMatch(char *s,char *p, int ls, int lp)
{
	int nextAarray[100];
	int i,j;
	i=0;
	j=0;
	getnextAarray(p,nextAarray, lp);
	while(i<ls)
	{
		if(j==-1||s[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			j=nextAarray[j];
		}
		if(j==lp)
			return i-strlen(p);
	}
	return -1;
}

int getLengthE()
{
	int start = strLength / 3;
	int ls;

	char *strA;
	while(start > 0)
	{
		if(!isSame(start))
		{
				start--;
				continue;
		}

		else{
			strA = (char*)(str+start);
			ls = strLength - 2*(start);

			if(KMPMatch(strA, str, ls, start) == -1)
			{
				start--;
				continue;
			}
			else{
				return start;
			}
		}
	}
    return 0;
}

void readData()
{
	int tests;
	cin>>tests;
	for(int i=0; i<tests; i++)
	{
		scanf("%s", str);
		memset(nextAarray, 0, sizeof(int)*MEMSIZE);
		strLength = strlen(str);
		cout<<getLengthE()<<endl;
	}
}

int main(int argc, char* argv[])
{
	str = new char[MEMSIZE];
	nextAarray = new int[MEMSIZE];

	readData();

	delete str;
	delete nextAarray;
}

