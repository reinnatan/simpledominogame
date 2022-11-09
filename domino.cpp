#include<iostream>
#include <cstdlib>
#include<algorithm>
#include <ctime>
#include<list>

using namespace std;

struct card{
	int first;
	int second;
};

card listCard[28];
card splitCardComputer[14];
card splitCardUser[14];
int arrIndex[14];
card currentCardSelected;

//flag the picked card
card computerCardPicked[14];
card userCardPicked[14];

//init card
void initCard(){
	int index;
	int counter;

	//init card 0 and the grouping (0-6)
	index = 0;
	counter = 0;
	for(int i=0; i<7; i++){
		listCard[i].first = index;
		listCard[i].second = (index+counter);
		counter++;
	}


	//init card 1 and the grouping (7-13)
	index =1;
	counter = 0;
	for(int i=7; i<13; i++){
		listCard[i].first = index;
		listCard[i].second = (index+counter);
		counter++;
	}

	//init card 2 and the grouping (13-17)
	index = 2;
	counter = 0;
	for(int i=13; i<18; i++){
		listCard[i].first = index;
		listCard[i].second = (index+counter);
		counter++;
	}

	//init card 3 and the grouping (18-21)
	index+=1;
	counter = 0;
	for (int i=18; i<22; i++){
		listCard[i].first = index;
		listCard[i].second = (index+counter);
		counter+=1;
	}

	//init card 4 and the grouping (22-24)
	index+=1;
	counter = 0;
	for(int i=22; i<25; i++){
		listCard[i].first = index;
		listCard[i].second = (index+counter);
		counter+=1;
	}

	//init card 5 and the grouping (25-26)
	listCard[25].first = 5;
	listCard[25].second =5;
	listCard[26].first = 5;
	listCard[26].second = 6;

	//init card 6 and the grouping (27)
	listCard[27].first = 6;
	listCard[27].second = 6;

}

//function to random card for computer
void randomCardComputer(){
	srand((unsigned) time(0));
	int counter = 0;

	do{
		int rnd = rand() % 28;
		bool exists = find(begin(arrIndex), end(arrIndex), rnd) != end(arrIndex);
		if(!exists){
			arrIndex[counter] = rnd;
			splitCardComputer[counter] = listCard[rnd];
			counter++;
		}
		//cout<<rnd<<"-"<<listCard[rnd].first<<"-"<<listCard[rnd].second<<endl;
	}while(counter<14);
}

//function to ranadom card for user
void randomCardUser(){
	int indexUser = 0;
	for(int k=0; k<28; k++){
		bool exists = find(begin(arrIndex), end(arrIndex), k) != end(arrIndex);

		if(!exists){
			splitCardUser[indexUser] = listCard[k];
			indexUser++;
		}

	}
}

void printCard(int index){
	for(int i=0; i<index; i++){
		cout<<splitCardComputer[i].first<<"-"<<splitCardComputer[i].second<<endl;
	}

	cout <<"\n\n";

	for(int i=0; i<index; i++){
		cout<<splitCardUser[i].first<<"-"<<splitCardUser[i].second<<endl;
		//cout<<listCard[i].first<<"-"<<listCard[i].second<<endl;
		//cout<<splitCardComputer[i].first<<"-"<<splitCardComputer[i].second<<endl;
	}
}

void playDomino(){
	srand((unsigned) time(0));

	for(int nextPlay = 1; nextPlay<=28; nextPlay++){
		//change player
		if(nextPlay%2!=0){
			for(int u=0; u<14; u++){

				if(currentCardSelected.first == NULL && currentCardSelected.second == NULL){
					currentCardSelected = splitCardComputer[u];
					computerCardPicked[u] = splitCardComputer[u];
				}else if(currentCardSelected.first == splitCardComputer[u].first){
					currentCardSelected.first = splitCardComputer[u].second;
					computerCardPicked[u] = splitCardComputer[u];
				}else if(currentCardSelected.second == splitCardComputer[u].first){
					currentCardSelected.second = splitCardComputer[u].second;
					computerCardPicked[u] = splitCardComputer[u];
				}else if(currentCardSelected.first == splitCardComputer[u].second){
					currentCardSelected.first = splitCardComputer[u].first;
					computerCardPicked[u] = splitCardComputer[u];
				}else if(currentCardSelected.second == splitCardComputer[u].second){
					currentCardSelected.first = splitCardComputer[u].first;
					computerCardPicked[u] = splitCardComputer[u];
				}

			}

		}else{
			for(int u=0; u<14; u++){

				if(currentCardSelected.first == NULL && currentCardSelected.second == NULL){
					currentCardSelected = splitCardUser[u];
				}else if(currentCardSelected.first == splitCardUser[u].first){
							currentCardSelected.first = splitCardUser[u].second;
				}else if(currentCardSelected.second == splitCardUser[u].first){
						currentCardSelected.second = splitCardUser[u].second;
				}else if(currentCardSelected.first == splitCardUser[u].second){
						currentCardSelected.first = splitCardUser[u].first;
				}else if(currentCardSelected.second == splitCardUser[u].second){
					currentCardSelected.first = splitCardUser[u].first;
				}





			}
		}
	}
}

int main(){
	initCard();
	randomCardComputer();
	randomCardUser();
	printCard(14);
}
