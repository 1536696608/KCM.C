#include<stdio.h>
#include<stdlib.h>
void *Prefix(char* str,int* prefix,int n)
{
	prefix[0] = 0;
	int len = 0;
	int i = 1;
	while(i < n)
	{
		if(str[i] == str[len])
		{
			len++;
			prefix[i] = len;
			i++;
		}
		else
		{
			if(len > 0)
			{
				len = prefix[len-1];
			}
			else
			{
				prefix[i] = 0;
				i++;
			}
			
		}
	}
}

void *Move(int* a,int n)
{
	int i = n - 1;
	for(i;i > 0;i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = -1;
}
//str[j],text[i],len(str) = n,len(text) = m
void search(char *text,char *str,int m,int n)
{
	int i = 0,j = 0;
	int *prefix;
	prefix = (int*)malloc(sizeof(int)*n);
	Prefix(str,prefix,n);
	Move(prefix,n);
	while(i < m)
	{
		
		if(j == n-1&&str[j] == text[i])
		{
			printf("ÔÚÄÄ%d\n",i - j);
			j = 0;
			i++;
		}
		
		if(str[j] == text[i])
		{
			
			j++;
			i++;
		}
		else
		{
			j = prefix[j];
			if(j == -1)
			{
				i++;
				j++;
			}
		}
	}
}
int main()
{
	int a[9];
	char* str = "BA";
	char* text = "ABABABBA";
	search(text,str,8,2);
	return 0;
}
