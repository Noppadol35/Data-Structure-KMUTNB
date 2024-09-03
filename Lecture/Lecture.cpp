#include <iostream>
using namespace std;


bool checkBracket(){
    string input;
    cout << "Enter input: ";
    getline(cin, input);
    int count = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            count++;
        }
        else if(input[i] == ')'){
            count--;
        }
    }
    if(count == 0){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    if(checkBracket()){
        cout << "Pass";
    }
    else{
        cout << "Error";
    }
    
    return 0;
}