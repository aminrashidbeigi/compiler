#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int C_name();
void load ();
void check ();
void go_end();
void C_math();
void go_end2();
void go_end3 ();
int C_number();
void tokenize();
int C_boolean();
int name_exist();
int C_character();
void go_end_semy();
int C_expression();
int preprocessor();
void include_load();
int C_intigerAndFloat();
void load_without_enter();
void IR_Generation ();
int IR_if ();

struct tokenize {
    char str[30];
    int type;
    int attribute;
    int line;
    int use;
    struct token *next;
    struct token *back;
}*temp,*first,*first2,*help,*help1,*help2;

FILE *fpIR;
int flag=0;
int check_else=0;
int state_number;
int num=0 ;
int tp=0;
int error=0;
int enter=1;
int enter_last=0;
char include[15][20];
char name_table [20][20]; //////esm no' meghdar
int num_table [20][20]; ///////aval no' bad meghdar
int table_cont=0;

int main(){
    fclose (fopen ("IR.txt" , "w"));
    fpIR = fopen ("IR.txt" , "w");


    int i , j;
    for (i=0 ; i<15 ; i++){
        for (j=0 ; j<20 ; j++){
            include[i][j]=NULL;
        }
    }
    first=(struct tokenize *)malloc(sizeof(struct tokenize));
    temp=first;
    NULLY();
    first->next=NULL;
    first->back=NULL;

    //preprocessor();
    temp=first;
    load();
    temp=first;
    tokenize();
    temp=first;
    load_without_enter();
    //printf ("HELLO");
    //include_load();

    temp=first;
    //preprocessor();

    //first=temp;
    while (temp->str[0]!='?'){
        printf ("%d " , temp->type);
        temp=temp->next;
    }
    printf ("%s " , temp->str);
    printf ("\n");

    //include_load();
    load_without_enter();

    temp=first;

    //load_without_enter();

    printf ("\n");
    printf ("\n");
    temp=first;
    check();




    temp=first;
    if (error == 0){
        i=make_table();
        if (i==1){
            if (check_id()==1){
                //table_number();
            }
        }

    }
    temp=first;
    IR_Generation();

    fprintf(fpIR , "RETURN \n\nCALL MAIN ");
    fclose (fpIR);
    return 0;
}

void NULLY (){
    int i;
    for (i=0 ; i<30 ; i++){
        temp->str[i]=NULL;
    }
}

void load (){
    char a;
    int k=0, i=0, end, help=0;
    temp=first;
    FILE *fp;
    fp=fopen ("totaldata.txt" , "r");
    rewind(fp);
    end = 1;
    while (!feof(fp)){
        a=fgetc(fp);
        if ((a>=48 && a<=57) || (a>=65 && a<=90) || (a>=97 && a<=122) || a==43 || a==47 || a==41 || a==46 || a==40 || a==35 || a==60 || a== 61 || a==62 || a==123 || a==124 || a==125 || a==59 || a==17 || a==44 || a==39 || a==38 || a==96 || a=='"'){
            if (i==0 && k!=0){
                help1=temp;
                temp->next=malloc(sizeof(struct tokenize));
                temp=temp->next;
                NULLY();
                temp->back=help1;
                temp->next=NULL;
            }
            temp->str[i]=a;
            i++;
            end = 0;
            k=1;
        }
        else if (a == ' '){
            i=0;
            end=1;
        }
        else if (a == '\n'){
            i=0;
            end=2;
            help1=temp;
            temp->next=malloc(sizeof(struct tokenize));
            temp=temp->next;
            NULLY();
            temp->back=help1;
            temp->next=NULL;
            temp->str[0]='\n';
        }
    }
    help1=temp;
    temp->next=malloc(sizeof(struct tokenize));
    temp=temp->next;
    NULLY();
    temp->back=help1;
    temp->next=NULL;
    temp->str[0] = '?';
    fclose (fp);
}

void include_load (){
    first2=first;
    int j=0 , end;
    char a;
    int k=0;

    //////////////////
    help=malloc(sizeof(struct tokenize));
    temp=help;
    NULLY();
    temp->next=first;
    temp->back=NULL;
    first=help;

    ///////////////////
    while (include[j][0] != '?'){
        int i=0;
        FILE *fp;
        printf ("%s" , include[j]);
        fp=fopen (include[j] , "r");
        end = 1;
        while (!feof(fp)){
            //printf ("hello");
            a=fgetc(fp);
            if ((a>=48 && a<=57) || (a>=65 && a<=90) || (a>=97 && a<=122) || a==43 || a==47 || a==41 || a==46 || a==40 || a==35 || a==60 || a== 61 || a==62 || a==123 || a==124 || a==125 || a==59 || a==17 || a==44 || a==39 || a==38 || a==96 || a=='"'){
                if (i==0){
                    help=temp;
                    temp->next=malloc(sizeof(struct tokenize));
                    temp=temp->next;
                    NULLY();
                    temp->back=help;
                    temp->next=first2;
                }
                temp->str[i]=a;
                i++;
                end = 0;

            }
            else if (a == ' '){
                i=0;
                end=1;
            }
            else if (a == '\n'){
                i=0;
                end=2;
                help=temp;
                temp->next=malloc(sizeof(struct tokenize));
                temp=temp->next;
                NULLY();
                temp->back=help;
                temp->next=first2;
                temp->str[0]='\n';
            }
        }
        fclose (fp);
        k=1;
        j++;
    }
}

