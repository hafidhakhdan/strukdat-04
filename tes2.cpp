#include <iostream>

using namespace std;

struct Elementlist{
	char info;
	Elementlist* next;
};

typedef Elementlist* pointer;
typedef pointer list;

void createList (list& first){
	first=NULL;
}

void createElement (pointer& pBaru){
	pBaru = new Elementlist;
	cout<<"Masukan info : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void insertFirst (list& first, pointer pBaru){
	if (first == NULL){
		first = pBaru;
	} else {
		pBaru ->next=first;
		first = pBaru;
	}
}

void insertLast (list& first, pointer pBaru){
	pointer last;
	if (first == pBaru){
		first = pBaru;
	} else {
		last = first;
		while (last->next != NULL){
			last=last->next;
		}
		last->next = pBaru;
	}
}

void traversal (list first){
	pointer pBantu;
	if (first == NULL){
		cout<<"List kosong"<<endl;
	} else {
		pBantu = first;
		while (pBantu != NULL){
			cout<<pBantu->info<<endl;
			pBantu=pBantu->next;
		}
	}
}

void deleteFrist (list& first, pointer& pHapus){
	if ( first == NULL){
		pHapus = NULL;
		cout<<"List kosong"<<endl;
	} else if ( first->next == NULL){
		pHapus=first;
		first=NULL;
	} else{
		pHapus=first;
		first=first->next;
		pHapus->next=NULL;
	}
	
	cout<<"Info yang dihapus : "<<pHapus->info<<endl;
}

void deleteLast (list& first, pointer& pHapus){
	pointer last, precLast;
	if ( first == NULL){
		pHapus = NULL;
		cout<<"LIST KOSONG"<<endl;
	} else if ( first->next==NULL){
		pHapus=first;
		first=NULL;
	} else {
		last=first;
		precLast=NULL;
		while (last->next!=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
	cout<<"info yang dihapus: "<<pHapus->info<<endl;
}
