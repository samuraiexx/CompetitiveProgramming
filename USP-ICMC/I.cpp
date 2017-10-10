#include<stdio.h>
int A[1010][1010];
int main(){
	int n;
	
	int sA=0;
	int filaA[1010],colA[1010];
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		filaA[i]=0;
		for (int j=0;j<n;j++){
			scanf("%d",&A[i][j]);
			sA+=A[i][j];
			filaA[i]+=A[i][j];
		}
	}
	for (int i=0;i<n;i++){
		colA[i]=0;
		for (int j=0;j<n;j++){
			colA[i]+=A[j][i];
		}
	}
	int s;
	if (n==1)
		if((A[0][0]==1 || A[0][0]==0)) return printf("1\n"), 0;
		else return printf("0\n"), 0;

	if (sA%(2*n -1)!=0)printf("0\n");
	else{
		s=sA/(2*n -1);
		bool ok=true;
		for (int i=0;i<n && ok;i++){
			for (int j=0;j<n && ok;j++){
				if ((filaA[i]+colA[j]-2*s)%(n-1)!=0)ok=false;
				else if (((filaA[i]+colA[j]-2*s)/(n-1) - A[i][j])!=0 &&
 					((filaA[i]+colA[j]-2*s)/(n-1) - A[i][j])!=1)ok=false;
			}		
		}
		if (ok)printf("1\n");
		else printf("0\n");
	} 
	return 0;
}
