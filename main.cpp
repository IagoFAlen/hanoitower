#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

#include "hanoi.hpp";

int main(){
    Pilha p1, p2, p3;
    inf_no info;
    inic(&p1);
    inic(&p2);
    inic(&p3);
    int menu = -1;
    bool first = true;
    int jogadas = 0;
    int ganhou = 0;
    int j = 0;

    while(menu !=  0){
            clear_screen();
            cout << "0  - EXIT" << endl;
            cout << "1  - START" << endl;
            cout << "2  - MOVE FROM STACK 1 TO STACK 2" << endl;
            cout << "3  - MOVE FROM STACK 1 TO STACK 3" << endl;
            cout << "4  - MOVE FROM STACK 2 TO STACK 3" << endl;
            cout << "5  - MOVE FROM STACK 2 TO STACK 1" << endl;
            cout << "6  - MOVE FROM STACK 3 TO STACK 1" << endl;
            cout << "7  - MOVE FROM STACK 3 TO STACK 2" << endl;
            cout << "8  - SHOW STACKS" << endl;
            cout << "9  - RESET" << endl;
            cin >> menu;
            fflush(stdin);
            clear_screen();

        switch(menu){
            case 0:
                {
                    cout << "Program finished!" << endl;
                    getchar();
                    break;
                }
            case 1:
            {
                if(first){
                    jogadas = 0;
                    while(j <= 0 || j > 5){
                        cout << "Submit the blocks quantity (1, 2, 3, 4, 5): ";
                        cin >> j;
                    }

                    for(int i = j; i >= 1; i--){
                        if(i == 5)
                            info.traco = "----- | -----";
                        else if(i == 4)
                            info.traco = " ---- | ---- ";
                        else if(i == 3)
                            info.traco = "  --- | ---  ";
                        else if(i == 2)
                            info.traco = "   -- | --   ";
                        else if(i == 1)
                            info.traco = "    - | -    ";

                        info.valortraco = i;
                        pushdehanoistart(&p1, info);

                    }

                    cout << "First stack is complete" << endl;
                    cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                    first = false;
                    getchar();
                    getchar();
                } else{
                    cout << "The game is already defined!" << endl;
                    getchar();
                    getchar();
                }

                break;
            }

            case 2:
            {

                if(transferdehanoi(&p1, &p2, &info)){
                    cout << "\nTransfered! " << endl;
                    jogadas++;
                    cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                    
                }
                else
                    cout << "\nInvalid!" << endl;

                cout << "STACK 1, 2 e 3:" << endl;
                showdehanoi(&p1);
                showdehanoi(&p2);
                showdehanoi(&p3);
                getchar();
                getchar();
                break;
            }

            case 3:
            {
                if(transferdehanoi(&p1, &p3, &info)){
                    cout << "\nTransfered! " << endl;
                    jogadas++;
                    ganhou = ganhouhanoi(&p3);
                    cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                    if(ganhou == j){
                        if(jogadas == (pow(2, j) - 1))
                            cout << "You won with minimum plays!!!!" << endl;

                        cout << "***************************************************" << endl;
                        cout << "*********************Congrats!*********************" << endl;
                        cout << "***************************************************" << endl;
                        showdehanoi(&p1);
                        showdehanoi(&p2);
                        showdehanoi(&p3);
                        getchar();
                        getchar();
                        cout << endl << "*********************Reseting stack!*********************" << endl;
                        resetdehanoi(&p1, &p2, &p3);
                        jogadas = 0;
                        first = true;
                        j = 0;

                    }
                }
                else
                    cout << "\nInvalid!" << endl;
                
                cout << "STACK 1, 2 e 3:" << endl;
                showdehanoi(&p1);
                showdehanoi(&p2);
                showdehanoi(&p3);
                getchar();
                getchar();
                break;
            }

            case 4:
            {
                if(transferdehanoi(&p2, &p3, &info)){
                    cout << "\nTransfered! " << endl;
                    jogadas++;
                    cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                    ganhou = ganhouhanoi(&p3);
                    if(ganhou == j){
                        if(jogadas == (pow(2, j) - 1))
                            cout << "You won with minimum plays!!!!" << endl;

                        cout << "***************************************************" << endl;
                        cout << "*********************Congrats!*********************" << endl;
                        cout << "***************************************************" << endl;
                        showdehanoi(&p1);
                        showdehanoi(&p2);
                        showdehanoi(&p3);
                        getchar();
                        getchar();
                        cout << endl << "*********************Reseting stack!*********************" << endl;
                        resetdehanoi(&p1, &p2, &p3);
                        jogadas = 0;
                        first = true;
                        j = 0;

                    }
                }
                else
                    cout << "\nInvalid!" << endl;

                cout << "STACK 1, 2 e 3:" << endl;
                showdehanoi(&p1);
                showdehanoi(&p2);
                showdehanoi(&p3);
                getchar();
                getchar();
                break;
            }

            case 5:
            {
                if(transferdehanoi(&p2, &p1, &info)){
                    cout << "\nTransfered! " << endl;
                    jogadas++;
                    cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                    
                }
                else
                    cout << "\nInvalid!" << endl;
                cout << "STACK 1, 2 e 3:" << endl;
                showdehanoi(&p1);
                showdehanoi(&p2);
                showdehanoi(&p3);
                getchar();
                getchar();
                break;
            }

            case 6:
            {
                if(transferdehanoi(&p3, &p1, &info)){
                    cout << "\nTransfered! " << endl;
                    jogadas++;
                    cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                    
                }
                else
                    cout << "\nInvalid!" << endl;
                
                cout << "STACK 1, 2 e 3:" << endl;
                showdehanoi(&p1);
                showdehanoi(&p2);
                showdehanoi(&p3);
                getchar();
                getchar();
                break;
            }

            case 7:
            {
                if(transferdehanoi(&p3, &p2, &info)){
                    cout << "\nTransfered! " << endl;
                    jogadas++;
                    cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                    
                }
                else
                    cout << "\nInvalid!" << endl;
                
                cout << "STACK 1, 2 e 3:" << endl;
                showdehanoi(&p1);
                showdehanoi(&p2);
                showdehanoi(&p3);
                getchar();
                getchar();
                break;
            }
            case 8:
            {
                showdehanoi(&p1);
                showdehanoi(&p2);
                showdehanoi(&p3);
                cout << "Minimum plays to win is " << (pow(2, j) - 1) << " and you played " << jogadas << " times" << endl;
                getchar();
                getchar();
                break;
            }
            case 9:
            {
                resetdehanoi(&p1, &p2, &p3);
                first = true;
                jogadas = 0;
                j = 0;
                getchar();
                getchar();
                break;
            }
        }
    }


}


