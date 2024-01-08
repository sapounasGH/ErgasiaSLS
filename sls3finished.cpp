#include <iostream>
using namespace std;
#include <queue>
#include <iomanip>
class average{
    public:
    bool hrthe=false;
    bool ektel=false;
    int prosopikos=1;
    bool teleiwse=false;
    int finishtime=-1;
};

int main(){
  int ad=0;
  cout << "Dwse ena arithmo diergasiwn: ";
  cin >> ad;
  int pin[ad][4];
  average art[ad];
  int voithitikos[ad];
  for(int i=0;i<ad;i++){
    cout << "Dwse xrono afiksis: ";
    cin >> pin[i][0];
    pin[i][0]=pin[i][0];
    cout << "Dwse xrono kataigismou: ";
    cin >> pin[i][1];
    cout << "Dwse proteraiothta ekfrasmenh sthn klimaka 1 ews 7, opou to 1 antistoixei sthn ypshloterh proteraiothta kai to 7 sthn xamiloteri proteraiothta: ";
    cin >> pin[i][2];
    pin[i][2]=pin[i][2]-1;
    pin[i][3]=i;
    voithitikos[i]=pin[i][1];
  }
  int kv=0;
  for(int i=0;i<ad;i++){
    kv=kv+pin[i][1];
  }
  cout << "O kvanto xronos einai: " << kv << "\n";
  /*edw arxizoume thn prosomiwsi programma*/
  queue<int> RQ[9];
  queue<int> ready[7];
  int processor[4];
  processor[0]=8;
  processor[1]=8;
  processor[2]=8;
  processor[3]=8;
  int prot=8;
  double metr=0;
  /*h main for arxizei edw*/
  for (int i = 0; i <kv; i++)
  {
    int k=0;
    do
    {
      if (i==pin[k][0])
      {
        RQ[pin[k][2]].push(pin[k][3]);
        art[pin[k][3]].hrthe=true;
        if (i==0)
        {
          processor[0]=pin[k][0];
          processor[1]=pin[k][1];
          processor[2]=pin[k][2];
          processor[3]=k;
          RQ[processor[2]].pop();
        }else if ((processor[2]>pin[k][2]) && (RQ[prot].empty()))
        {
          if (processor[2]!=8)
          {
            RQ[processor[2]].push(processor[3]);
            ready[processor[2]].push(processor[3]);
          }
          processor[0]=pin[k][0];
          processor[1]=pin[k][1];
          processor[2]=pin[k][2];
          processor[3]=k;
          RQ[processor[2]].pop();
        }else if (processor[2]<pin[k][2])
        {
          ready[pin[k][2]].push(pin[k][3]);
        }
      }
      k++; 
    } while (k<ad);
    if (processor[2]!=8)
        {
            RQ[processor[2]].push(processor[3]);
            processor[0]=pin[RQ[processor[2]].front()][0];
            processor[1]=pin[RQ[processor[2]].front()][1];
            processor[2]=pin[RQ[processor[2]].front()][2];
            processor[3]=RQ[processor[2]].front();
            RQ[processor[2]].pop();
    }else if(prot!=8){
        processor[0]=pin[RQ[prot].front()][0];
        processor[1]=pin[RQ[prot].front()][1];
        processor[2]=pin[RQ[prot].front()][2];
        processor[3]=RQ[prot].front();
        RQ[prot].pop();
    }    
    /*edw vlepw an yparxei kapoia etoimh diergasia*/
          for (int p = 0; p < 7; p++)
          {
            if (!ready[p].empty() && processor[0]==8)
            {
              processor[0]=pin[ready[p].front()][0];
              processor[1]=pin[ready[p].front()][1];
              processor[2]=pin[ready[p].front()][2];
              processor[3]=ready[p].front();
              RQ[p].pop();
              ready[p].pop();
              break;
            }
          }
/*edw afairw apo to xrono kataigismoy ths diergasias pou vriskete mesa ston epeksergasti*/
      cout<<"ston kvantoxrono "<<i<<"\n";
      if (processor[2]==8)
      {
          cout<<"Kamia diergasia aderfouli :) \n";
      }else{
        processor[1]--;
        pin[processor[3]][1]--;
        cout<<"ektelesthke h "<< processor[3]+1<< " diergasia \n";
        cout<<"kai o xronos kataigismou einai "<<processor[1]<<"\n";
        art[processor[3]].ektel=true;
        if (processor[1]==0)
        {
          if(!RQ[processor[2]].empty()){prot=processor[2];}
          art[processor[3]].teleiwse=true;
          art[processor[3]].finishtime=i;
          processor[0]=8;
          processor[1]=8;
          processor[2]=8;
          processor[3]=8;
        }else if (i==kv-1 && processor[1]>0)
        {
          RQ[processor[2]].push(processor[3]);
          processor[0]=8;
          processor[1]=8;
          processor[2]=8;
          processor[3]=8;
        }
      }
      for (int g = 0; g < ad; g++)
      {
        if ((art[g].hrthe==true) && (art[g].ektel==false))
        {
            metr++;
        }
        if ((art[g].hrthe==true) && (art[g].teleiwse==false))
        {
            art[g].prosopikos++;
        }
        
      }
  }
  cout<<"\n";
  /*edw elegxo an o procesor den exei tipota mesa toy*/
  cout<< processor[0]<< processor[1]<< processor[2]<< processor[3];
  /*for (int p = 0; p < 7; p++)
  {
    queue<int> temp = RQ[p];
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
    cout << '\n';
  }*/
   for (int p = 0; p < 7; p++)
        {
          do
          {
            if (!RQ[p].empty())
          {
            processor[0]=pin[RQ[p].front()][0];
            processor[1]=pin[RQ[p].front()][1];
            processor[2]=pin[RQ[p].front()][2];
            processor[3]=RQ[p].front();
            --processor[1];
            --pin[processor[3]][1];
            cout<<"ektelesthke h "<< processor[3]+1<< " diergasia \n";
            cout<<"kai o xronos kataigismou einai "<<processor[1];
            if (processor[1]!=0)
            {
              RQ[processor[2]].push(RQ[p].front());
            }
            RQ[p].pop();
          }
          } while (!RQ[p].empty()); 
        }
        cout<<"\n";
        double turnaround=0.0;
        double responsetime1=0.0;
        for (int g = 0; g < ad; g++){
            cout<<"gia thn diergasia "<< g+1<<"\n";
            cout<<"to finish time einai: "<< art[g].finishtime+1<<"\n";
            cout<<"to turnaround time einai: "<< art[g].prosopikos<<"\n";
            responsetime1=(double)art[g].prosopikos/(double)voithitikos[g];
            cout<<"To Tr/Ts ths einai : "<<responsetime1<<"\n";
            turnaround=turnaround+art[g].prosopikos;
        }
        metr=metr/ad;
        turnaround=turnaround/ad;
        cout<<"O average response time einai : "<<metr<<"\n";
        cout<<"TO average turnaround time einai : "<<turnaround;
  /*kai teliwnei edw*/
}


