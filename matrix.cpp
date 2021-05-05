#include <bits/stdc++.h>
using namespace std;

int main()
 {
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

*/
