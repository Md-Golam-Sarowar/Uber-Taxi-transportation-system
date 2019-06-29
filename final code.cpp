#include<bits/stdc++.h>
#include<cstdio>
#include<windows.h>
#include<cstring>
using namespace std;

map<string, int> m;
int arr[100][100];
int path [100][100];
int taka;
int count1=0;
pair<int , int> p[100];
int travel[100];

void available_balance(string st)
{
    int a,q=0;
    string strn;

    ifstream it;
    it.open("cost.txt");

    while(!it.eof())
    {
        getline(it, strn);

        if(strn==st)
        {
            it>>a;

            cout<<"Cost is "<<a<<" TK."<<endl;

            taka-=a;

            q=1;
        }
    }

    if(q==0)
    {
        cout<<"Please enter correct place."<<endl;
    }

    cout<<"Available balance : "<<taka<<endl;
}

void pathfind(string s1, string s2)
{
    string city1 , city2;
    vector<int>v;
    int dist,op;
    city1 = s1;
    city2 = s2;

    int a,b,c,i,j,f;
    a=m[city1];
    b=m[city2];
    p[count1++]= make_pair(a,b);
    dist = arr[a][b];
  //  cout<<dist<<endl;
    if((dist*2)>taka)
    {
        cout<<"\n\t\tYou have not enough taka to go there \n"<<endl;
        return;
    }

    c=b;
      cout<<"\n\n\t\tShortest path is: ";
       map<string, int>:: iterator  it;
        for(it=m.begin();it!=m.end(); ++it)
        {
            if((*it).second == a)
            {
                cout<<(*it).first;
                break;
            }

        }

    while(1)
    {

           j=path[a][b];
            b=j;
          if(b==a || b==-1)
            break;
            v.push_back(j);
    }
    reverse(v.begin(), v.end());
    v.push_back(c);

    while(!v.empty())
    {
        f=v[0];
        v.erase(v.begin());
    for(it=m.begin();it!=m.end(); ++it)
           {
            if((*it).second == f)
            {
                cout<<"-->"<<(*it).first ;
                 break;
            }

         }

    }
     cout<<endl;

  cout<<"\t\tWhat vehicle you want to go: "<<endl<<endl;
    if((dist*10)<taka)
       cout<<"\t\tPress 1 to rickshah and cost of it : "<<(dist*10)<<endl;
     if((dist*5)<taka)
         cout<<"\t\tPress 2 to UBAR taxi and cost of it : "<<(dist*5)<<endl;
    if ((dist*2)<taka)
         cout<<"\t\tPress 3 to bus and cost of it : "<<(dist*2)<<endl;
     cout<<"\t\t";
     cin>>op;

    if(op==1)
    {
        taka = taka - (dist*10);
        travel[count1-1]= (dist*10);
    }
    else if(op==2)
    {
        taka = taka - (dist * 5);
         travel[count1-1]= (dist*5);
    }
    else
    {
        taka = taka -(dist * 2);
        travel[count1-1]= (dist*2);
    }
    system("cls");
}

