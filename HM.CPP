#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
main()
{
 int i, j, len, ch, c1, c2, gd=DETECT, gm;
 char a[10], b[10], c[10], d[10], let;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 clrscr();
 setbkcolor(BLACK);
 setcolor(BLACK);
 printf("\n Enter the word : ");
 scanf("%s",a);
 clrscr();

 for(i=0;i<20;i++)
   d[i]='*';
 d[20]='\0';

 len=strlen(a);
 strcpy(b,a);

 for(i=0;i<len;i++)
   c[i]='*';
 c[len]='\0';

 j=0;
 c2=0;
 do
  {
    puts(c);
    label :
    getchar();
    printf("Enter the letter : ");
    scanf("%c",&let);
    c1=0;
    for(i=0;i<j;i++)
     if(d[i]==let)
       {
	  printf("\n This letter is chosen. Try a different one! ");
	  goto label;
       }
    d[j]=let;
    j++;
    for(i=0;i<len;i++)
    {
      if(let==b[i])
	    c[i]=let;
      else
	    c1++;
    }

    if(strcmp(c,a)==0)
	{clrscr();printf("\n You got it right!"); getch(); exit(0);}
    if(c1==len)
    {
      c2++;
      switch(c2)
      {
	    case(0) : break;
  /*face*/  case(1) : {
		      circle(480,120,20);
		      circle(485,117,3);
		      circle(475,117,3);
		      line(472,133,488,133);
		      }
		      break;
  /*body*/  case(2) : line(480,140,480,180); break;
  /*hand*/  case(3) : line(480,160,500,160); break;
  /*hand*/  case(4) : line(480,160,460,160); break;
  /*legs*/  case(5) : line(480,180,500,195); break;
  /*legs*/  case(6) : line(480,180,460,195); break;
  /*hang*/  case(7) : {
		      line(440,140,520,140);
		      line(440,80,480,80);
		      line(440,80,440,200);
		      line(440,200,505,200);
		      line(480,80,480,100);
		      printf("\n YOU LOST! ");
		      break;
		      }
      }
    }
  }while(c2<7);
 getch();
 clrscr();
 closegraph();
 restorecrtmode();
 return(0);
}

