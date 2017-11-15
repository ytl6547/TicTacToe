#include "TicTacToe.h"
using namespace std;
class TicTacToe;

TicTacToe::TicTacToe(){
    for(int i=0; i<9; i++){
        board[i]=0;
    }
    rep[0]=1;
    rep[1]=-1;
    AICalculate();
}

int TicTacToe::isWin(){
    for(int i=0; i<=6; i+=3){
        int sum=0;
        for(int j=0; j<3; j++){
            sum+=board[i+j];
        }
        if(sum==3){
            return 1;
        }
        else if(sum==-3){
            return -1;
        }
    }
    for(int i=0; i<3; i++){
        int sum=0;
        for(int j=0; j<=6; j+=3){
            sum+=board[i+j];
        }
        if(sum==3){
            return 1;
        }
        else if(sum==-3){
            return -1;
        }
    }
    int sum=board[0]+board[4]+board[8];
    if(sum==3){
        return 1;
    }
    else if(sum==-3){
        return -1;
    }
    sum=board[2]+board[4]+board[6];
    if(sum==3){
        return 1;
    }
    else if(sum==-3){
        return -1;
    }
    return 0;
}

void TicTacToe::playerMove(){
    cout<<"Your turn, type in a number of spot: ";
    int spot;
    cin>>spot;
    board[spot]=rep[1-seq];
}

string TicTacToe::toString(){
    string boardString;
    for(int i=0; i<9; i++){
        if(board[i]==0){
            boardString+="_";
        }
        else if(board[i]==1){
            boardString+="O";
        }
        else if(board[i]==-1){
            boardString+="X";
        }
        else{
            boardString+=" ";
        }
    }
    return boardString;
}

void TicTacToe::AIMove(){
    //cout<<seq<<" "<<rep[seq]<<endl;
    //cout<<toString()<<" "<<nextStep[toString()]<<endl;
    board[nextStep[toString()]]=rep[seq];

}

void TicTacToe::AICalculate(){
    cout<<calculateHelper(0)<<endl;
    // map<string, int>::iterator it;
    // for(it=nextStep.begin(); it!=nextStep.end(); ++it){
        
    //     cout<<it->first<<" "<<it->second<<endl;
        
    // }
}

int TicTacToe::calculateHelper(int curr){
    if(curr==9){
        return isWin();
    }
    int next;
    int flag;
    int result;
    int checkWin;
    if(curr%2==0){
        flag=-100;
        for(int i=0; i<9; i++){
            if(board[i]==0){
                board[i]=1;
                checkWin=isWin();
                if(checkWin==1){
                    flag=1;
                    next=i;
                    board[i]=0;
                    break;
                }
                else if(checkWin==-1){
                    result=-1;
                }
                else{
                    result=calculateHelper(curr+1);
                }
                if(result>flag){
                    flag=result;
                    next=i;
                }
                board[i]=0;
            }
        }
        // if(next<0||next>8){
        //     cout<<"O:"<<endl;
        //     cout<<toString()<<next<<endl;
        //     cout<<flag<<endl;
        // }
        //cout<<toString()<<" "<<next<<endl;
        nextStep[toString()]=next;
        if(flag<-1||flag>1){
            cout<<toString()<<" "<<next<<endl;
            cout<<flag<<endl;
        }
        return flag;
    }
    else{
        flag=100;
        for(int i=0; i<9; i++){
            if(board[i]==0){
                board[i]=-1;
                checkWin=isWin();
                if(checkWin==-1){
                    flag=-1;
                    next=i;
                    board[i]=0;
                    break;
                }
                else if(checkWin==1){
                    result=1;
                }
                else{
                    result=calculateHelper(curr+1);
                }
                if(result<flag){
                    flag=result;
                    next=i;
                }
                board[i]=0;
            }
        }
        // if(next<0||next>8){
        //     cout<<"X:"<<endl;
        //     cout<<toString()<<next<<endl;
        //     cout<<flag<<endl;
        // }
        //cout<<toString()<<" "<<next<<endl;
        nextStep[toString()]=next;
        if(flag<-1||flag>1){
            cout<<toString()<<" "<<next<<endl;
            cout<<flag<<endl;
        }
        return flag;
    }
}

void TicTacToe::printBoard(){
    for(int i=0; i<=6; i+=3){
        for(int j=0; j<3; j++){
            if(board[i+j]==1){
                cout<<"o ";
            }
            else if(board[i+j]==-1){
                cout<<"x ";
            }
            else{
                cout<<i+j<<" ";
            }
        }
        cout<<endl<<endl;
    }
}

void TicTacToe::clearBoard(){
    for(int i=0; i<9; i++){
        board[i]=0;
    }
}
void TicTacToe::startGame(){
    int curr;
    char start = 'y';
    while(start == 'y'){
        curr=0;
        cout<<"Do you wanna be the first(1) or the second(0)? ";
        cin>>seq;
        while(isWin()==0&&curr<9){
            //printBoard();
            if(curr%2==seq){
                AIMove();
            }
            else{
                printBoard();
                playerMove();
            }
            curr++;
        }
        cout<<endl;
        int checkWin = isWin();
        if(checkWin == rep[1-seq]){
            cout<<"You win. Cong!"<<endl;
        }
        else if(checkWin == rep[seq]){
            cout<<"AI wins."<<endl;
        }
        else{
            cout<<"Tie"<<endl;
        }
        printBoard();
        cout<<"Another game(y/n)? ";
        cin>>start;
        clearBoard();
    }

}