void load_without_enter (){
    temp=first;
    while (temp->str[0] == '\n' || temp->str[0] == NULL){
        first=temp->next;
        temp=first;
    }
    while (temp->str[0] != '?'){
        if (temp->str[0] == '\n'){
            help1=temp->next;
            help2=temp->back;
            temp=temp->back;
            temp->next=help1;
            temp=temp->next;
            temp->back=help2;
        }
        else {
            temp=temp->next;
        }
    }
}

void tokenize (){
    enter=2;
    temp=first;

    ////////////keywords////////////
    while (strcmp(temp->str , "?")!=0){
        help1=temp->back;
        help2=temp->next;
        if (strcmp(temp->str , "main")==0) {
            temp->type=1;
            temp->attribute=0;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "if")==0) {
            temp->type=1;
            temp->attribute=1;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "else")==0) {
            temp->type=1;
            temp->attribute=2;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "int")==0) {

            temp->type=1;
            temp->attribute=3;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "float")==0) {
            temp->type=1;
            temp->attribute=4;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "char")==0) {
            temp->type=1;
            temp->attribute=5;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "bool")==0) {
            temp->type=1;
            temp->attribute=6;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "void")==0) {
            temp->type=1;
            temp->attribute=7;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "NULL")==0) {
            temp->type=1;
            temp->attribute=8;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "while")==0) {
            temp->type=1;
            temp->attribute=9;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "true")==0) {
            temp->type=1;
            temp->attribute=10;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "false")==0) {
            temp->type=1;
            temp->attribute=11;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "return")==0) {
            temp->type=1;
            temp->attribute=12;
            temp->line=enter;
            enter_last=0;
        }

        ////////////operators////////////
        else if (strcmp(temp->str , "+")==0) {
            temp->type=2;
            temp->attribute=1;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "-")==0) {
            temp->type=2;
            temp->attribute=2;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "/")==0) {
            temp->type=2;
            temp->attribute=3;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "*")==0) {
            temp->type=2;
            temp->attribute=4;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , ">")==0) {
            temp->type=2;
            temp->attribute=5;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "<")==0) {
            temp->type=2;
            temp->attribute=6;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "==")==0) {
            temp->type=2;
            temp->attribute=7;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "!=")==0) {
            temp->type=2;
            temp->attribute=8;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "&&")==0) {
            temp->type=2;
            temp->attribute=9;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "||")==0) {
            temp->type=2;
            temp->attribute=10;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "=")==0) {
            temp->type=2;
            temp->attribute=11;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "<=")==0) {
            temp->type=2;
            temp->attribute=12;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , ">=")==0) {
            temp->type=2;
            temp->attribute=13;
            temp->line=enter;
            enter_last=0;
        }

        ////////////punc////////////
        else if (strcmp(temp->str , "(")==0) {
            temp->type=6;
            temp->attribute=1;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , ")")==0) {
            temp->type=6;
            temp->attribute=2;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "{")==0) {
            temp->type=6;
            temp->attribute=3;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "}")==0) {
            temp->type=6;
            temp->attribute=4;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , ",")==0) {
            temp->type=6;
            temp->attribute=5;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , ";")==0) {
            temp->type=6;
            temp->attribute=6;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "'")==0) {
            temp->type=6;
            temp->attribute=7;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "\"")==0) {
            temp->type=6;
            temp->attribute=8;
            temp->line=enter;
            enter_last=0;
        }
        else if (strcmp(temp->str , "#")==0) {
            temp->type=6;
            temp->attribute=9;
            temp->line=enter;
            enter_last=0;
        }

        /////////number///////////
        else if (C_number()==1) {
            temp->type=4;
            temp->attribute=1;
            temp->line=enter;
            enter_last=0;
        }
        else if (C_number()==0) {
            temp->type=4;
            temp->attribute=2;
            temp->line=enter;
            enter_last=0;
        }

        ////////////char//////////////
        else if ((strcmp(help1->str , "'")==0) && (strcmp(help2->str , "'")==0) && (strlen(temp->str)==1)) {
            temp->type=5;
            temp->attribute=0;
            temp->line=enter;
            enter_last=0;
        }

        ////////////n////////////
        else if (strcmp(temp->str , "\n")==0) {
            temp->type=7;
            temp->attribute=0;
            temp->line=enter;
            enter++;
            enter_last++;
        }

        ///////////id////////////
        else if (strcmp(temp->str , "?")!=0){
            temp->type=3;
            temp->attribute=0;
            temp->line=enter;
            enter_last=0;
        }
        temp=temp->next;
    }
}

