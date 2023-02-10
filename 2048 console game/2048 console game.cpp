// 2048 console game.cpp : Defines the entry point for the console application.
//
// lishuang10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <new>

int cifang(int i);

int _tmain(int argc, _TCHAR* argv[])
{
	printf("本产品最终解释权及版权归狗不理所有\nq:undo\tz:redo\te:end game\tw:up\ts:down\ta:left\td:right\nor use arrow keys\n");
loop:
	unsigned short a,b,bo=0,d,e,f,g,h,j,k,l=0,m=0;
	unsigned char(*i)[100];
	char c='w';
	bool boo=1;
	printf("wide:");
	scanf_s("%u",&a);
	printf("high:");
	scanf_s("%u",&b);
	try
	{
		i=new unsigned char [a*b][100];
	}
	catch(std::bad_alloc)
	{
		printf("申请内存失败。\n");
		goto loop;
	}
	for(g=0;g<a*b;g++)
		i[g][l]=0;
	for(g=0;g<a*b;g++)
		i[g][99]=0;
	for(;;boo=0,++l%=100,m=(m==100)?100:(m+1))
	{
		switch(c)
		{
//上已完成********************************************************************
		case 'w':case 72:
			{
				bo=0;		
				for(g=0;g<a*b;g++)
					i[g][l]=i[g][(l==0)?99:(l-1)];
				for(d=0;d<a;)
				{
					for(e=d;e<a*b;e=f)
					{
						for(;e<a*b&&!i[e][l];e+=a);
						for(f=e+a;f<a*b&&!i[f][l];f+=a);
						if(f<a*b&&i[f][l]==i[e][l])
						{
							i[e][l]++;
							i[f][l]=0;
							boo=1;
						}
					}
					for(e=g=d++;e<a*b;g+=a)
					{
						for(e+=a;e<a*b&&i[g][l];g+=a,e+=a);
						for(;e<a*b&&!i[e][l];e+=a);
						if(e<a*b&&i[e][l])
						{
							i[g][l]=i[e][l];
							i[e][l]=0;
							boo=1;
						}
					}
				}
				break;
			}
//下已完成**********************************************************************
		case 's':case 80:
			{
				bo=0;
				for(g=0;g<a*b;g++)
					i[g][l]=i[g][(l==0)?99:(l-1)];
				for(d=a*b-1;d>=a*b-a;d--)
				{
					for(e=d;;e=f)
					{
						for(;e<a*b&&!i[e][l];e-=a);
						for(f=e-a;f<a*b&&!i[f][l];f-=a);
						if(f>=a*b)
							break;
						if(i[f][l]==i[e][l])
						{
							i[e][l]++;
							i[f][l]=0;
							boo=1;
						}
					}
					for(e=g=d;e<a*b;g-=a)
					{
						for(e-=a;e<a*b&&i[g][l];g-=a,e-=a);
						for(;e<a*b&&!i[e][l];e-=a);
						if(e<a*b&&i[e][l])
						{
							i[g][l]=i[e][l];
							i[e][l]=0;
							boo=1;
						}
					}
				}
				break;
			}
//左********************************************************************************
		case 'a':case 75:
			{
				bo=0;
				for(g=0;g<a*b;g++)
					i[g][l]=i[g][(l==0)?99:(l-1)];
				for(d=0;d<a*b;d+=a)
				{
					for(e=d;;)
					{
						for(;e<a+d&&!i[e][l];e++);
						for(f=e+1;f<a+d&&!i[f][l];f++);
						if(f>=a+d)
							break;
						if(i[f][l]==i[e][l])
						{
							i[e][l]++;
							i[f][l]=0;
							e=f+1;
							boo=1;
						}
						else
							e=f;
					}
					e=g=d;
					for(f=0;f<a;g++)
					{
						e++;
						for(f++;f<a&&i[g][l];g++,e++,f++);
						for(;f<a&&!i[e][l];e++,f++);
						if(f<a)
						{
							i[g][l]=i[e][l];
							i[e][l]=0;
							boo=1;
						}
					}
				}
				break;
			}
//右****************************************************************************
		case 'd':case 77:
			{
				bo=0;
				for(g=0;g<a*b;g++)
					i[g][l]=i[g][(l==0)?99:(l-1)];
				for(d=a-1;d<a*b;d+=a)
				{
					for(e=d;;)
					{
						for(;e>=d+1-a&&e<a*b&&!i[e][l];e--);
						for(f=e-1;f>=d+1-a&&f<a*b&&!i[f][l];f--);
						if(f<d+1-a||f>=a*b)
							break;
						if(i[f][l]==i[e][l])
						{
							i[e][l]++;
							i[f][l]=0;
							e=f-1;
							boo=1;
						}
						else
							e=f;
					}
					for(e=g=d;e>=d+1-a&&e<a*b;g--)
					{
						for(e--;e>=d+1-a&&e<a*b&&i[g][l];e--,g--,f++);
						for(;e>=d+1-a&&e<a*b&&!i[e][l];e--,f++);
						if(e>=d+1-a&&e<a*b)
						{
							i[g][l]=i[e][l];
							i[e][l]=0;
							boo=1;
						}
					}
				}
				break;
			}
//跳出*************************************************************************
		case 'e':
			{
				g=0;
				for(e=0;e<a*b;e++)
					if(i[e][l-1]>g)
						g=i[e][l-1];
				printf("游戏结束\n%u\n",cifang(g));
				delete [] i;
				goto loop;
			}
		case 'q':case 8:
			{
				if(m>1)
				{
					if(l>1)l-=2;
					else if(l>0)l=99;
					else l=98;
					bo++;
					m-=2;
				}
				else
				{
					m--;
					if(l>0)l--;
					else l=99;
				}
				l++;
				m++;
				break;
			}
		case 'z':
			{
				if(bo>0)
				{
					bo--;
					m++;
					l++;
					break;
				}
			}/*
		default:
			{
				if(l>0)l--;
				else l=99;
				if(m>0)m--;
				else m=99;
			}*/
		}
//随机函数**********************************************************************
		j%=200;
		do
		{
			j++;
			k%=200;
			k++;
			h%=199;
			h++;
			switch(j%6)
			{
			case 0:
				k+=h;
				break;
			case 1:
				k-=h;
				break;
			case 2:
				k*=h;
				break;
			case 3:
				k^=h;
				break;
			case 4:
				k&=h;
				break;
			case 5:
				k|=h;
				break;
			}
			switch(k%6)
			{
			case 0:
				h+=j;
				break;
			case 1:
				h-=j;
				break;
			case 2:
				h*=j;
				break;
			case 3:
				h^=j;
				break;
			case 4:
				h&=j;
				break;
			case 5:
				h|=j;
				break;
			}
		}
		while(i[h%(a*b)][l]&&j<65535);
		if(j>=65535)
		{
			boo=1;
			for(d=0;d<a;d++)
			{
				for(e=d;e<a*b;e=f)
				{
					for(;e<a*b&&!i[e][l];e+=a);
					for(f=e+a;f<a*b&&!i[f][l];f+=a);
					if(f<a*b&&i[f][l]==i[e][l])boo=0;
				}
			}
			for(d=a*b-1;d>=a*b-a;d--)
			{
				for(e=d;;e=f)
				{
					for(;e<a*b&&!i[e][l];e-=a);
					for(f=e-a;f<a*b&&!i[f][l];f-=a);
					if(f>=a*b)
						break;
					if(i[f][l]==i[e][l])boo=0;
				}
			}
			for(d=0;d<a*b;d+=a)
			{
				for(e=d;;)
				{
					for(;e<a+d&&!i[e][l];e++);
					for(f=e+1;f<a+d&&!i[f][l];f++);
					if(f>=a+d)
						break;
					if(i[f][l]==i[e][l])boo=0;
					e=f;
				}
			}
			for(d=a-1;d<a*b;d+=a)
			{
				for(e=d;;)
				{
					for(;e>=d+1-a&&e<a*b&&!i[e][l];e--);
					for(f=e-1;f>=d+1-a&&f<a*b&&!i[f][l];f--);
					if(f<d+1-a||f>=a*b)
						break;
					if(i[f][l]==i[e][l])boo=0;
					e=f;
				}
			}
			for(j=0;j<a*b;j++)
				if(!i[j][l])
					boo=0;
			if(boo)
			{
				g=0;
				for(e=0;e<a*b;e++)
					if(i[e][l]>g)
						g=i[e][l];
				printf("游戏结束\n%u\n",cifang(g));
				delete [] i;
				goto loop;
			}
		}
		if(boo)
		{
			i[h%(a*b)][l]=1;
			if(h<=10)
				i[h%(a*b)][l]=2;
			if(h==1)
				i[h%(a*b)][l]=3;
		}
		else
		{
			if(l>0)l--;
			else l=99;
			if(m>0)m--;
			else m=99;
		}
//输出******************************************************************************
		for(d=8,g=0;g<a*b;g++)
			if(i[g][l]>d)
				d=i[g][l];
		d=cifang(d);
		for(g=0;0!=d;g++)
			d/=10;
		switch(d=g)
		{
		case 3:
			for(e=a*1/3;e<6;e++)
				printf("\t");
			 
			for(g=0;g<a;g++)
				printf("|---");
			printf("|\n");
			for(g=0;g<b;g++)
			{
				for(e=a*1/3;e<6;e++)
					printf("\t");
				 
				printf("|");
				for(e=0;e<a;e++)
					if(!i[a*g+e][l])
						printf("   |");
					else
						printf("%3u|",cifang(i[a*g+e][l]));
				printf("\n");
				for(e=a*1/3;e<6;e++)
					printf("\t");
				 
				for(e=0;e<a;e++)
					printf("|---");
				printf("|\n");
			}
			for(g=b;g<12;g++)
				printf("\n");
			break;
		case 4:
			for(e=a*5/12;e<6;e++)
				printf("\t");
			 
			for(g=0;g<a;g++)
				printf("|----");
			printf("|\n");
			for(g=0;g<b;g++)
			{
				for(e=a*5/12;e<6;e++)
					printf("\t");
				 
				printf("|");
				for(e=0;e<a;e++)
					if(!i[a*g+e][l])
						printf("    |");
					else
						printf("%4u|",cifang(i[a*g+e][l]));
				printf("\n");
				for(e=a*5/12;e<6;e++)
					printf("\t");
				for(e=0;e<a;e++)
					printf("|----");
				printf("|\n");
			}
			for(g=b;g<12;g++)
				printf("\n");
			break;
		case 5:
			for(e=a;e<6;e++)
				printf("\t");
			for(g=0;g<a;g++)
				printf("|-----");
			printf("|\n");
			for(g=0;g<b;g++)
			{
				for(e=a;e<6;e++)
					printf("\t");				 
				printf("|");
				for(e=0;e<a;e++)
					if(!i[a*g+e][l])
						printf("     |");
					else
						printf("%5u|",cifang(i[a*g+e][l]));
				printf("\n");
				for(e=a;e<6;e++)
					printf("\t");				 
				for(e=0;e<a;e++)
					printf("|-----");
				printf("|\n");
			}
			for(g=b;g<12;g++)
				printf("\n");
			break;
		default:
			for(e=a*(d+1)/6;e<6;e++)
				printf("\t");			 
			for(g=0;g<a;g++)
			{
				printf("|");
				for(f=0;f<d;f++)
					printf("-");
			}
			printf("|\n");
			for(g=0;g<b;g++)
			{
				for(e=a*(d+1)/6;e<6;e++)
					printf("\t");
				printf("|");
				for(e=0;e<a;e++)
					if(!i[a*g+e][l])
					{
						for(f=0;f<d;f++)
							printf(" ");
						printf("|");
					}
					else
					{
						switch(d)
						{
						case 6:
							printf("%6u|",cifang(i[a*g+e][l]));
							break;
						case 7:
							printf("%7u|",cifang(i[a*g+e][l]));
							break;
						case 8:
							printf("%8u|",cifang(i[a*g+e][l]));
							break;
						case 9:
							printf("%9u|",cifang(i[a*g+e][l]));
							break;
						case 10:
							printf("%10u|",cifang(i[a*g+e][l]));
							break;
						case 11:
							printf("%11u|",cifang(i[a*g+e][l]));
							break;
						case 12:
							printf("%12u|",cifang(i[a*g+e][l]));
							break;
						case 13:
							printf("%13u|",cifang(i[a*g+e][l]));
							break;
						default:
							printf("%14u|",cifang(i[a*g+e][l]));
						}
					}
				printf("\n");
				for(e=a*(d+1)/6;e<6;e++)
					printf("\t");
				 
				for(e=0;e<a;e++)
				{
					printf("|");
					for(f=0;f<d;f++)
						printf("-");
				}
				printf("|\n");
			}
			for(g=b;g<12;g++)
				printf("\n");
			break;
		}
		c=_getch();
		if(c==-32)
			c=_getch();
	}
}

int cifang(int i)
{
	int k=1;
	for(int j=0;j<i;j++)
		k*=2;
	return k;
}