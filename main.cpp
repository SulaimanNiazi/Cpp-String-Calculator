#include<iostream>
#include<string>
using namespace std;
int main()
{
    system("cls");
    
    char input[16];
    cout<<"Enter equation: ";
    cin>>input;
    cout<<"You entered: "<<input<<endl;
    
    int tokenNo = 0, length = strlen(input);
    string tokens[16];
    bool symbol = false;
    for(int x = 0; x < length; x++){
        int ascValue = (int)input[x];
        if((ascValue >= 48 && ascValue <= 57) || ascValue == 46){ //asc value of 0 is 48 and 9 is 57
            if(symbol){
                tokenNo++;
                symbol = false;
            }
        }
        else{
            if(!symbol){
                tokenNo++;
                symbol = true;
            }
        }
        tokens[tokenNo] += input[x];
    }

    cout<<"Tokens: "<<endl;
    for(int x = 0; x < tokenNo + 1; cout<<tokens[x++]<<endl);
}