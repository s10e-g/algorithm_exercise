#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ntest;
int numbers;

int count;

void readData()
{
	int i, j, pos, k, curA, nstr;

	scanf("%d", &ntest);
	for(i=0; i<ntest; i++)
	{
		scanf("%d%d", &numbers, &count);
		printf("Case #%d: ", i+1);
		if(numbers == 1)
		{
			for(j=0; j<count; j++)
			{
				printf("a");
			}
			
		}
		
		else if(numbers == 2)
		{
			nstr = count / 2;
			if(count % 2 != 0)	nstr++;

			for(j=0; j<nstr; j++)
			{
				printf("a");
			}

			if(j<count)
			{
				printf("b");
				j++;
			}

			pos = (nstr-1)/2;
			for(k=0; k<pos; k++)
			{
				if(j<count)
				{
					printf("a");
					j++;
				}
			}

			if(j<count)
			{
				printf("b");
				j++;
			}

			pos = (nstr - (pos+2))/2;
			for(k=0; k<pos; k++)
			{
				if(j<count)
				{
					printf("a");
					j++;
				}
			}

			if(j<count)
			{
				printf("b");
				j++;
			}

			for(k=j; k<count; k++)
			{
				if(k < count)
				{
					printf("a");
				}
			}
		}
		else
		{
			pos = count/3;
			int x=0;
			for(j=0; j<pos; j++, x+=3)
			{
				printf("abc");
			}
			if(count % 3 != 0){
				if(x < count)	printf("a");
				if(x+1 < count)	printf("b");
				if(x+2 < count)	printf("c");
			}
		}
		printf("\n");
	}
	
}
int main()
{
	readData();
}
