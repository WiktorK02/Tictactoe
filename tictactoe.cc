#include <iostream>

using namespace std;

void mapgenerator();
void switch_turn(int turn);;
void getvalue(int* x, int* y);
void updatemap(int x, int y, char map[3][4], int turn, int* qloop);
void genupdatemap(char map[3][4]);
void run(int getx, int gety, int turn, char map[3][4]);
void res(int getx, int gety, int turn, char map[3][4]);
void checkifwin(int getx, int gety, int turn, char map[3][4]);
void resmap(char map[3][4]);
void drawcheck(int getx, int gety, int turn, char map[3][4]);
void winx(int getx, int gety, int turn, char map[3][4]);
void wino(int getx, int gety, int turn, char map[3][4]);

int main(){
	int getx = 0, gety = 0, turn = 1; 
	
	char map [3][4] = {"___", "___","___"};
	
	system("clear");
	mapgenerator();
	cout<<"tura krzyzyka:"<<endl;
	run(getx,gety,turn,map);
	
	return 0;
}
void mapgenerator(){
	char map [3][4] = {"___", "___","___"};

	
	for (int i = 0; i<sizeof(map)/sizeof(map[0]); i++){
		int counter = 0;
		for(int j = 0; j<sizeof(map)/sizeof(map[0]); j++){
			cout<<map[i][j];
			counter++;
			if (counter == 3){
				cout<<endl;
				counter=0; 
			}
		}
	} 

	cout<<endl;
}

void switch_turn(int turn){
        if(turn % 2 == 1){
                cout<<"tura krzyzyka:"<<endl;
        }
        else {
                cout<<"tura kolka: "<<endl;
        }
}

void getvalue(int* x, int* y){
        cin>>*y>>*x;
        --*x;
        --*y;
        cout<<endl;
}

void updatemap(int x, int y, char map[3][4], int turn, int* qloop){
	for (int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if(i == x && j == y && turn % 2 == 0){
                    		if(map[i][j] != 88 && map[i][j] != 79){ 
					map[i][j] = 88;//X in ascii
				}
				else{
					cout<<"zle wybrane wsporzedne, sproboj ponownie"<<endl;
					*qloop = 1;
				}
			}
			
			else if(i == x && j == y && turn % 2 == 1){
                                if(map[i][j] != 88 && map[i][j] != 79){ 
					map[i][j] = 79;//O in ascii
                        	}
				else{
                                        cout<<"zle wybrane wsporzedne, sproboj ponownie"<<endl;
					*qloop = 1;
                                }

			}
		}
	}
}

void genupdatemap(char map[3][4]){

        for (int i = 0; i<3; i++){
                int counter = 0;
                for(int j = 0; j<3; j++){
            
			
			cout<<map[i][j];
			
			counter++;
                        
			if (counter == 3){
                                cout<<endl;
                                counter=0;
                        }
                }
        }
	
        cout<<endl;
}
void run(int getx, int gety, int turn, char map[3][4]){
	turn = 1;
	system("clear");
	resmap(map);
	genupdatemap(map);

	cout<<"tura krzyzyka"<<endl;	
	while(1){
                int qloop = 0;
                start:

                getvalue(&getx,&gety);

                if(!(getx>=-1 && getx<=2 && gety>=-1 && gety<=2)){//-1 bo wczesniej dodalem
                        cout<<"zle wybrane wsporzedne, sproboj ponownie"<<endl;
                        goto start;
                }
                system("clear");
                turn++;
                updatemap(getx,gety,map,turn,&qloop);

                if(qloop == 1){
                        turn--;
                }
                genupdatemap(map);
                switch_turn(turn);//switch turn
                checkifwin(getx,gety,turn,map);
		drawcheck(getx,gety,turn,map);
        }
}

void res(int getx, int gety, int turn, char map[3][4]){
        system("clear");
        run(getx,gety,turn,map);
}

void checkifwin(int getx, int gety, int turn, char map[3][4]){
	if(map[1][0] == 88){////skrajne srodki dla krzyzyka
		if(map[0][0] == 88 && map[2][0] == 88){
			winx(getx,gety,turn,map);
		}
	}
	if(map[0][1] == 88){////skrajne srodki dla krzyzyka
		if(map[0][0] == 88 && map[0][2] == 88){
			winx(getx,gety,turn,map);
		}
	}
	if(map[2][1] == 88){////skrajne srodki dla krzyzyka
		if(map[2][0] == 88 && map[2][2] == 88){
			winx(getx,gety,turn,map);
		}
	}
	if(map[1][2] == 88){////skrajne srodki dla krzyzyka
		if(map[0][2] == 88 && map[2][2] == 88){
			winx(getx,gety,turn,map);
		}
	}
	if(map[1][0] == 79){////skrajne srodki dla kolka
		if(map[0][0] == 79 && map[2][0] == 79){
			wino(getx,gety,turn,map);
		}
	}
	if(map[0][1] == 79){////skrajne srodki dla kolka
		if(map[0][0] == 79 && map[0][2] == 79){
			wino(getx,gety,turn,map);
		}
	}
	if(map[2][1] == 79){////skrajne srodki dla kolka
		if(map[2][0] == 79 && map[2][2] == 79){
			wino(getx,gety,turn,map);
		}
	}
	if(map[1][2] == 79){////skrajne srodki dla kolka
		if(map[0][2] == 79 && map[2][2] == 79){
			wino(getx,gety,turn,map);
		}
	}
	
	
	
	if(map[1][1] == 88){//srodek dla krzzyka
                if((map[1][0] == 88 && map[1][2] == 88) || (map[0][1] == 88 && map[2][1] == 88) || (map[0][0] == 88 && map[2][2] == 88) || (map[2][0] == 88 && map[0][2] == 88)){
			winx(getx,gety,turn,map);
                }
	}
	if(map[1][1] == 79){//srodek dla kolka
                if((map[1][0] == 79 && map[1][2] == 79) || (map[0][1] == 79 && map[2][1] == 79) || (map[0][0] == 79 && map[2][2] == 79) || (map[2][0] == 79 && map[0][2] == 79)){
                        wino(getx,gety,turn,map);
		}

        }


}

void resmap(char map[3][4]){
        for (int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
			if(map[i][j] == 79 || map[i][j] == 88){
				map[i][j] = 95;
			}
		}
	}
}

void drawcheck(int getx, int gety, int turn, char map[3][4]){
	int drawcounter = 1;
	int intres = 0;
        for (int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
			if(map[i][j] == 79 || map[i][j] == 88){
			drawcounter++;
			}
		}
	}
	if(drawcounter == 9){
        	cout<<"remis"<<endl;
		cout<<"nacisnij 1 aby zesetowac"<<endl;
		cin>>intres;
		if(intres == 1){
		res(getx,gety,turn,map);
		}
	
	}
}

void winx(int getx, int gety, int turn, char map[3][4]){
	int intres = 0;
	cout<<"krzyzyk wygral"<<endl;
        cout<<"nacisnij 1 aby zesetowac"<<endl;
        cin>>intres;
       	if(intres == 1){
        	res(getx,gety,turn,map);
        }
}

void wino(int getx, int gety, int turn, char map[3][4]){
	int intres = 0;
	cout<<"kolko wygralo"<<endl;
        cout<<"nacisnij 1 aby zesetowac"<<endl;
        cin>>intres;
       	if(intres == 1){
        	res(getx,gety,turn,map);
        }
}

