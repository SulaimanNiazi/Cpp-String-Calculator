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
    
    int length = strlen(input), tokenNo = 0, index = 0, firstOperations = 0, secondOperations = 0;
    char tokens[16][16]={};
    bool symbol = false;
    for(int x = 0; x < length; x++){
        int ascValue = (int)input[x];
        if((ascValue >= 48 && ascValue <= 57) || input[x] == '.'){ //asc value of 0 is 48 and 9 is 57
            if(symbol){
                if(strcmp(tokens[tokenNo],(char*)"*") == 0 || strcmp(tokens[tokenNo],(char*)"/") == 0){
                    firstOperations++;
                }
                else if(strcmp(tokens[tokenNo],(char*)"+") == 0 || strcmp(tokens[tokenNo],(char*)"-") == 0 || strcmp(tokens[tokenNo],(char*)"+-") == 0 || strcmp(tokens[tokenNo],(char*)"--") == 0){
                    secondOperations++;
                }
                else{
                    cout<<"Syntax Error\nInvalid token: "<<tokens[tokenNo]<<endl;
                    return 0;
                }
                tokenNo++;
                index = 0;
                symbol = false;
            }
        }
        else if(!symbol){
            tokenNo++;
            index = 0;
            symbol = true;
        }
        tokens[tokenNo][index++] = input[x];
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
        }
    }

    cout<<"Tokens: "<<endl;
    for(int x = 0; x < tokenNo; x++){
        cout<<tokens[x]<<endl;
    };
}
