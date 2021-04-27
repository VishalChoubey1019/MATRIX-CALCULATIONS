#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define   pb                     push_back              
#define   yes                    cout<<"yes\n";
#define   no                     cout<<"no\n";
#define   YES                    cout<<"YES\n";
#define   NO                     cout<<"NO\n";
#define   Yes                    cout<<"Yes\n";
#define   No                     cout<<"No\n";
#define   one                    cout<<"1\n";
#define   zero                   cout<<"0\n";
#define   mone                   cout<<"-1\n";
#define   line                   cout<<"\n";;
#define   mp                     make_pair 
#define   pf                     push_front
#define   pii                    pair<int,int> 
#define   t()                    long test;cin>>test;while(test--)
#define   F                      first
#define   S                      second
#define   ft                     front 
#define   bk                     back
#define   ios                    ios_base::sync_with_stdio(false);cin.tie(NULL);   
#define   INF                   1000000000
#define   MAX                    1000000
#define   mod                    1e9+7
#define   endl                   "\n"
#define   input                  for(int i=0;i<n;i++)cin>>a[i];
#define   output                 for(int i=0;i<n;i++)cout<<a[i]<<" ";
#define   loop(a,b)                   for(int i=a;i<b;i++)
#define   loop2(a,b)                  for(int j=a;j<b;j++)
#define   vinput                 for(int i=0;i<n;i++){long x;cin>>x;v.push_back(x);}
typedef   unsigned long long int ull;
typedef   long long int          lli;
typedef   long long              ll;



void st()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("youroutput.txt", "w", stdout);
  
   #endif
     ios;  
}


int main()
 {
  st();

  bool b=0;

  int n=3,m=3;
  double a[n][m];
  double c[n][m];

  cout<<"Enter the numbers of your matrix \n";

  for(int i=1;i<=n;i++) 
  for(int j=1;j<=n;j++)  
      {
          cin>>a[i][j];
          if(a[i][j]!=0 && !b)b=1;
      }

for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    if(i==1 && j==1)
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)][(j+2)] ) - ( a[(i+2)][(j+1)] * a[(i+1)][(j+2)] );
    }
    else if( i==1 && j==2 )
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)][(j+2)%3] ) - ( a[(i+2)][(j+1)] * a[(i+1)][(j+2)%3] );
    }
    else if( i==1 && j==3 )
    {
      c[i][j] = ( a[(i+1)][(j+1)%3] * a[(i+2)][(j+2)%3] ) - ( a[(i+2)][(j+1)%3] * a[(i+1)][(j+2)%3] );
    }
    else if(i==2 && j==1 )
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)%3][(j+2)] ) - ( a[(i+2)%3][(j+1)] * a[(i+1)][(j+2)] );
    }
    else if( i==2 && j==2 )
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)%3][(j+2)%3] ) - ( a[(i+2)%3][(j+1)] * a[(i+1)][(j+2)%3] );
    }
    else if( i==2 && j==3 )
    {
      c[i][j] = ( a[(i+1)][(j+1)%3] * a[(i+2)%3][(j+2)%3] ) - ( a[(i+2)%3][(j+1)%3] * a[(i+1)][(j+2)%3] );
    }
    else if( i==3 && j==1 )
    {
      c[i][j] = ( a[(i+1)%3][(j+1)] * a[(i+2)%3][(j+2)] ) - ( a[(i+2)%3][(j+1)] * a[(i+1)%3][(j+2)] );
    }
    else if( i==3 && j==2 )
    {
      c[i][j] = ( a[(i+1)%3][(j+1)] * a[(i+2)%3][(j+2)%3] ) - ( a[(i+2)%3][(j+1)] * a[(i+1)%3][(j+2)%3] );
    }
    else if( i==3 && j==3 )
    {
      c[i][j] = ( a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3] ) - ( a[(i+2)%3][(j+1)%3] * a[(i+1)%3][(j+2)%3] );
    }
  }
}


  cout<<"\n\n";

  double det = a[1][1]*c[1][1] + a[1][2]*c[1][2] + a[1][3]*c[1][3];
  
  string deter="det" , adj="adj" , inv= "inv" , ran="rank";
  
  
  
   cout<<"If you want the determinant of the given matrix then type 'yes' \n";
   cin>>deter;
   if(deter=="yes" ||deter=="Yes")
   if(det==0)cout<<"DETERMINANT= "<<det<<", Inverse Does Not Exist. \n\n";