void Floyds_warshal(int c)
{
    int i, j, k;

    for(i=1;i<c;i++)
    {
        for(j=1;j<c;j++)
        {
            if(i==j || arr[i][j]==100000)
                path[i][j]=-1;
            else
                path[i][j]=i;
        }
    }

    for(k=1;k<c;k++)
    {
        for(i=1;i<c;i++)
        {
            for(j=1;j<c;j++)
            {
                if(arr[i][j] > arr[i][k]+arr[k][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                       path[i][j]= path[k][j];
                }
            }
        }
    }


    for(i=1;i<c;i++)
    {
        arr[i][i]=0;
    }
//  for(i=1;i<c;i++){
//  for(j=1;j<c;j++)
//   {
//       cout<<arr[i][j]<<"  ";
//   }
//   cout<<endl;
//  }
//  cout<<endl<<endl;
//   for(i=1;i<c;i++){
//  for(j=1;j<c;j++)
//   {
//       cout<<path[i][j]<<"  ";
//   }
//   cout<<endl;
//  }
// pathfind();

}

void Input()
{
    string a,b;
    int c=1,s;

    fill(&arr[0][0], &arr[99][99], 100000);
    fill(&path[0][0], &path[99][99], 100000);


    ifstream input("places.txt");

    if(input)
    {
    while(!input.eof())
    {
        input>>a>>b>>s;

        if(m[a]==0)
        {
            m[a]=c;
          //  cout<<a<<"  "<<c<<endl;
            c++;
        }

        if(m[b]==0)
        {
            m[b]=c;
           // cout<<b<<"  "<<c<<endl;
            c++;
        }

        arr[m[a]][m[b]]=s;
        path[m[a]][m[b]] = m[a];

    }

    }
    else
    {
        cout<<"\t\tNot found"<<endl;
    }


   Floyds_warshal(c);
}

void cost()
{
    char ch;
    string st;

    cout<<"\n\t\tDo you want to visit any place? : ";
    cin>>ch;

    cin.ignore();

    if(ch=='Y' || ch=='y')
    {
        cout<<"\t\tEnter the place you want to visit : ";
        getline(cin,st);
        available_balance(st);
    }
    else if(ch=='N' || ch=='n')
    {
        return;
    }
    else
    {
        cout<<"\t\tPlease follow input procedure"<<endl;
    }
    system("cls");
}

void places(string s1)
{
    string line,line1,str;
    int v=0,k=0;
   cout<<"\n\n";
    //cout<<"Enter a place to check out which famous place you can visit & where you will get our UBER taxi : ";
    //cin>>line;
    line = s1;

    ifstream input("places1.txt");

    while(!input.eof())
    {
        getline(input, line1);

        if(line==line1)
        {
            v=1;
        }

        if(v==1)
        {
            if(k!=0)
            {
                if(m[line1]>0 && m[line1]<20)
                {
                    break;
                }

                cout<<"\t\t"<<line1<<endl;

            }

            k++;

        }


    }

    cost();
}

void list1()
{
    cout<<"\n\n\t\tDo you want to see the list which place you visit : ";
    char cc;
     cin>>cc;
    if(cc=='y' || cc=='Y')
        {

      for(int i=0;i<count1;i++)
        {
      int aa, bb;
      aa=p[i].first;
      bb=p[i].second;
      cout<<"\t\t"<<i+1<<". ";
       map<string, int>:: iterator  it;
        for(it=m.begin();it!=m.end(); ++it)
        {
            if((*it).second == aa)
            {
                cout<<(*it).first<<" to ";
                break;
            }

        }

        for(it=m.begin();it!=m.end(); ++it)
        {
            if((*it).second == bb)
            {
                cout<<(*it).first<<"  ";
                break;
            }

        }
      cout<<"and travel cost is "<<travel[i]<<" tk"<<endl;
        }
  }
  else if (cc!='y' || cc!='Y')
       return ;

}

void available_taxi()
{
    string line,line1,str;
    int v=0,k=0;

    cout<<"\n\n\t\tEnter current location : ";
    cin>>line;

    ifstream input("uber.txt");

    while(!input.eof())
    {
        getline(input, line1);

        if(line==line1)
        {
            v=1;
        }

        if(v==1)
        {
            if(k!=0)
            {
                if(m[line1]>0 && m[line1]<20)
                {
                    break;
                }

                cout<<"\t\t"<<line1<<endl;

            }

            k++;

        }


    }
}



int main()
{
    system("color B0");


    Input();
    int p=0;
    cout<<endl<<endl<<"********* Welcome to UBER Taxi Transportation system***********"<<endl;

    string start;

    string s11, s22;

    while(1)
    {
    int n;
    if(p==0)
    cout<<"\n\t\tPress 0 to enter start "<<endl;
    cout<<"\t\tPress 1 to visit another place "<<endl;
    cout<<"\t\tPress 2 to visit around famous places "<<endl;
    cout<<"\t\tPress 3 to go home"<<endl;
    cout<<"\t\tpress 4 to show available Taxi "<<endl;
    cout<<"\t\tpress 5 to show show the visited places"<<endl;
    cout<<"\t\tpress 6 to Exit"<<endl;
    cout<<"\t\t";
    cin>>n;
     system("cls");

    string vis;
   // cin>>vis;


    switch(n)
    {
    case 0:
           system("color A0");
           cout<<endl<<endl<<"\t\tEnter where are you live: ";
           cin>>start;
           system("cls");
           cout<<endl<<endl<<"\t\tEnter how much money you have: ";
          // cout<<"\t\t";
           cin>>taka;
           system("cls");
           s11 = start;
           s22 = start;
           p=1;
           break;

    case 1:
        system("color C0");
        cout<<"\n\n\t\tEnter name where you want to go: ";
       // cout<<"\t\t";
        cin>> s22;
        system("cls");
        pathfind(s11, s22);
        break;

    case 2:
        system("color D0");
        places(s11);
        break;

    case 3:
        system("color E0");
        pathfind(s11, start);
        break;

    case 4:
        system("color F0");
        available_taxi();
        break;
    case 5:
        system("color F0");
        list1();
        break;
    case 6:
        exit(0);
        break;

    default:
        cout<<"Please follow input procedure.";
    }
   s11=s22;
   cout<<"\n\t\tYou have "<<taka<<" tk"<<endl;
    }

}

