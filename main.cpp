#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
    system("cls");
    
    char input[16];
    cout<<"Enter equation: ";
    cin>>input;
    cout<<"You entered: "<<input<<endl;
    
    int length = strlen(input), tokenNo = 2, index = 0;
    char tokens[16][16]={"0","+"}, solution[16] = {}, allowedOperators[] = {'+','-','*','/'};
    bool symbol = false;
    for(int x = 0; x < length; x++){
        int ascValue = (int)input[x];
        if((ascValue >= 48 && ascValue <= 57) || input[x] == '.'){ //asc value of 0 is 48 and 9 is 57
            if(symbol){
                int minusCount = 0;
                index = 0;
                symbol = false;
                for(int z = strlen(tokens[tokenNo]) - 1; z > 0; z--){
                    if(tokens[tokenNo][z] == '-'){
                        tokens[tokenNo][z] = '\0';
                        minusCount++;
                    }
                }
                if(minusCount % 2 == 1){
                    strcpy(tokens[tokenNo + 1],"-");
                    index++;
                }
                if(strlen(tokens[tokenNo]) > 1 || strpbrk(allowedOperators, tokens[tokenNo]) == '\0'){
                    cout<<"Syntax Error\nInvalid token: "<<tokens[tokenNo]<<endl;
                    return 0;
                }
                tokenNo++;
            }
        }
        else if(!symbol){
            tokenNo++;
            index = 0;
            symbol = true;
        }
        tokens[tokenNo][index++] = input[x];
    }
    if(symbol){
        cout<<"Syntax Error\nYou can't end an equation with an operator"<<endl;
        return 0;
    }

    for(int y = 0; y < tokenNo + 1; y++){
        if(strcmp(tokens[y],(char*)"*") == 0 || strcmp(tokens[y],(char*)"/") == 0){
            float first = atof(tokens[y - 1]), second = atof(tokens[y + 1]), ans;
            if(strcmp(tokens[y],(char*)"*") == 0){
                ans = first * second;
            }
            else{
                ans = first / second;
            }
            sprintf(tokens[y - 1], "%f", ans);
            for(int z = y; z < tokenNo; z++){
                strcpy(tokens[z], tokens[z + 2]);
                strcpy(tokens[z + 2], (char*)"");
            }
            y--;
        }
    }
    for(int y = 0; y < tokenNo + 1; y++){
        if(strcmp(tokens[y],(char*)"+") == 0 || strcmp(tokens[y],(char*)"-") == 0){
            float first = atof(tokens[y - 1]), second = atof(tokens[y + 1]), ans;
            if(strcmp(tokens[y],(char*)"+") == 0){
                ans = first + second;
            }
            else{
                ans = first - second;
            }
            sprintf(tokens[y - 1], "%f", ans);
            for(int z = y; z < tokenNo; z++){
                strcpy(tokens[z], tokens[z + 2]);
                strcpy(tokens[z + 2], (char*)"");
            }
            y--;
        }
    }

    strcpy(solution, tokens[0]);
    for(int x = strlen(solution) - 1; x >= 0; x--){
        if(solution[x] == '0'){
            solution[x] = '\0';
        }
        else if(solution[x] == '.'){
            solution[x] = '\0';
            break;
        }
        else{
            break;
        }
    }
    cout<<"Solution: "<<solution<<endl;
}