/****************************PROGRAMMA ME TUXAIOYS ARITHMOUS************************************/

/*#include <iostream>
using namespace std;
#include <queue>
#include <cstdlib> 
class average{
    public:
    bool hrthe=false;
    bool ektel=false;
    int prosopikos=1;
    bool teleiwse=false;
    int finishtime=-1;
};

int main(){
  int ad=0;
  int pin[ad][4];
  average art[ad];
  int voithitikos[ad];
  int arithmos1=0;
  int arithmos2=0;
  queue<int> RQ[9];
  queue<int> ready[7];
  int processor[4];
  processor[0]=8;
  processor[1]=8;
  processor[2]=8;
  processor[3]=8;
  int prot=8;
  double metr=0;
  int apofasi=0;
  do
  {
  cout << "Dwse ena arithmo diergasiwn: ";
  cin >> ad;
  for(int i=arithmos1;i<(arithmos1+ad);i++){
    pin[i][0]=(rand() % ((arithmos1+10) - arithmos1 + 1)) + arithmos1;
    pin[i][1]=rand() % 11;
    pin[i][2]=rand() % 7;
    pin[i][3]=i;
    voithitikos[i]=pin[i][1];
  }
  int kv=0;
  for(int i=arithmos1;i<(arithmos1+ad);i++){
    kv=kv+pin[i][1];
  }
  arithmos1=arithmos1+ad+1;
  for (int i = arithmos2; i <(arithmos2+kv); i++)
  {
    int k=0;
    do
    {
      if (i==pin[k][0])
      {
        RQ[pin[k][2]].push(pin[k][3]);
        art[pin[k][3]].hrthe=true;
        if (i==0)
        {
          processor[0]=pin[k][0];
          processor[1]=pin[k][1];
          processor[2]=pin[k][2];
          processor[3]=k;
          RQ[processor[2]].pop();
        }else if ((processor[2]>pin[k][2]) && (RQ[prot].empty()))
        {
          if (processor[2]!=8)
          {
            RQ[processor[2]].push(processor[3]);
            ready[processor[2]].push(processor[3]);
          }
          processor[0]=pin[k][0];
          processor[1]=pin[k][1];
          processor[2]=pin[k][2];
          processor[3]=k;
          RQ[processor[2]].pop();
        }else if (processor[2]<pin[k][2])
        {
          ready[pin[k][2]].push(pin[k][3]);
        }
      }
      k++; 
    } while (k<ad);
    if (processor[2]!=8)
        {
            RQ[processor[2]].push(processor[3]);
            processor[0]=pin[RQ[processor[2]].front()][0];
            processor[1]=pin[RQ[processor[2]].front()][1];
            processor[2]=pin[RQ[processor[2]].front()][2];
            processor[3]=RQ[processor[2]].front();
            RQ[processor[2]].pop();
    }else if(prot!=8){
        processor[0]=pin[RQ[prot].front()][0];
        processor[1]=pin[RQ[prot].front()][1];
        processor[2]=pin[RQ[prot].front()][2];
        processor[3]=RQ[prot].front();
        RQ[prot].pop();
    }    
          for (int p = 0; p < 7; p++)
          {
            if (!ready[p].empty() && processor[0]==8)
            {
              processor[0]=pin[ready[p].front()][0];
              processor[1]=pin[ready[p].front()][1];
              processor[2]=pin[ready[p].front()][2];
              processor[3]=ready[p].front();
              RQ[p].pop();
              ready[p].pop();
              break;
            }
          }
      cout<<"ston kvantoxrono "<<i<<"\n";
      if (processor[2]==8)
      {
          cout<<"Kamia diergasia aderfouli :) \n";
      }else{
        processor[1]--;
        pin[processor[3]][1]--;
        cout<<"ektelesthke h "<< processor[3]+1<< " diergasia \n";
        cout<<"kai o xronos kataigismou einai "<<processor[1]<<"\n";
        art[processor[3]].ektel=true;
        if (processor[1]==0)
        {
          if(!RQ[processor[2]].empty()){prot=processor[2];}
          art[processor[3]].teleiwse=true;
          art[processor[3]].finishtime=i;
          processor[0]=8;
          processor[1]=8;
          processor[2]=8;
          processor[3]=8;
        }else if (i==kv-1 && processor[1]>0)
        {
          RQ[processor[2]].push(processor[3]);
          processor[0]=8;
          processor[1]=8;
          processor[2]=8;
          processor[3]=8;
        }
      }
      for (int g = 0; g < ad; g++)
      {
        if ((art[g].hrthe==true) && (art[g].ektel==false))
        {
            metr++;
        }
        if ((art[g].hrthe==true) && (art[g].teleiwse==false))
        {
            art[g].prosopikos++;
        }
        
      }
  }
  arithmos2=arithmos2+kv+1;
  cout<<"Theleis na synexisoume??? \n";
  cout<<"Enter 1 for yes or 0 for no: ";
  cin>>apofasi;
  cout<<"\n";
  } while (apofasi==1);
  cout<<"\n";
  cout<< processor[0]<< processor[1]<< processor[2]<< processor[3];
   for (int p = 0; p < 7; p++)
        {
          do
          {
            if (!RQ[p].empty())
          {
            processor[0]=pin[RQ[p].front()][0];
            processor[1]=pin[RQ[p].front()][1];
            processor[2]=pin[RQ[p].front()][2];
            processor[3]=RQ[p].front();
            --processor[1];
            --pin[processor[3]][1];
            cout<<"ektelesthke h "<< processor[3]+1<< " diergasia \n";
            cout<<"kai o xronos kataigismou einai "<<processor[1];
            if (processor[1]!=0)
            {
              RQ[processor[2]].push(RQ[p].front());
            }
            RQ[p].pop();
          }
          } while (!RQ[p].empty()); 
        }
        cout<<"\n";
        double turnaround=0.0;
        double responsetime1=0.0;
        for (int g = 0; g < ad; g++){
            cout<<"gia thn diergasia "<< g+1<<"\n";
            cout<<"to finish time einai: "<< art[g].finishtime+1<<"\n";
            cout<<"to turnaround time einai: "<< art[g].prosopikos<<"\n";
            responsetime1=(double)art[g].prosopikos/(double)voithitikos[g];
            cout<<"To response time ths einai : "<<responsetime1<<"\n";
            turnaround=turnaround+art[g].prosopikos;
        }
        metr=metr/ad;
        turnaround=turnaround/ad;
        cout<<"O average response time einai : "<<metr<<"\n";
        cout<<"TO average turnaround time einai : "<<turnaround;
}*/