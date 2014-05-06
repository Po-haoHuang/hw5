#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include<math.h>

using namespace std;



int n,k;
int *flag,*loclist;



int deviation(int * f,int _n,int _k){
	int a=0;
	for(int i=1;i<k+1;i++){
		for(int j=flag[i-1]+1;j<=flag[i];j++)
			a = a + abs(loclist[(int)floor((flag[i-1]+1+flag[i])/2)]-loclist[j]);
	}
	return a;
	
}

void readin(){
	int ans=0,stop=0,temp,record;
	scanf("%d%d",&n,&k);
	loclist = (int*)malloc(sizeof(int)*n);
	flag = (int*)malloc(sizeof(int)*(k-1));
	for(int i=0;i<n;i++){
		scanf("%d",&loclist[i]);
  	}



	for(int i=0;i<k+1;i++){
		if(i==k)
			flag[i] = n-1;
  		else
			flag[i]=i-1;

	}
	ans=deviation(flag,n,k);
	/*for(int i=0;i<k+1;i++)
	cout<<flag[i]<<endl;*/
	while(1){
		stop=0;
		for(int i=1;i<k;i++){
				if((flag[i+1]-flag[i])>1){

				record=flag[i];
				for(int k=flag[i]+1;k<flag[i+1];k++){
					flag[i]=k;
					temp = deviation(flag,n,k);


					if(temp<= ans){
						ans=temp;
						stop=1;
						i=0;
					}
					else{
					flag[i]=record;
					}
				}
			}

		}
		if(stop==0)
			break;
	}
	/*for(int i=0;i<k+1;i++)
	cout<<flag[i]<<endl;*/
	cout<<ans;



}

int main(int argc,char* argv[]){
	readin();
	return 0;
}
