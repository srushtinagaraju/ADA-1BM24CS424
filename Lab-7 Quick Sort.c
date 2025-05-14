#include&lt;time.h&gt;
#include&lt;stdio.h&gt;
#define MAX 5000
void quicksort(int[],int,int);
int partition(int[],int,int);
void main()
{
int i,n,a[MAX],ch;
clock_t start,end;
clrscr();
while(ch)
{
printf(&quot;\n enter the number of elements\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
for(i=0;i&lt;n;i++)
a[i]=rand()%200;
printf(&quot;The random generated array is\n&quot;);
for(i=0;i&lt;n;i++)
printf(&quot; %d&quot;,a[i]);
start=clock();
quicksort(a,0,n-1);
end=clock();
printf(&quot;\n\nthe sorted array elements are\n\n&quot;);
for(i=0;i&lt;n;i++)
printf(&quot;%d\n&quot;,a[i]);
printf(&quot;time taken = %f&quot;,(end-start)/CLK_TCK);
printf(&quot;\n\n do u wish to continue (0/1)\n&quot;);
scanf(&quot;%d&quot;,&amp;ch);
}
}
void quicksort(int a[],int low,int high)
{
int mid;
delay(500);
if(low&lt;high)
{
mid=partition(a,low,high);
quicksort(a,low,mid-1);
quicksort(a,mid+1,high);

}
}
int partition(int a[],int low,int high)
{
int key,i,j,temp,k;
key=a[low];
i=low+1;

j=high;
while(i&lt;=j)
{
while(i&lt;=high &amp;&amp; key&gt;=a[i])
i=i+1;
while(key&lt;a[j])
j=j-1;
if(i&lt;j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
else
{
k=a[j];
a[j]=a[low];
a[low]=k;
}
}
return j;
}

OUTPUT:
Enter the number of elements: 5
The random generated array is:
13 125 97 58 72 
The sorted array elements are:
13
58
72
97
125
Time taken = 0.000056 seconds
Do you wish to continue (0/1)? 1
Enter the number of elements: 7
The random generated array is:
134 92 59 23 78 161 104 
The sorted array elements are:
23
59
78
92
104
134
161
Time taken = 0.000070 seconds
Do you wish to continue (0/1)? 0