int preprocessor (){
    int i , j=0;
    while (temp->type != 1 ){
        if (strcmp(temp->str , "#")==0){
            temp=temp->next;
            if (strcmp(temp->str , "include")==0){
                temp=temp->next;
                if (strcmp(temp->str , "\"")==0){
                    temp=temp->next;
                    temp=temp->next;
                    if (strcmp(temp->str , "\"")==0){
                        temp=temp->back;
                        for (i=0 ; i<20 ; i++){
                            include[j][i]=temp->str[i];
                        }
                        printf("%s" , temp->str);
                        j++;
                        temp=temp->next;
                        temp=temp->next;
                    }
                }
            }
        }
    }
    include[j][0]='?';
return j;
}

int C_character() {
    while (strcmp(temp->str , ";")!=0) {
        temp=temp->next;
        if (temp->type == 3) {
            temp=temp->next;
            if (strcmp(temp->str , "=") == 0){
                temp=temp->next;
                if (strcmp(temp->str , "'") == 0) {
                    temp = temp -> next;
                    if (temp -> type == 5) {
                        temp = temp -> next;
                        if (strcmp(temp->str , "'") == 0) {
                            temp = temp -> next;
                            if (strcmp(temp->str , ",") == 0){
                                continue;
                            }
                            else if (strcmp(temp->str , ";") == 0){
                                go_end();
                            }
                            else {
                                go_end_semy();
                                error++;
                            }
                        }
                        else{
                            printf("%d : Expected to see ' c ' , but '%s' have been seen.\n" , temp->line, temp->str);
                            go_end();
                            error ++;
                        }
                    }
                    else if (strcmp (temp->str , ";") == 0) {
                        printf("%d : Correct structure of 'c' is missed.\n" , temp->line);
                        error ++;
                    }
                    else{
                        printf("%d : Correct structure of 'c' is missed.\n" , temp->line);
                        go_end();
                        error ++;
                    }
                }
                else {
                    printf("%d : Correct structure of 'c' is missed.\n" , temp->line);
                    go_end();
                    error ++;
                }
            }
            else if (strcmp (temp->str , ",") == 0){
                continue;
            }
            else if (strcmp (temp->str , ";") == 0) {
                go_end();
            }
            else {
                printf ("%d : Expected to see ';' or '=' after identifire, but '%s' have been seen.\n" , temp->line, temp->str);
                go_end();
                error ++;
            }
        }
        else {
            error ++;
            printf ("%d : Expected to see identifire.\n" , temp->line);
            go_end();
        }
    }
}

int C_intigerAndFloat () {
    while (strcmp (temp->str , ";")!=0 && strcmp (temp->str , "?")!=0) {
        temp=temp->next;
        if (temp->type == 3) {
            temp=temp->next;
            if (strcmp (temp->str , "=") == 0){
                temp=temp->next;
                if (temp->type == 3 || temp->type == 4) {
                    temp=temp->next;
                    if (temp->type == 2 && temp->attribute<=4 && temp->attribute>=1) {
                        temp=temp->next;
                        if (temp->type == 3 || temp->type == 4) {
                            temp=temp->next;
                            if(strcmp(temp->str , ";") == 0) {
                                go_end();
                            }
                            else if (strcmp(temp->str , ",") == 0) {
                                continue;
                            }
                            else {
                                printf ("%d : Expected to see ';', but '%s' have been seen.\n" , temp->line, temp->str);
                                go_end();
                                error ++;
                            }
                        }
                        else if (strcmp (temp->str , ";") == 0) {
                            go_end();
                        }
                        else {
                            error ++;
                            go_end();
                            printf ("%d : Expected to see an operator after identifire, but '%s' have been seen.\n", temp->line, temp->str);
                        }
                    }
                    else if (strcmp(temp->str , ";")==0) {
                    }
                }
                else {
                    printf ("%d : Expected to see an operator or identifire after '=', but '%s' have been seen.\n", temp->line, temp->str);
                    error ++;
                    go_end();
                }
            }
            else if (strcmp (temp->str , ";") == 0) {
                go_end();

            }
            else if (strcmp (temp->str , ",") == 0){
                continue;
            }
            else {
                printf ("%d : Expected to see an ';' or '=' after identifire, but '%s' have been seen.\n", temp->line, temp->str);
                go_end();
                error ++;
            }
        }
        else if (temp->type == 1 && temp->attribute == 0){
            printf("%d : Expected to see an 'void' before 'main', but '%s' have been seen.\n", temp->line, temp->str);
            error++;
            go_end2();
            break;
        }
        else if (temp->str[0] == ';'){
            continue;
        }
        else {
            error ++;
            printf("%d : Expected to see an identifire, but '%s' have been seen.\n", temp->line, temp->str);
            go_end();
        }
    }
}