else
{
    

  if(deter=="yes" || deter=="Yes")
  cout<<"DETERMINANT:  "<<det<<" \n\n";
  
  
  
  cout<<"\nIf you want the adjoint of the given matrix then type 'yes' \n";
  cin>>adj;
  if(adj=="yes" || adj=="Yes")  
 {
    cout<<"ADJOINT: \n\n";
    for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=m;j++)
      cout<<(c[j][i])<<"   "; 
      cout<<"\n\n";
   }
 }  
  
  
  
  cout<<"\nIf you want the inverse of the given matrix then type 'yes' \n";
  cin>>inv;
  if(inv=="yes" ||inv=="Yes" )
 {
    cout<<"\n\nINVERSE OF THE MATRIX: \n\n";
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        cout<<setprecision(3)<<double(c[j][i]/det)<<"   "; 
    
        cout<<"\n\n";
    }
  
 } 
}

  cout<<"\nIf you want the rank of the given matrix then type 'yes' \n";
  cin>>ran;
  if(ran=="yes" || ran=="Yes")
    {
      if(det!=0)
      cout<<"Rank = 3\n";
      
      else if(a[1][1]*a[2][2]-a[1][2]*a[2][1]!=0 || a[1][2]*a[2][3]-a[2][2]*a[1][3]!=0 || a[2][1]*a[3][2]-a[3][1]*a[2][2]!=0 || a[2][2]*a[3][3]-a[3][2]*a[2][3])
      cout<<"Rank = 2\n";
      
      else if(b)
      cout<<"Rank = 1\n";
      
      else 
      cout<<"Rank = 0\n";
    }

    
  
  return 0;
}


 

/*

11    12    13

21    22    23

31    32    33


 (( a[(i+1)][(j+1)] * a[(i+2)][(j+2)] )) - (( a[(i+2)][(j+1)] * a[(i+1)][(j+2)] ));

for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    if(i==1 && j==1)
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)][(j+2)] )) - (( a[(i+2)][(j+1)] * a[(i+1)][(j+2)] );
    }
    else if( i==1 && j==2 )
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)][(j+2)%3] )) - (( a[(i+2)][(j+1)] * a[(i+1)][(j+2)%3] );
    }
    else if( i==1 && j==3 )
    {
      c[i][j] = ( a[(i+1)][(j+1)%3] * a[(i+2)][(j+2)] )) - (( a[(i+2)][(j+1)%3] * a[(i+1)][(j+2)] );
    }
    else if(i==2 && j==1 )
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)%3][(j+2)] )) - (( a[(i+2)%3][(j+1)] * a[(i+1)][(j+2)] );
    }
    else if( i==2 && j==2 )
    {
      c[i][j] = ( a[(i+1)][(j+1)] * a[(i+2)%3][(j+2)%3] )) - (( a[(i+2)%3][(j+1)] * a[(i+1)][(j+2)%3] );
    }
    else if( i==2 && j==3 )
    {
      c[i][j] = ( a[(i+1)][(j+1)%3] * a[(i+2)%3][(j+2)%3] )) - (( a[(i+2)%3][(j+1)%3] * a[(i+1)%3][(j+2)%3] );
    }
    else if( i==3 && j==1 )
    {
      c[i][j] = ( a[(i+1)%3][(j+1)] * a[(i+2)%3][(j+2)] )) - (( a[(i+2)%3][(j+1)] * a[(i+1)%3][(j+2)] );
    }
    else if( i==3 && j==2 )
    {
      c[i][j] = ( a[(i+1)%3][(j+1)] * a[(i+2)%3][(j+2)%3] )) - (( a[(i+2)%3][(j+1)] * a[(i+1)%3][(j+2)%3] );
    }
    else if( i==3 && j==3 )
    {
      c[i][j] = ( a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3] )) - (( a[(i+2)%3][(j+1)%3] * a[(i+1)%3][(j+2)%3] );
    }

    if((i+j)%2!=0)c[i][j]*=(-1);
  }
}





























  else if( i==3 && j==1 )
    {
       c[i][j] = ( a[(i+1)%3][(j+1)] * a[(i+2)%3][(j+2)] )) - (( a[(i+2)%3][(j+1)] * a[(i+1)%3][(j+2)] );
    }





  a[(i+1)%3][(j+1)] * a[(i+2)%3][(j+2)] )) - (( a[(i+2)%3][(j+1)] * a[(i+1)%3][(j+2)] 











*/