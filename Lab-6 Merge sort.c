#include &lt;stdio.h&gt;
#include&lt;time.h&gt;
int a[20],n;
void simple_sort(int [],int,int,int);
void merge_sort(int[],int,int);
int main()
{
int i;
clock_t start, end;
double time_taken;
printf(&quot;Enter the no. of elements:&quot;);
scanf(&quot;%d&quot;, &amp;n);
printf(&quot;Enter the array elements:&quot;);
for (i = 0; i &lt; n; i++) {
scanf(&quot;%d&quot;, &amp;a[i]);
}
start = clock();
merge_sort(a, 0, n - 1);
end = clock();
time_taken = (double)(end - start) / CLOCKS_PER_SEC;
printf(&quot;Sorted array:&quot;);
for (i = 0; i &lt; n; i++) {
printf(&quot;%d &quot;, a[i]);
}
printf(&quot;\n&quot;);
printf(&quot;Time taken to sort: %f seconds\n&quot;, time_taken);
return 0;
}
void merge_sort(int a[],int low, int high){

if(low&lt;high){
int mid=(low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
simple_sort(a,low,mid,high);
}
}
void simple_sort(int a[],int low, int mid, int high){
int i=low,j=mid+1,k=low;
int c[n];
while(i&lt;=mid &amp;&amp; j&lt;=high){
if(a[i]&lt;a[j]){
c[k++]=a[i];
i++;
}else{
c[k++]=a[j];
j++;
}
}
while(i&lt;=mid){
c[k++]=a[i];
i++;
}
while(j&lt;=high){
c[k++]=a[j];
j++;
}
for(i=low;i&lt;=high;i++){
a[i]=c[i];
}
}

OUTPUT:
Enter the number of elements: 5
Enter the array elements: 12 11 13 5 6
Sorted array: 5 6 11 12 13 
Time taken to sort: 0.000000 seconds
