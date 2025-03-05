#include <stdio.h>
int main(){
int p[10],pri[10],bt[10],wt[10],tat[10],i,n,temp,j;
float avgwt,avgtat;
printf("enter no.process");
scanf("%d",&n);
for(i=0;i<n;i++){
p[i]=i;
printf("enter busrt and priority %d",i);
scanf("%d%d",&bt[i],&pri[i]);
}
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(pri[i]>pri[j]){
temp=p[i];
p[j]=p[i];
p[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
}}}
avgwt=wt[0]=0;
avgtat=tat[0]=bt[0];
for(i=1;i<n;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
avgwt+=wt[i];
avgtat+=tat[i];
}
printf("\nprocess\t\tpriority\t\tburst\t\twaiting\t\tturnaround");
for(i=0;i<n;i++){
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",p[i],pri[i],bt[i],wt[i],tat[i]);
}
printf("\nAverage Waiting time:%f\n",avgwt/n);
printf("Average Turn Around Time%f\n",avgtat/n);
return 0;
}
