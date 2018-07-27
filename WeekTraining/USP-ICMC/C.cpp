#include<stdio.h>
#include<map>
#include<string>
#include<cstring>
using namespace std;
typedef struct{
	char eq[15];
	char q;
	int tempo;
}sub;
typedef struct{
	char nome[15];
	int p;
	int tentadas[15];
	int tempo;
}team;
int main(){
	int n,m,p;
	team times[205];
	sub submission[10010];
	map <string,int> mapa;
	team max;
	
	scanf("%d %d %d",&n,&m,&p);
	for (int i=0;i<n;i++){
		scanf("%s",times[i].nome);
		mapa[times[i].nome]=i;
		times[i].p=0;
		times[i].tempo=0;
		for (int j=0;j<p;j++)times[i].tentadas[j]=0;
	}
	strcpy(max.nome,times[0].nome);
	max.p=0;
	max.tempo=0;
	char status[5]; 
	int ini=0,fim=0,total=0;
	for (int i=0;i<m;i++){
		scanf("%s %c %d %s",submission[i].eq, &submission[i].q, &submission[i].tempo,status);
		times[mapa[submission[i].eq]].tentadas[submission[i].q-'A']++;
		//printf("%d %d %d\n",ini,fim,total);
		if (status[0]=='O'){
			times[mapa[submission[i].eq]].p++;
			times[mapa[submission[i].eq]].tempo+=submission[i].tempo+20*(times[mapa[submission[i].eq]].tentadas[submission[i].q-'A']-1);
			if (times[mapa[submission[i].eq]].p>max.p){
				//printf("%s ganhando em %d\n",times[mapa[submission[i].eq]].nome,submission[i].tempo);
				if (mapa[max.nome]==0 && mapa[submission[i].eq]!=0){
					fim=submission[i].tempo;
					total+=fim-ini;				
				}else if (mapa[submission[i].eq]==0 && mapa[max.nome]!=0)ini=submission[i].tempo;
				strcpy(max.nome,times[mapa[submission[i].eq]].nome);
				max.p=times[mapa[submission[i].eq]].p;
				max.tempo=times[mapa[submission[i].eq]].tempo;
				
							
			}
			else if (times[mapa[submission[i].eq]].p==max.p && 
			max.tempo>times[mapa[submission[i].eq]].tempo){
				//printf("%s ganhando em %d\n",times[mapa[submission[i].eq]].nome,submission[i].tempo);
				if (mapa[max.nome]==0 && mapa[submission[i].eq]!=0){
					fim=submission[i].tempo;
					total+=fim-ini;				
				}else if (mapa[submission[i].eq]==0 && mapa[max.nome]!=0)ini=submission[i].tempo;				
				strcpy(max.nome,times[mapa[submission[i].eq]].nome);
				max.tempo=times[mapa[submission[i].eq]].tempo;
				 	
			}else if (times[mapa[submission[i].eq]].p==max.p && 
			max.tempo==times[mapa[submission[i].eq]].tempo && mapa[submission[i].eq]==0){
				if (mapa[max.nome]==0 && mapa[submission[i].eq]!=0){
					fim=submission[i].tempo;
					total+=fim-ini;				
				}else if (mapa[submission[i].eq]==0 && mapa[max.nome]!=0)ini=submission[i].tempo;				
				strcpy(max.nome,times[mapa[submission[i].eq]].nome);
				max.tempo=times[mapa[submission[i].eq]].tempo;
			}
		}
		
			
	}
	if (mapa[max.nome]==0){
		fim=300;
		total+=fim-ini;
	}
	printf("%d\n",total);
	


	return 0;
}