int C_boolean() {
    while (strcmp (temp->str , ";")!=0) {
        temp = temp->next;
        if(temp->type == 3){
            temp = temp->next;
            if(temp->type == 2 && temp->attribute==11){
                temp = temp->next;
                if(temp->type==1 && (temp->attribute==10 || temp->attribute==11)){
                    temp = temp -> next;
                    if (temp->type==6 && temp->attribute==5){
                        continue;
                    }
                    else if (temp->type==6 && temp->attribute==6){
                        go_end();
                    }
                    else {
                        go_end_semy();
                    }
                }
                else{
                    printf("%d : Expected to see 'true' or 'false', but '%s' have been seen.\n", temp->line, temp->str);
                    error ++;
                    go_end();
                }
            }
            else if (temp->type==6 && temp->attribute==5){
                continue;
            }
            else if (temp->type==6 && temp->attribute==6){
                go_end();
            }
            else{
                printf("%d : Expected to see an identifire after '=', but '%s' have been seen.\n", temp->line, temp->str);
                error ++;
                go_end();
            }
        }
        else{
            printf("%d : Expected to see an identifire after 'bool' keyword, but '%s' have been seen.\n", temp->line, temp->str);
            error ++;
            go_end();
        }
    }
}

int C_if (){
    int check=0;
    int ak=0 , ak2=0;
    temp=temp->next;
    if (strcmp (temp->str , "(") == 0){
        temp=temp->next;
        if (temp->type == 3){
            temp=temp->next;
            if (temp->type == 2 && ((temp->attribute>=5 && temp->attribute<=10) || temp->attribute==12 || temp->attribute==13)){
                temp=temp->next;
                if (temp->type==3 || temp->type==4){
                    temp=temp->next;
                    if (strcmp (temp->str , ")") == 0){
                        temp=temp->next;
                        check=1;
                    }
                    else {
                        printf("%d : Expected to see ')' but '%s' have been seen.\n", temp->line, temp->str);
                        error ++;
                        go_end2();
                    }
                }
                else {
                    printf("%d : Expected to see an identifire or a number after conditional operator, but '%s' have been seen.\n", temp->line, temp->str);
                    error ++;
                    go_end3();
                }
            }
            else{
                printf("%d : Expected to see a conditional operator after 'if', but '%s' have been seen.\n", temp->line, temp->str);
                error ++;
                go_end3();
            }
        }
        else {
            printf("%d : Expected to see an identifire, but %d have been seen.\n", temp->line, temp->str);
            error ++;
            go_end2();
        }

    }
    else {
        printf("%d : Expected to see '(' after 'if', but '%s' have been seen.\n", temp->line, temp->str);
        error ++;
        go_end3();
    }

    ////////////////////////////////////////////////////
    if (check==1){
        help1=temp;
        if (temp->str[0]=='{'){
            while (ak==0 && strcmp(temp->str , "?")!=0){
                temp=temp->next;

                if (temp->str[0]=='}' && ak2==0)
                {
                    ak=1;
                }
                else if (temp->str[0]=='{'){
                    ak2++;
                }
                else if (temp->str[0]=='}' && ak2!=0){
                    ak2--;
                }
            }
            if (ak == 1){
            }
            else{
                temp=help1;
                end_akolad();
                error ++;
            }
        }
        else {
            printf("%d : Expected to see '{' after ')'\n", temp->line, temp->str);
            error ++;
            go_end2();
        }
        temp=help1;
    }
}

int C_else (){
    int ak=0 , ak2=0;
    help1=temp;
    temp=temp->next;
    if (temp->str[0]=='{'){
        while (ak==0 && strcmp(temp->str , "?")!=0){
            temp=temp->next;
            if (temp->str[0]=='}' && ak2==0) {
                ak=1;
            }
            else if (temp->str[0]=='{'){
                ak2++;
            }
            else if (temp->str[0]=='}' && ak2!=0){
                ak2--;
            }
        }
        if (ak == 1){
        }
        else{
            temp=help1;
            end_akolad();
            error ++;
        }
    }
    else {
        printf("%d : Expected to see '{' after ')', but '%s' have been seen.\n", temp->line, temp->str);
        error ++;
        go_end2();
    }
    temp=help1;
}

int C_number () {
    int flt=0,j=0,i;
    for (i=0 ; i<strlen(temp->str) ; i++) {
        if ((temp->str[i]>=48 && temp->str[i]<=57) || (temp->str[i]==46)) {
            if (temp->str[i]==46)
                flt++;// agar az 1 bishtar shavad aslan addad nist
            j++;
        }
    }
    if (j!=strlen(temp->str))
        return -1; //addad nabood
    else if (flt==1 && j==strlen(temp->str))
        return 0; //ashari bood
    return 1;
}

int C_name() {
    int j=0 , k=0 ,i;
    for (i=0 ; i<strlen(temp->str) ; i++) {
        if ((temp->str[i]>=65 && temp->str[i]<=90) || (temp->str[i]>=97 && temp->str[i]<=122) || (temp->str[i]>=48 && temp->str[i]<=57) ) {
            if (temp->str[i]>=48 && temp->str[i]<=57)
                k++;
            j++;
        }
    }
    if (j!=strlen(temp->str) || k==j) //k=j baraye emsi ke kolan addade
        return 0; //esmet ghalate
    return 1;
}

void C_math(){
    if (!temp->str=='=') {
        return 2; //mosavi nadidam
    }
}

void go_end(){
    while(temp->str[0]!=';' && temp->str[0]!='?') {
        temp=temp->next;
    }
}

void go_end_semy(){
    while(temp->str[0]!=';') {
        temp=temp->next;
    }
    printf ("%d : Expected to see ';', but %d have been seen.\n" , temp->line);
}

