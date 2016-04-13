#include<iostream.h>
#include<conio.h>
class prio
{
      public:
      int n,bt[20],wt[20],awt,tat,tp,name[10],atat,pre[10],pro[20];
      
      void input()
      {
           
           cout<<"Enter number of JOBS";
           cin>>n;
           cout<<"Enter process name of JOBS";
           for(int i=1;i<=n;i++)
                   {
                   cin>>pre[i];
                   }
            cout<<"Enter priority of JOBS";
           for(int i=1;i<=n;i++)
                   {
                   cin>>pro[i];
                   }
           cout<<"Enter the burst times of JOBS";
           for(int i=1;i<=n;i++)
                   {
                   cin>>bt[i];
                   }
      }
      
      void sort()
      {
           for(int i=1;i<=n;i++)
           {
                   for(int j=1;j<=n-i;j++)
                   {
                           if(pro[j]>pro[j+1])
                           {
                                            int temp3=pro[j];
                                            pro[j]=pro[j+1];
                                            pro[j+1]=temp3;  
                                            
                                            int temp2=pre[j];
                                            pre[j]=pre[j+1];
                                            pre[j+1]=temp2;
                           
                                            int temp=bt[j];
                                            bt[j]=bt[j+1];
                                            bt[j+1]=temp;
                           }
                   }
           }
           }
      void cal()
      {
           //wait times
           wt[1]=0;
           wt[2]=bt[1];
           for (int i=3;i<=n;i++)
           {
               wt[i]=bt[i-1]+wt[i-1];
           }
           awt=0;
           for(int i=1;i<=n;i++)
           {
                   awt=awt+wt[i];
           }
           awt=awt/n;
           
           tat=0;
            for(int i=1;i<=n;i++)
           {
                     tat=tat+wt[i];
           }
           tat=tat+bt[n]+wt[n];
      }
      
      
      void disp()
      {
                
           cout<<"\n Name: \t\t Process: \t\t Priority: \t\t Burst time: \t\t Wait Time:";
         
                                
                                for(int i=1;i<=n;i++)
                                {
                                
                   cout<<"\n"<<"P"<<i<<"\t\t"<<pre[i]<<"\t\t"<<pro[i]<<"\t\t "<<bt[i]<<"\t\t";
                   }
                   wt[1]=0;
                   cout<<wt[1]<<"\n";
                   for(int i=2;i<=n;i++)
                   {
                           cout<<"\t\t"<<wt[i]<<"\n";
                   }
           cout<<"\n \n Average Wait time:"<<awt<<"\n\n Turn around time:"<<tat<<"\n\n Avg turn around time:"<<tat/n<<"\n Throughput:"<<((float)n/(bt[n]+wt[n]));
      }
};

int main()
{
    {
    prio p;
    p.input();
    p.sort();
    p.cal();
    p.disp();
    }
    getch();
}
