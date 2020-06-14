#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
int main();
void naoborot(){
	system("cls");
	FILE *o; 
	int N=3,i,f=0,a[3];
	char ch[8][30],y,slovo[N+1][100];
	o=fopen("task.txt","r");  
	for(int i=1; i<N+1; i++){
		fgets(slovo[i], 100,o);
	}
	fclose(o);
	o=fopen("arrayslov.txt","w");  
	fprintf(o,slovo[3]);     
	fclose(o); 
	i=0;
	o=fopen("arrayslov.txt","r");
	while ((y=getc(o))!=EOF)
  	{ 	
  		if(y==' '){
  			y=getc(o);
  			i++;
  			f=0;
		  }
  		ch[i][f]=y;
  		f++;
  	}
  	
  	for(int i=2; i<6; i++){
		ch[4][i]=' ';
	}
	ch[5][4]=' ';
	for(int i=4; i<8; i++){
		ch[6][i]=' ';
	}
	ch[7][4]=' ';
	fclose(o);
	char **mass = new char *[8];
    for(int i = 0; i<8;i++) {
        mass[i] = new char[20];
        mass[i]=ch[i];
    }
    for(int i = 0 ; i < 8; i++){
        for(int j = i+1; j < 8; j++)
            if(strcmp(mass[i], mass[j]) < 0){
                char* tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
    }
    cout<<"Слова из последнего предложения в порядке, обратном алфавитному:"<<endl;
    for(int i=4; i<8; i++){
		mass[4][i]=' ';
	}
    for(int i = 0; i < 8; i++){
        cout << mass[i]<<endl;
    }
    cout<<endl<<"1.Меню"<<endl;
	cout<<"2.Выход."<<endl;
	cout<<"Выберете пункт: ";
	cin>>f;
	if(f==1){
		main();
	}
	else if(f==2){
		exit(1);
	}	
}
void wordog(){
	system("cls");
	FILE *o, *t; 
	int N=3,f=0,a[3];
	char ch[100],y,slovo[N+1][100];
	o=fopen("task.txt","r");  
	for(int i=1; i<N+1; i++){
		fgets(slovo[i], 100,o);
	}
	fclose(o);
	a[0]=strlen(slovo[1]);
	a[1]=strlen(slovo[2]);
	a[2]=strlen(slovo[3]);
	for(int j=a[0]-2,v=0; j>=0,v<=a[0]-1; j--,v++){
		ch[v]=slovo[1][j];
	}
	for(int j=a[1]-2,v=a[0]-1; j>=0,v<=a[0]-2+a[1]-1; j--,v++){
		ch[v]=slovo[2][j];
	}
	for(int j=a[2]-2,v=a[0]-2+a[1]-1; j>=0,v<=a[0]-2+a[1]-1+a[2]-1; j--,v++){
		ch[v]=slovo[3][j];
	}
	o=fopen("arrayslov.txt","w");  
	fprintf(o,ch);     
	fclose(o); 
	o=fopen("arrayslov.txt","r");   // Открытие файла pf для чтения
  	t=fopen("wordog.txt","w");  
	while ((y=getc(o))!=EOF)                  // Чтение символа ch из файла pf
  	{ 
  		if(y=='!'||y=='.'||y=='?'||y==' '){
		  y=getc(o);
 			if (y=='g'||y=='o'){
 			do{	
 			if(y!='!'){
 			putc(y,t);
			 }
			 else putc(' ',t);
			}while ((y=getc(o))!=' '&&y!=EOF);
			fprintf(t," ");  
		 }
	}
  	}
    fclose(t);  
    fclose(o); 
    o=fopen("wordog.txt","r");  
	fgets(slovo[1], 100,o);
	fclose(o); 
	for(int i=0; i<100; i++){
		ch[i]=' ';
	}
	a[0]=strlen(slovo[1]);
	for(int j=a[0]-2,v=0; j>=0,v<=a[0]-1; j--,v++){
		ch[v]=slovo[1][j];
	}
	cout<<endl<<"Все слова, которые окончиваются на o и g: "<<ch<<endl;
	
	cout<<endl<<"1.Меню"<<endl;
	cout<<"2.Выход."<<endl;
	cout<<"Выберете пункт: ";
	cin>>f;
	if(f==1){
		main();
	}
	else if(f==2){
		exit(1);
	}	
}
void first(){
	FILE *o, *t; 
	int N=1,f=0;
	system("cls");
	cout<<"Введите предложение:";
	char y,slovo[N+1][100];
	for(int i=0; i<N+1; i++){
		gets(slovo[i]);
	}
	o=fopen("arrayslov.txt","w");
	for(int i=1; i<N+1; i++){
		fprintf(o,slovo[i]);                
	}
	fclose(o);
	o=fopen("arrayslov.txt","r");  
  	t=fopen("firstword.txt","w");  
	while ((y=getc(o))!=' ')                  
  	{ 
 		putc(y,t);	
  	}
    fclose(t);
    rewind(o);   
	fclose(o);    
	cout<<"Смотрите файл firstword.txt";
	cout<<endl<<"1.Меню"<<endl;
	cout<<"2.Выход."<<endl;
	cout<<"Выберете пункт: ";
	cin>>f;
	if(f==1){
		main();
	}
	else if(f==2){
		exit(1);
	}	
}

int main(){
	setlocale(LC_ALL, "Russian");
	int v;
	system("cls");
	cout<<"Menu:"<<endl;
	cout<<"1.Первое слово."<<endl;
	cout<<"2.Слова окан-ся на o и g."<<endl;
	cout<<"3.Последнее предложение еаоборот."<<endl;
	cout<<"4.Выход."<<endl;
	cout<<"Выберете пункт: ";
	cin>>v;
	if(v==1){
		first();
	}
	else if(v==2){
		wordog();
	}
	else if(v==3){
		naoborot();
	}
	else if(v==4){
		return 0;
	}
	
}
/*aaaaa,ttttt.
rrrrr,eeee.*/