int go_virgool (){
    while(temp->str[0]!=';' && temp->str[0]!=',') {
        temp=temp->next;
    }
    if (temp->str[0]==';')
        return 0;
    else
        return 1;
}

int name_exist() {
    int i;
    for (i=0 ; i<table_cont ; i++) {
        if (strcmp(name_table[i], temp->str ) == 0)
            return 1;
    }
    return 0;
}

int name_index (){
    int i;
    for (i=0 ; i<table_cont ; i++) {
        if (strcmp(name_table[i], temp->str ) == 0)
            return i;
    }

}

void go_end3 (){
    while(temp->str[0]!=';' && temp->str[0]!='?' && temp->type!=1) {
        temp=temp->next;
    }
    temp=temp->back;

}

void go_end2(){
    /*while(strcmp(temp->str , "{")!=0 && strcmp(temp->str , "}")!=0 && strcmp(temp->str , "?")!=0) {
        temp=temp->next;
    }*/
    while(temp->str[0]!=';' && temp->str[0]!='?' && temp->type==1 && temp->type==3) {
        temp=temp->next;
    }
    temp=temp->back;
}

int C_voidAndMain() {
    int ak=0 , ak2=0;
    temp = temp->next;
        if(temp->type == 1 && temp->attribute==0){
            temp = temp->next;
            if(temp->type == 6 && temp->attribute==1){
                temp = temp->next;
                if(temp->type == 6 && temp->attribute==2){
                    temp = temp->next;
                }
                else{
                    printf("%d : Expected to see ')', but '%s' have been seen.\n", temp->line, temp->str);
                    error ++;
                    go_end2();
                }
            }
            else{
                printf("%d : Expected to see '(' after 'main', but '%s' have been seen.\n", temp->line, temp->str);
                error ++;
                go_end2();
            }
        }
        else{
            printf("%d : Expected to see 'main' after 'void'\n", temp->line, temp->str);
            error ++;
            go_end2();
        }

    ////////////////////////////////////////////////////
    help1=temp;
    if (strcmp(temp->str , "{")==0){
        while (ak==0 && strcmp(temp->str , "?")!=0){
            temp=temp->next;
            if (temp->str[0]=='}' && ak2==0) {
                ak=1;
            }
            else if (temp->str[0]=='{') {
                ak2++;
            }
            else if (temp->str[0]=='}' && ak2!=0) {
                ak2--;
            }
        }
        if (ak == 1) {
        }
        else{
            temp=help1;
            end_akolad();
            error ++;
        }
    }
    else {
        printf("%d : Expected to see '{' after ')', but '%s' have been seen.\n", temp->line, temp->str);
        error ++;
        go_end2();
    }
    temp=help1;
}

void end_akolad (){
    while (strcmp(temp->str , "}")!=0 && strcmp(temp->str , "?")!=0){
        temp=temp->next;
    }
    if (strcmp(temp->str , "?")==0)
        printf("%d : Brace has not be closed('{' expected).\n", temp->line);
    else
        printf("%d : Brace has not be closed('{' expected).\n", temp->line);
    }

int C_expression() {
    while (strcmp (temp->str , ";")!=0 && strcmp (temp->str , "?")!=0) {
        if(temp -> type == 3){
            temp = temp -> next;
            if(temp->type == 2 && temp->attribute == 11) {
                temp = temp -> next;
                if(temp->type == 3 || temp->type == 4){
                    if(strcmp(temp->str, "min") == 0 || strcmp(temp->str, "max") == 0 ){
                        temp=temp->next;
                        if(temp->type == 6 && temp->attribute == 1){
                            temp=temp->next;
                            if(temp->type == 4 || temp->type == 3) {
                                temp=temp->next;
                                if(temp->type == 6 && temp->attribute == 5){
                                    temp=temp->next;
                                    if(temp->type == 4 || temp->type == 3) {
                                        temp=temp->next;
                                        if(temp->type==6 && temp->attribute==2){
                                            temp=temp->next;
                                        }
                                        else{
                                            printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                                            go_end();
                                            error ++;
                                        }
                                    }
                                    else{
                                        printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                                        go_end();
                                        error ++;
                                    }
                                }
                                else{
                                    printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                                    go_end();
                                    error ++;
                                }
                            }
                            else{
                                printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                                go_end();
                                error ++;
                            }
                        }
                        else{
                            printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                            go_end();
                            error ++;
                        }
                    }
                    /*else if(strcmp(temp->str , "true") == 0 || strcmp(temp->str , "false") == 0){
                        temp=temp->next;
                    }*/
                    else{
                        temp = temp -> next;
                        if ((temp->type == 2 && temp->attribute<=4 && temp->attribute>=1) || temp->attribute==11){
                            temp = temp -> next;
                            if(temp->type == 3 || temp->type == 4){
                                temp = temp->next;
                            }
                            else{
                                //printf("Ba'd az id/num op id/num bayad ; byayad!\n");
                                printf("%d : Expected to see an identifire or a number after operator, but '%s' have been seen.\n", temp->line, temp->str);
                                go_end();
                                error ++;
                            }
                        }
                        else if(temp->type == 6 && temp->attribute == 6){
                            break;
                        }
                        else {
                            printf("%d : Expected to see an operator or ';' after identifires and numbers, but '%s' have been seen.\n", temp->line, temp->str);
                            error ++;
                            go_end();
                        }
                    }
                }
                else if(strcmp(temp->str , "'") == 0) {
                    temp=temp->next;
                    if(temp->type == 5){
                        temp=temp->next;
                        if(strcmp(temp->str, "'") == 0){
                           temp=temp->next;
                        }
                        else{
                            printf("%d : Correct structure of \"char = ' c '\" is missed.\n" , temp->line);
                            error ++;
                            go_end();
                        }
                    }
                    else{
                        printf("%d : Correct structure of \"char = ' c '\" is missed.\n" , temp->line);
                        error ++;
                        go_end();
                    }
                }
                else{
                    printf("%d : Expected to see an identifire or a number or min/max or 'c' but '%s' have been seen.\n", temp->line, temp->str);
                    go_end();
                    error ++;
                }
            }
            else{
                printf("%d : Expected to see '=' after identifre but '%s' have been seen.\n", temp->line, temp->str);
                error ++;
                go_end();
            }
        }
        else{
            printf("%d : Expected to see an identifre at the strat of expression, but '%s' have been seen.\n", temp->line, temp->str);
            go_end();
            error ++;
        }
    }
}

