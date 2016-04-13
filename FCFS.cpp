#include<iostream.h>
#include<conio.h>
class FCFS
{
      public:
      int n,bt[20],wt[20],awt,tat,tp,name[10],atat;
      
      void input()
      {
           
           cout<<"Enter number of JOBS";
           cin>>n;
           cout<<"Enter the burst times of JOBS";
           for(int i=1;i<=n;i++)
                   {
                   cin>>bt[i];
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
                
           cout<<"\n Name: \t\t Burst time: \t\t Wait Time:";
           wt[1]=0;
                                cout<<"\n"<<"P"<<1<<"\t\t "<<bt[1]<<"\t\t"<<wt[1]<<"\n";
           for(int i=2;i<=n;i++)
                   {
                                cout<<"\n"<<"P"<<i<<"\t\t "<<bt[i]<<"\t\t"<<wt[i]<<"\n";
                   }
           cout<<"\n \n Average Wait time:"<<awt<<"\n\n Turn around time:"<<tat<<"\n\n Avg turn around time:"<<tat/n;
      }
};

int main()
{
    {
    FCFS f;
    f.input();
    f.cal();
    f.disp();
    }
    getch();
}
