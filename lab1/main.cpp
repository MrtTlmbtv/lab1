#include <ctime>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
const int M=538; //ЧИСЛО ГОРОДОВ
using namespace std;
typedef struct gorod{
string name;
int god;
int naselenie;
};
//
//
//
//
// СОРТИРОВКА ШЕЛЛА
//
//
//
//
//
void ShellSort(int *a, int n)
{
	time_t start, end;
	double seconds;
	int perestanovki=0;
	int sravneniya=0;
	int i, j, k, temp;
		start = clock();
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				sravneniya++;
				if(a[k+i] >= a[k])
				break;
			
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
					perestanovki++;
				}
			}
		}
	}
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя Shell сортировки = " << seconds;
	cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}

void ShellSortsgod(gorod *a, int n)
{
	time_t start, end;
	double seconds;
	int i, j, k; 
	int perestanovki=0;
	int sravneniya=0;
	gorod temp;
		start = clock();
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				sravneniya++;
				if(a[k+i].god >= a[k].god)
				break;
			
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
					perestanovki++;
				}
			}
		}
	}
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя сортировки по году = " << seconds;
	cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}



void ShellSortsnaselenie(gorod *a, int n)
{
	time_t start, end;
	double seconds;
	int i, j, k; 
	int perestanovki=0;
	int sravneniya=0;
	gorod temp;
		start = clock();
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				sravneniya++;
				if(a[k+i].naselenie >= a[k].naselenie)
				break;
			
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
					perestanovki++;
				}
			}
		}
	}
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя сортировки по населению = " << seconds;
	cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}
//
//
//
//
//ГЛУПАЯ СОРТИРОВКА
//
//
//
//
//
void stupidSort(int *arr,int size)
{
	time_t start, end;
	double seconds;
	int perestanovki=0;
	int sravneniya=0;
    int i = 0, tmp;
		start = clock();
    while (i < size - 1)
    {
		sravneniya++;
        if (arr[i + 1] < arr[i])
        {
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
            i = 0;
			perestanovki++;
        }
        else i++;
    }
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя Stupid сортировки = " << seconds;
	cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}

void stupidSortsgod(gorod *arr,int size)
{
	time_t start, end;
	double seconds;
	int perestanovki=0;
	int sravneniya=0;
    int i = 0;
	gorod tmp;
		start = clock();
    while (i < size - 1)
    {
		sravneniya++;
        if (arr[i + 1].god < arr[i].god)
        {
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
            i = 0;
			perestanovki++;
        }
        else i++;
    }
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя сортировки по населению = " << seconds;
	cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}

void stupidSortsnaselenie(gorod *arr,int size)
{
	time_t start, end;
	double seconds;
    int i = 0;
	int perestanovki=0;
	int sravneniya=0;
	gorod tmp;
		start = clock();
    while (i < size - 1)
    {
		sravneniya++;
        if (arr[i + 1].naselenie < arr[i].naselenie)
        {
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
            i = 0;
			perestanovki++;
        }
        else i++;
    }
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя сортировки по населению = " << seconds;
	cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}
//
//
//
//
//ДВОЙНЫЕ ВСТАВКИ
//
//
//
//
//
void sort_bin_insert(int *a, int n)
{ int x, left, right, sred;
	time_t start, end;
	double seconds;
	int perestanovki=0;
	int sravneniya=0;
	start = clock();
  for (int i=1; i<n; i++)
  {
	sravneniya++;
    if (a[i-1]>a[i]) 
       {   x=a[i];     
          left=0;       
          right=i-1;    
               do{
                       sred = (left+right)/2;  
					   sravneniya++;
                         if (a[sred]<x )   left= sred+1;
                             else right=sred-1;
          }while(left<=right);     
                                                          
			   for (int  j=i-1;   j>=left;   j--){ a[j+1]= a[j];}
            a[left]= x; perestanovki++;
      }
  }
  end = clock();
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя bin insertion = " << seconds;
  cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}

void sort_bin_insertsgod(gorod *a, int n)
{ int left, right, sred;
time_t start, end;
	double seconds;
int perestanovki=0;
	int sravneniya=0;
gorod x;
	start = clock();
  for (int i=1; i<n; i++)
  {
	sravneniya++;
    if (a[i-1].god>a[i].god) 
       {   x=a[i];     
          left=0;       
          right=i-1;    
               do {
                       sred = (left+right)/2;  
					    sravneniya++;
                         if (a[sred].god<x.god )   left= sred+1;
                             else right=sred-1;
          } while (left<=right);     
                                                          
           for (int  j=i-1;   j>=left;   j--) a[j+1]= a[j];
            a[left]= x; perestanovki++;
      }
  }
  end = clock();
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя сортировки по году = " << seconds;
  cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}
void sort_bin_insertsnaselenie(gorod *a, int n)
{ int left, right, sred;
time_t start, end;
	double seconds;
gorod x;
int perestanovki=0;
	int sravneniya=0;
		start = clock();
  for (int i=1; i<n; i++)
  {
	  sravneniya++;
    if (a[i-1].naselenie>a[i].naselenie) 
       {   x=a[i];     
          left=0;       
          right=i-1;    
               do { sravneniya++;
                       sred = (left+right)/2;      
                         if (a[sred].naselenie<x.naselenie )   left= sred+1;
                             else right=sred-1;
          } while (left<=right);     
                                                          
           for (int  j=i-1;   j>=left;   j--) a[j+1]= a[j];
            a[left]= x;perestanovki++;
      }
  }
  end = clock();
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя сортировки по  населению = " << seconds;
  cout << "\nЧисло сравнений = " << sravneniya << "\nЧисло перестановок = " << perestanovki;
}
//
//
//
//
//ПОРАЗРЯДНАЯ СОРТИРОВКА
//
//
//
//
//
void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
	time_t start, end;
	double seconds;
    int i,k,n;
    k = sizeC;
    n = sizeAB;
	start = clock();
	int perestanovki=0;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
      {
         br[cr[ar[i]]-1]=ar[i];
         cr[ar[i]]-=1;
		 perestanovki++;
      }
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя radix сортировки " << seconds;
	cout << "\nЧисло перестановок = " << perestanovki;
  }


