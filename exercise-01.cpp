/*
	Nama	:Hafidh Akhdan Najib
	NPM		: 140810180061
	Kelas 	: A
	Tanggal	: 19/03/2019
	exercise 
*/

#include<iostream>
using namespace std;

struct Elementlist{
	char nama[30];
	char bidang[10];
	int gaji;
	Elementlist* next;
};

typedef Elementlist* pointer;
typedef pointer List;

void createList(List& First){
	First=NULL;
}

void createElmt(pointer& pBaru) {

	pBaru= new Elementlist; 
	cout<<"\nNama Pegawai  : ";
	cin.ignore();
	cin.getline(pBaru->nama, 30); 
	cout<<"Bidang 	: "; cin>> pBaru->bidang;
	cout<<"Gaji	 	: "; cin>>pBaru->gaji;
	pBaru->next = NULL; 
}

void insertFirst(List& First, pointer pBaru){
	if (First==NULL){ 
	First=pBaru;
} else {
	pBaru->next=First; 
	First=pBaru; 
	}	
}

void traversal(List First){	
	pointer pBantu;
	pBantu=First;
	int i=0;
	cout<<"No\tNama\tBidang\tGaji"<<endl;
		do {
			cout<<i+1<<"\t"<<pBantu->nama<<"\t"; 
			cout<<pBantu->bidang<<"\t";
			cout<<pBantu->gaji<<"\t"<<"\n";
			pBantu = pBantu->next; 
			i++;
		} while(pBantu != NULL); 
}

void deleteFirst(List& First,pointer pHapus){
	cout<<"Delete First"<<endl;
	if (First==NULL){ 
	pHapus= NULL;
	cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){ 
	pHapus=First;
	First=NULL;
	}
	else { 
	pHapus=First; 
	First=First->next; 
	pHapus->next=NULL; 
	}
  
}

void insertLast(List& First,pointer pBaru){
	pointer last;
	cout<<"Insert Last"<<endl;
	if (First==NULL){ 
	First=pBaru;
	} else { 
	last=First;
	while (last->next!=NULL){
	last=last->next;
	}last->next=pBaru; 
	}
}

void deleteLast(List& First,pointer pHapus){
	pointer last,precLast;
	cout<<"Delete Last"<<endl;
	if (First==NULL){ 
	pHapus=NULL;
	cout<<"List kosong, tidak ada yang dihapus"<<endl;
	} else if (First->next==NULL){ 
	pHapus=First;
	First=NULL; 
	} else { 
	last=First;
	precLast=NULL;
	while (last->next!=NULL){
	precLast=last;
	last=last->next;
	}
	pHapus=last;
	precLast->next=NULL;
	}
}


int main()
{
	pointer Baru,hapus;
	int x,n;
	List list;
	createList(list);
	while(x!=4){
	system ("cls");
	cout<<"Menu "<<endl;
	cout<<"1.Insert First"<<endl;
	cout<<"2.Insert Last"<<endl;
	cout<<"3.Delete First"<<endl;
	cout<<"4.Delete Last"<<endl;
	cout<<"5.Cetak data"<<endl;
	cout<<"6.Exit"<<endl;
	cout<<"Pilih (1/2/3/4/5/6) = "; cin>>x;
	switch(x){
		
	case 1:
	cout<<"Masukan banyak pegawai:";
	cin>>n;
	for(int i=0;i<n;i++){
	createElmt(Baru); 
	insertFirst(list,Baru);
	}
	
	break;	
	
	case 2:
	cout<<"Masukan banyak pegawai:";
	cin>>n;
	for(int i=0;i<n;i++){
	createElmt(Baru); 
	insertLast(list,Baru);
	cout<<endl;
	}	
	break;
		
	case 3:
	deleteFirst(list,hapus);	
	break;	
	
	case 4:
	deleteLast(list,hapus);	
	break;
	
	case 5:
	system("cls");
	traversal(list);	
	default:
		cout<<"Exit\n";
		exit(0);
		break;
	
	}
}

}