void check (){
    temp=first;
    while (strcmp (temp->str , "?")!=0){
        if (strcmp(temp->str , "}")==0 || strcmp(temp->str , "{")==0) {
        }
        else if (strcmp(temp->str , "if")==0) {
            C_if();
        }
        else if (strcmp(temp->str , "else")==0) {
            C_else();
        }
        else if (strcmp(temp->str , "int")==0) {
            C_intigerAndFloat();
        }
        else if (strcmp(temp->str , "float")==0) {
            C_intigerAndFloat();
        }
        else if (strcmp(temp->str , "char")==0) {
            C_character();
        }
        else if (temp->type==1 && temp->attribute==6){
            C_boolean();
        }
        else if (strcmp(temp->str , "#")==0){
            preprocessor();
        }
        else if (strcmp(temp->str , "void")==0){
            C_voidAndMain();
        }
        else if (temp->type==3 && strcmp(temp->str , "?")!=0){
            C_expression();
        }
        else {
            printf ("%d : no match!\n" , temp->line);
            error ++;
        }

        if (temp->str[0]!='?'){
            temp=temp->next;
        }
    }
    if (error == 0){
        printf ("\nNO ERROR! ");
    }
    else if (error == 1 ){
        printf ("\n%d ERROR FOUND! \n" , error);
    }
    else {
        printf ("\n%d ERRORS FOUND! \n" , error);
    }
}

void semantic (){
}

void make_table (){
    int check=1 , check2 = 1;

    temp=first;

    while (temp->str[0] != '?'){
        check=1;
        if (strcmp (temp->str , "int")==0){

            while (check==1){
                temp=temp->next;
                if (strcmp (temp->str , ";")!=0){
                    if (name_exist()==1){
                        printf ("%d : moteghayer '%s' ghablan tarif shode.\n" , temp->line , temp->str);
                        go_end();
                        check=0;
                        check2=0;
                    }
                    else{
                        //printf ("jj");
                        strcpy(name_table[table_cont] , temp->str);
                        num_table[table_cont][0]=3;
                        check=go_virgool();
                        table_cont++;
                    }
                }
            }
        }
        else if (strcmp (temp->str , "float")==0){
            check=1;
            while (check==1){
                temp=temp->next;
                if (strcmp (temp->str , ";")!=0){
                    if (name_exist()==1){
                        printf ("%d : moteghayer '%s' ghablan tarif shode.\n" , temp->line , temp->str);
                        go_end();
                        check=0;
                        check2=0;
                    }
                    else{
                        strcpy(name_table[table_cont] , temp->str);
                        num_table[table_cont][0]=4;
                        check=go_virgool();
                        table_cont++;
                    }
                }
            }
        }
        else if (strcmp (temp->str , "char")==0){
            check=1;
            while (check==1){
                temp=temp->next;
                if (strcmp (temp->str , ";")!=0){
                    if (name_exist()==1){
                        printf ("%d : moteghayer '%s' ghablan tarif shode.\n" , temp->line , temp->str);
                        go_end();
                        check=0;
                        check2=0;
                    }
                    else{
                        strcpy(name_table[table_cont] , temp->str);
                        num_table[table_cont][0]=5;
                        check=go_virgool();
                        table_cont++;
                    }
                }
            }
        }
        //printf ("%s" , temp->str);
        temp=temp->next;
    }
    printf ("%d" , check2);
    return check2;


}

int check_id (){
    temp=first;
    int check=1;
    while (temp->str[0] != '?'){
        if (temp->type==3){
            if (name_exist()==0){
                printf ("%d : moteghayer '%s' ghablan tarif nashode ast.\n" , temp->line , temp->str);
                check=0;
            }
        }
        temp=temp->next;
    }
    return check;
}