void radixsgod(gorod *ar, gorod *br, int *cr, int sizeC, int sizeAB)
{
	time_t start, end;
	double seconds;
	start = clock();
    int i,k,n;
    k = sizeC;
    n = sizeAB;
	int perestanovki=0;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i].god]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
      {
         br[cr[ar[i].god]-1]=ar[i];
         cr[ar[i].god]-=1;
		 perestanovki++;
      }
	  end = clock();
	  seconds = (double)(end - start) / CLOCKS_PER_SEC;
	  cout << "\nВремя сортировки по  населению " << seconds;
	  cout << "\nЧисло перестановок = " << perestanovki;
  }

void Sort(int *a, int n) //Для лучшего случая
{
	int i, j, k, temp;
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				if(a[k+i] >= a[k])
				break;
			
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
				}
			}
		}
	}
}

void reverse(int *a, int n){
	for (int i  = 0; i < n / 2; i++)
 swap(a[i], a[n - i - 1]);
}




int main(){
label1:
	int a;
	setlocale(LC_ALL,"Russian");
	int choice;
	cout << "Сортировка\n1. База данных\n2. Массив чисел\n";
	cin >> choice;
	switch (choice){
	case 1:{
		ifstream fin;
		ofstream fout1;
		ofstream fout2;
		fout1.open("GorodaSortedGod.txt");
		fout2.open("GorodaSortedNaselenie.txt");
		fin.open("Goroda.txt");
		struct gorod g[M];
		struct gorod gB[M];
		int cgod[2018];
		for(int i=0;i<M;++i){
		fin >> g[i].name>> g[i].naselenie >> g[i].god;
		}
		int choice2;
		system("cls");
		cout << "\n1. Сортировка Шелла\n2. Поразрядная сортировка\n3. Глупая сортировка\n4. Сортировка двойными вставками\n";
		cin >> choice2;
		if(choice2==1){
			ShellSortsgod(g,M);
			for(int i=0;i<M;++i){
				fout1 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
			ShellSortsnaselenie(g,M);
			for(int i=0;i<M;++i){
				fout2 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
		}
		else if(choice2==2){
			radixsgod(g,gB,cgod,2017,M);
			for(int i=0;i<M;++i){
				fout1 <<  gB[i].name <<"   "<< gB[i].naselenie << "   "<< gB[i].god << "\n";
			}
		}
		else if(choice2==3){
			stupidSortsgod(g,M);
			for(int i=0;i<M;++i){
				fout1 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
				}
			stupidSortsnaselenie(g,M);
			for(int i=0;i<M;++i){
				fout2 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
		}
		else if(choice2==4){
			sort_bin_insertsgod(g,M);
			for(int i=0;i<M;++i){
				fout1 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
				}
			sort_bin_insertsnaselenie(g,M);
			for(int i=0;i<M;++i){
				fout2 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
		}
		fout1.close();
		fout2.close();
		fin.close();
		break;
		   }
	case 2:{
		int N2,N;
		srand(time(NULL));
		cout << "\nВведите размер массива: ";
		cin >> N;
		int *a1=new int[N];
		int *b1=new int[N];
		int c[101];
		cout << "\n1. Средний случай \n2. Худший случай \n3. Лучший случай\n";
		cin >> N2;
		if(N2==1){ //средний случай
		
		///
		for(int i=0;i<N;++i){
		a1[i]=rand()%101;
		}
		radix(a1,b1,c,100,N);
		///
		for(int i=0;i<N;++i){
		a1[i]=rand()%101;
		}
		ShellSort(a1,N);
		///
		for(int i=0;i<N;++i){
		a1[i]=rand()%101;
		}
		sort_bin_insert(a1,N);
		///
		for(int i=0;i<N;++i){
		a1[i]=rand()%101;
		}
		stupidSort(a1,N);
		///
		   }

		else if(N2==2){ //худший случай
		///
		for(int i=0;i<N;++i){
		a1[i]=rand()%101;
		}
		Sort(a1,N);
		reverse(a1,N);
		radix(a1,b1,c,100,N);
		///
		/*Sort(a1,N);
		reverse(a1,N);               //ХУДШИЙ СЛУЧАЙ ЗАВИСИТ ОТ ВЫБОРА ПРОМЕЖУТКОВ
		ShellSort(a1,N);*/
		///
		reverse(a1,N);
		sort_bin_insert(a1,N);
		///
		reverse(a1,N);
		stupidSort(a1,N);
		///
		   }

		else if(N2==3){ //лучший случай
		///
		for(int i=0;i<N;++i){
		a1[i]=rand()%101;
		}
		Sort(a1,N);
		radix(a1,b1,c,100,N);
		///
		
		ShellSort(a1,N);
		///
		
		sort_bin_insert(a1,N);
		///
		
		stupidSort(a1,N);
		///
		   }

		delete []a1;
		delete []b1;
		break;
		   }
	}
	
	cout << "\n\nПовторить?\n1. Да\n2. Нет\n";
	cin >> a;
	system("cls");
	if(a==1)
		goto label1;
	system("pause");
return 0;
}