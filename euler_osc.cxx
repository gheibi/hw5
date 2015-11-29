#include<iostream>
#include<cmath>

using namespace std;

int main(){
int N=100;                      // pi/N is the time step
int d=2,s;                     // d= dimention of matrixes yf[], yb[], and ya[]
double dt,t,yf_0,yf_1;        // dt= delta time (time step), t= The end of time interval
double yb[d], yf[d], ya[d];  // yb= y backward, yf= y forward, ya= y analytical
yb[0]=1;                    // yb[0]=x in backward Euler method
yb[1]=0;                   // yb[1]=x' in backward Euler method
yf[0]=1;                  // yf[0]=x   in forward Euler method
yf[1]=0;                 // yf[1]=x'   in forward Euler method
ya[0]=1;                // x=cos(0)
ya[1]=0;               // x'=-sin(0)

dt=M_PI/N;
t=20*M_PI;
s=t/dt;            // s= The # of time steps
for(int i=1; i<=s; i++){

  cout<<i*dt<<'\t'<< yb[0] <<'\t'<< yf[0] <<'\t'<< ya[0] <<endl;
  
ya[0]=cos(i*dt);
ya[1]=-sin(i*dt);

yf_0=yf[0]+yf[1]*dt;
yf_1=yf[1]-yf[0]*dt;
 yf[0]=yf_0;
 yf[1]=yf_1;
 
yb[0]=(yb[0]+yb[1]*dt)/(1+dt*dt);
yb[1]=yb[1]-yb[0]*dt;

}
  
return 0;
}