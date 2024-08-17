/*Code for determining if the password pass these parameters or not:
 -Must be higher than 12 characters
 -Must not contain spaces
 -Must not cointain only upper letters
 -Must not contain only lower letters
 -Must have a digit
*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define Passlenght 20

int check=0;

//-----------------------------CHECK PARAMETERS--------------------------------------------------------
bool check_parameters(char aux[]){
//check lenght    
    if(strlen(aux) < 12){
      printf("Short password.\n");
    }else {
        check++;
    }

    if(strchr(aux,' ') != NULL){
      printf("Cant use space.\n");
    
    }else{
        check++;
    }
//check uppercase 
 bool up=false;

    for(int i=0;i<strlen(aux);i++){
        if(isupper(aux[i])){
            check++;
            up=true;
            break;
        }else{
          up=false;
        }
    }
  if(up==false){printf("Must have at least one uppercase letter\n");}   
//check lowercase
 bool low=false;
    for(int i=0;i<strlen(aux);i++){
        if(islower(aux[i])){
            check++;
            low=true;
            break;
        }
    }
  if(low==false){printf("Must have at least one lowercase letter\n");}
//check digit
 bool dig=false;
    for(int i = 0; i < strlen(aux); i++){
        if(isdigit(aux[i])){
             check++;
             dig=true;
             break;
        }
    }
  if(dig==false){printf("Must have a number digit (0-9)\n");}

if(check==5){
    return true;
}else{
    return false;}
}

//---------------------------Main Function--------------------------------------------
int main(){

char password[Passlenght];  

//User password input    
printf("\nInsert password: ");
fgets(password,Passlenght,stdin); 

//Replace last wrong digit by a NULL character
int i = strlen(password); 
if(password[i-1]=='\n'){ 
     password[i-1] = '\0'; 
  }

//Checks ALL errors
bool checks_ok = check_parameters(password);
 
if(checks_ok){
    printf("Done, remember your password btw: %s\n",password);
  }else{
    printf("\nTente novamente\n\n");
  }

return 0;    
}

// Just gotta finish the special characters check yet idk (%$@#!*()&/:;\|?)