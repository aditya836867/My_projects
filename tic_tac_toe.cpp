#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//  A description of where the locations of the points
void tic_start(){
    cout<<"The game is starting"<<endl;
    cout<<1<<" | "<<2<<" | "<<3<<endl;
    cout<<"__  __  __"<<endl;
    cout<<4<<" | "<<5<<" | "<<6<<endl;
    cout<<"__  __  __"<<endl;
    cout<<7<<" | "<<8<<" | "<<9<<endl;
    cout<<"Type The number of the box which you want to fill."<<endl<<endl;
}

//  Checking the number is greate than 0 and less than 10;
bool range_checker(int num){
    if((num>0)&&(num<10)){
        return true;   
    }
    else{
        cout<<endl<<"Type in range from 1 to 9"<<endl<<endl;
        return false;
    }
}

//  Draw the pattern of the lines with Player's Symbol
void tic_draw(string a = " ",string b = " ",string c = " ",string d = " ",string e = " ",string f = " ",string g = " ",string h = " ",string i = " "){
    //  Defining The Shape OF The Tic Tac Toe
    cout<<endl;
    cout<<a<<" | "<<b<<" | "<<c<<endl;
    cout<<"__  __  __"<<endl;
    cout<<d<<" | "<<e<<" | "<<f<<endl;
    cout<<"__  __  __"<<endl;
    cout<<g<<" | "<<h<<" | "<<i<<endl;
    cout<<endl;
}

//  Check if the number is already present in the vector
bool is_present(vector<int> vec,int a){
    if ((find(vec.begin(),vec.end(),a) != vec.end())){
        return true;
    }
    else{
        return false;
    }
}

//  Make a orgainsed statement for number is already present or not
int double_check (int pos){
    static vector<int> position_box;
    if (is_present(position_box,pos)){
        cout<<endl<<">>This box is already filled, Please choose another box<<"<<endl<<endl;
        return 1;
    }
    else{
        position_box.push_back(pos);
        return 0;
    }
}

//  Fill the box with the player's symbol
void fill_box(int num,string player){
    //  Creating Static Strings So That The Last Value is Kept;
    static string a = " ",b = " ",c = " ",d = " ",e = " ",f = " ",g = " ",h = " ",i = " ";
    if (num == 1){
        a=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 2){
        b=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 3){
        c=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 4){
        d=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 5){
        e=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 6){
        f=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 7){
        g=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 8){
        h=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
    else if (num == 9){
        i=player;
        tic_draw(a,b,c,d,e,f,g,h,i);
    }
}

//  Check if the player1 has won or not
void check_won1(int pos){
    static vector<int> position;
    position.push_back(pos);
    vector<int> win_pos[8];
    
    win_pos[0] = {1,2,3};
    win_pos[1] = {4,5,6};
    win_pos[2] = {7,8,9};
    win_pos[3] = {1,4,7};
    win_pos[4] = {2,5,8};
    win_pos[5] = {3,6,9};
    win_pos[6]= {1,5,9};
    win_pos[7] = {3,5,7};
    for (int j=0;j<8;j++){
        int count=0;
        for (int i = 0;i<position.size();i++){
            if(find(win_pos[j].begin(),win_pos[j].end(),position[i]) != win_pos[j].end()){
                count++;
                if (count == 3){
                    cout<<endl<<"Player 1 Won"<<endl;
                    exit(0);
                }
                
            }
        } 
    }
}

//  Check if the player2 has won or not
void check_won2(int pos){
    static vector<int> position2;
    position2.push_back(pos);
    vector<int> win_pos[8];

    win_pos[0] = {1,2,3};
    win_pos[1] = {4,5,6};
    win_pos[2] = {7,8,9};
    win_pos[3] = {1,4,7};
    win_pos[4] = {2,5,8};
    win_pos[5] = {3,6,9};
    win_pos[6]= {1,5,9};
    win_pos[7] = {3,5,7};
    for (int j=0;j<8;j++){
        int count=0;
        for (int i = 0;i<position2.size();i++){
            if(find(win_pos[j].begin(),win_pos[j].end(),position2[i]) != win_pos[j].end()){
                count++;
                if (count == 3){
                    cout<<endl<<"Player 2 Won"<<endl;
                    exit(0);
                }

            }
        } 
    }
}

void main_function(){
    string player1="O", player2="X";
    //  Number is set to 1 and it will keep changing to odd even so that every player get chance to do it
    static int number = 1;
    //  If inputed Value is same as before 
    for(int i=0;i<9;i++){
        int repeated =0;
        if ((number==1) || (number==3) || (number==5) || (number==7) || (number==9) ){
            cout<<"Player 1:"<<endl;
            cout<<"Number:";
            int position;
            cin>>position;
            repeated = double_check(position);
            if ((repeated == 0) && range_checker(position)){
                fill_box(position,player1);
                number++;
                check_won1(position);
            }
            else{
                i--;
            }
        }
        else if ((number == 2) || (number == 4) || (number == 6) || (number == 8)){
            cout<<"Player 2:"<<endl;
            cout<<"Number:";
            int position;
            cin>>position;
            repeated = double_check(position);
            if ((repeated == 0) && range_checker(position)){
                fill_box(position,player2);
                number++;
                check_won2(position);
            }
            else{
                i--;
            }
            cout<<endl;
        }
    }
}

int main(){
    tic_start();
    main_function();
}