void change_number (){





}

void table_number (){



}

int states (){

    ////////////state 1 \\\\\\\\\\\\\

    help=temp;

    if (temp->type==3){
        temp=temp->next;
        if (temp->type==2 && temp->attribute==11){
            temp=temp->next;
            if (temp->type==3){
                temp=temp->next;
                if (temp->type==6 && temp->attribute==6){
                    temp=help;
                    return 2;
                }
                else if (temp->type==2 && temp->attribute>=1 && temp->attribute<=4){
                    temp=temp->next;
                    if (temp->type==3){
                        temp=temp->next;
                        if (temp->type==6 && temp->attribute==6){
                        temp=help;
                        return 4;
                        }
                    }
                    else if (temp->type==4){
                        temp=temp->next;
                        if (temp->type==6 && temp->attribute==6){
                        temp=help;
                        return 5;
                        }
                    }
                }
            }
            else if (temp->type==4){
                temp=temp->next;
                if (temp->type==6 && temp->attribute==6){
                    temp=help;
                    return 1;
                }
                else if (temp->type==2 && temp->attribute>=1 && temp->attribute<=4){
                    temp=temp->next;
                    if (temp->type==3){
                        temp=temp->next;
                        if (temp->type==6 && temp->attribute==6){
                        temp=help;
                        return 6;
                        }
                    }
                    else if (temp->type==4){
                        temp=temp->next;
                        if (temp->type==6 && temp->attribute==6){
                        temp=help;
                        return 3;
                        }
                    }
                }
            }
        }
        else if (temp->type==2 && temp->attribute>=5 && temp->attribute<=10){
            temp=temp->next;
            if (temp->type==3){
                temp=temp->next;
                temp=help;
                return 7;

            }
            else if (temp->type==4){
                temp=temp->next;
                temp=help;
                return 8;

            }
        }
    }
    else if (temp->type==4){
        temp=temp->next;
        if (temp->type==2 && temp->attribute>=5 && temp->attribute<=10){
            temp=temp->next;
            if (temp->type==3){
                temp=temp->next;
                temp=help;
                return 9;

            }
            else if (temp->type==4){
                temp=temp->next;
                temp=help;
                return 10;
            }
        }
    }


    temp=help;
    return 0;

}


int IR_if (){
    temp=temp->next;
    temp=temp->next;
    state_number=states();
    help1=temp;
    while (temp->str[0]!='}'){
        temp=temp->next;
    }
    temp=temp->next;
    if (strcmp(temp->str, "else")==0){
        check_else=1;
    }
    temp=help1;

    if (state_number==7){
        fprintf (fpIR , "IF T%d " , name_index());
        temp=temp->next;
        fprintf (fpIR , "%s " , temp->str);
        temp=temp->next;
        fprintf (fpIR , "T%d " , name_index());
    }
    else if (state_number==8){
        temp=temp->next;
        temp=temp->next;
        fprintf (fpIR , "T_%d = %s \n" , num , temp->str);
        temp=temp->back;
        temp=temp->back;
        fprintf (fpIR , "IF T%d " , name_index());
        temp=temp->next;
        fprintf (fpIR , "%s T_%d" , temp->str , num);
        num++;
    }
    else if (state_number==9){
        fprintf (fpIR , "T_%d = %s \n" , num , temp->str);
        temp=temp->next;
        fprintf (fpIR , "IF T_%d %s " , num , temp->str);
        temp=temp->next;
        fprintf (fpIR , "T%d" , name_index());
        num++;
    }
    else if (state_number==10){
        fprintf (fpIR , "T_%d = %s \n" , num , temp->str);
        temp=temp->next;
        temp=temp->next;
        fprintf (fpIR , "T_%d = %s \n" , num + 1 , temp->str);
        temp=temp->back;
        fprintf (fpIR , "IF T_%d %s T_%d " , num , temp->str , num + 1);
        num=num+2;
    }

    fprintf (fpIR , "goto L%d else L%d \nL%d\n\n" , flag , flag+1 ,flag);
    flag=flag+2;
    IR_Generation2();

    if (check_else == 1){
        fprintf (fpIR , "goto L%d\nL%d\n\n" , flag , flag-1);
        temp=temp->next;
        temp=temp->next;
        temp=temp->next;
        flag=flag+1;
        IR_Generation2();
        fprintf (fpIR , "L%d\n" , flag-1);
        check_else=0;
        temp=temp->next;
    }
    else {
        fprintf (fpIR , "L%d\n\n" , flag-1);
        check_else=0;
        temp=temp->next;
    }


}

