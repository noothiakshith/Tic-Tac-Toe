#include<iostream>
using namespace std;
int space[3][3]={{00,01,02},{03,04,05},{06,07,8}};
int row;
int col;
bool tie=false;
char token='X';
 string n1="";
string n2="";
void functionone(){
    // creating the board
    cout<<"  |      |\n";
    cout<<space[0][0]<<" | "<< " "<<space[0][1]<<" "<<" "<<" | "<<space[0][2]<<"\n";
    cout<<"__|______|_\n";
    cout<<"  |      |\n";
    cout<<space[1][0]<<" | "<<space[1][1]<<" "<<" | "<<space[1][2]<<"\n";
    cout<<"__|______|_\n";
    cout<<"  |      |\n";
    cout<<space[2][0]<<" | "<<space[2][1]<<" "<<" | "<<space[2][2]<<"\n";
    cout<<"  |      |\n";  

}
void functiontwo(){
    int digit;
    if(token=='X'){
        cout<<n1<<"please enter";
        cin>>digit;
    }
    if(token=='O'){
        cout<<n2<<"please enter";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        col=0;
    }
    if(digit==2){
        row=0;
        col=1;
    }
    if(digit==3){
        row=0;
        col=2;
    }
    if(digit==4){
        row=1;
        col=1;
    }
    if(digit==5){
        row=1;
        col=2;
    }
    if(digit==6){
        row=1;
        col=3;
    }
    if(digit==7){
        row=2;
        col=1;
    }
    if(digit==8){
        row=2;
        col=2;
    }
    if(digit==9){
        row=2;
        col=3;
    }
    else if(digit<1||digit>9){
        cout<<"Invalid input";
    }
    if(token=='X' and space[row][col]!= 'X' and space[row][col]!='O'){
        space[row][col]='X';
        token='O';
    }
    else if(token =='O' and space[row][col]!='O' &&space[row][col]!='X'){
        space[row][col]='O';
        token='X';
    }
    else{
        cout<<"There is no empty spaces\n ";
        functiontwo();
    }
    functionone();
}
bool functionthree(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] and space[i][0]==space[i][2] || space[0][i]==space[1][i] and space[0][i]==space[1][i] and space[0][i]==space[2][i]){
            return true;
        }
         if(space[0][0]==space[1][1] and space[1][1]==space[2][2] || space[0][2]==space[1][1] and space[1][1]==space[2][0]){
            return true;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='X' and space[i][j]!='O'){
                return false;
            }
        }
    }
    tie=true;
    return false;
}
int main(){
    cout<<"Enter the name of the first player "<<endl;
    getline(cin,n1);
    cout<<"Enter the name of the second player"<<endl;
    getline(cin,n2);
    cout<<n1<<" " <<"is the first player"<<endl;
    cout<<n2<<" "<<"is the second player"<<endl;
    cout<<"\n";
    while(!functionthree()){
        functionone();
        functiontwo();
        functionthree();
    }
    if(token='X'&& tie ==false){
        cout<<n1<<"wins"<<endl;
    }
    else if(token='O' and tie==false){
        cout<<n1<<"Wins"<<endl;
    }
    else{
        cout<<"Tie";
    }
}