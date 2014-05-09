#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include<math.h>

using namespace std;



int n,k;
int **memo,*loclist;



int mcost(int _h,int _t){
	int a=0,b=(int)floor((_h+_t)/2);
	for(int i=_h;i<=_t;i++)
		a = a + abs(loclist[b]-loclist[i]);

	return a;
	
}

void readin(){
	int ans=0,stop=0,temp,record;
	scanf("%d%d",&n,&k);
	loclist = (int*)malloc(sizeof(int)*n);
	//flag = (int*)malloc(sizeof(int)*(k+1));
	for(int i=0;i<n;i++){
		scanf("%d",&loclist[i]);
  	}
  	if(n==k){
  		cout<<0;
  		return;
	}
  	memo=(int**)calloc(n,sizeof(int*));
  	for(int i=0;i<n;i++)
		memo[i]=(int*)calloc(k,sizeof(int));
		
		
		
	for(int i=1;i<n;i++){
		for(int j=min(i-1,k-1);j>=0;j--){
			//cout<<i+1<<","<<j+1<<endl;
			if(j==0){
				memo[i][j]=mcost(0,i);
				//cout<<memo[i][j]<<endl;
				continue;
			}
			for(int l=i-1;l>=j-1;l--){
			//cout<<"\t"<<l+1<<","<<j<<"\t"<<i-l<<","<<1<<endl;
				if(l==(i-1)){
					temp = memo[l][j-1]+0;
				}
				else if(l==(j-1)){
					if(mcost(l+1,i)<temp)
						temp=mcost(l+1,i);

				}
				else{
					if((memo[l][j-1]+mcost(l+1,i))<temp)
						temp=memo[l][j-1]+mcost(l+1,i);
      				}
			}
			memo[i][j]=temp;
			//cout<<memo[i][j]<<endl;
			if(j==(k-1)&&i==(n-1)){

				cout<<memo[i][j];
				return;
			}
		}
	}



}

int main(int argc,char* argv[]){
	readin();
	return 0;
}