void IR_Generation (){



    while (temp->str[0]!='?'){

        if (temp->type == 3){
            state_number=states();
            printf ("%s" , temp->str);
            printf ("%d " , state_number);

            if (state_number==1){
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "T_%d = %s\n", num , temp->str);
                temp=temp->back;
                temp=temp->back;
                fprintf (fpIR , "T%d = T_%d\n\n", name_index() , num);
                num++;
                go_end();

            }

            else if (state_number==2){
                fprintf (fpIR , "T%d := ", name_index());
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "T%d \n\n", name_index());
                go_end();
            }

            else if (state_number==3){
                temp=temp->next;
                temp=temp->next;
                fprintf(fpIR , "T_%d := %s\n" , num , temp->str);
                num++;
                temp=temp->next;
                temp=temp->next;
                fprintf(fpIR , "T_%d := %s\n" , num , temp->str);
                temp=temp->back;
                help1=temp;
                temp=temp->back;
                temp=temp->back;
                temp=temp->back;
                fprintf(fpIR , "T%d := T_%d %s T_%d\n\n" , name_index() ,num-1, help1->str , num);
                num++;
                go_end();
            }
            else if (state_number == 4){
                fprintf(fpIR , "T%d := ", name_index());
                temp = temp->next;
                temp = temp->next;
                fprintf(fpIR , "T%d ", name_index());
                temp=temp->next;
                fprintf(fpIR , "%s ", temp->str);
                temp = temp->next;
                fprintf(fpIR , "T%d\n\n", name_index());
                go_end();
            }
            else if (state_number==5){
                help1=temp;
                go_end();
                temp=temp->back;
                fprintf (fpIR , "T_%d := %s\n" , num , temp->str);
                temp=help1;
                fprintf(fpIR , "T%d := ", name_index());
                temp = temp->next;
                temp = temp->next;
                fprintf(fpIR , "T%d ", name_index());
                temp=temp->next;
                fprintf(fpIR , "%s ", temp->str);
                temp=temp->str;
                fprintf(fpIR , "T_%d\n\n" , num);
                num++;
                go_end();


            }
            else if (state_number==6){
                help1=temp;
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "T_%d := %s\n" , num , temp->str);
                temp=help1;
                fprintf (fpIR , "T%d := T_%d " , name_index() , num);
                temp=temp->next;
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "%s " , temp->str);
                temp=temp->next;
                fprintf (fpIR , "T%d\n\n" , name_index());
                num++;
                go_end();
            }
        }

        else if (strcmp(temp->str, "if")==0){
            IR_if();
        }
        else if (strcmp(temp->str , "void") == 0){
            fprintf(fpIR, "PROCEDURE MAIN\nBEGIN\n\n");
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
        }


        if (temp->str[0]!='?')
            temp=temp->next;



    }



}

void IR_Generation2 (){



    while (temp->str[0]!='?' && temp->str[0]!='}'){

        if (temp->type == 3){
            state_number=states();
            printf ("%s" , temp->str);
            printf ("%d " , state_number);

            if (state_number==1){
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "T_%d = %s\n", num , temp->str);
                temp=temp->back;
                temp=temp->back;
                fprintf (fpIR , "T%d = T_%d\n\n", name_index() , num);
                num++;
                go_end();

            }

            else if (state_number==2){
                fprintf (fpIR , "T%d := ", name_index());
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "T%d \n\n", name_index());
                go_end();
            }

            else if (state_number==3){
                temp=temp->next;
                temp=temp->next;
                fprintf(fpIR , "T_%d := %s\n" , num , temp->str);
                num++;
                temp=temp->next;
                temp=temp->next;
                fprintf(fpIR , "T_%d := %s\n" , num , temp->str);
                temp=temp->back;
                help1=temp;
                temp=temp->back;
                temp=temp->back;
                temp=temp->back;
                fprintf(fpIR , "T%d := T_%d %s T_%d\n\n" , name_index() ,num-1, help1->str , num);
                num++;
                go_end();
            }
            else if (state_number == 4){
                fprintf(fpIR , "T%d := ", name_index());
                temp = temp->next;
                temp = temp->next;
                fprintf(fpIR , "T%d ", name_index());
                temp=temp->next;
                fprintf(fpIR , "%s ", temp->str);
                temp = temp->next;
                fprintf(fpIR , "T%d\n\n", name_index());
                go_end();
            }
            else if (state_number==5){
                help1=temp;
                go_end();
                temp=temp->back;
                fprintf (fpIR , "T_%d := %s\n" , num , temp->str);
                temp=help1;
                fprintf(fpIR , "T%d := ", name_index());
                temp = temp->next;
                temp = temp->next;
                fprintf(fpIR , "T%d ", name_index());
                temp=temp->next;
                fprintf(fpIR , "%s ", temp->str);
                temp=temp->str;
                fprintf(fpIR , "T_%d\n\n" , num);
                num++;
                go_end();


            }
            else if (state_number==6){
                help1=temp;
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "T_%d := %s\n" , num , temp->str);
                temp=help1;
                fprintf (fpIR , "T%d := T_%d " , name_index() , num);
                temp=temp->next;
                temp=temp->next;
                temp=temp->next;
                fprintf (fpIR , "%s " , temp->str);
                temp=temp->next;
                fprintf (fpIR , "T%d\n\n" , name_index());
                num++;
                go_end();
            }
        }

        else if (strcmp(temp->str, "if")==0){
            IR_if();
        }
        else if (strcmp(temp->str , "void") == 0){
            fprintf(fpIR, "PROCEDURE MAIN\nBEGIN\n\n");
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
        }


        if (temp->str[0]!='?')
            temp=temp->next;



    }

printf("test");

}
