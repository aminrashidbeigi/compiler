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
<<<<<<< HEAD
}*temp,*first,*first2,*help,*help1,*help2 , *myfirst;

int checkMain=0 , checkReturn=0;
=======
}*temp,*first,*first2,*help,*help1,*help2;

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
char name_table [20][20]; //////esm
int num_table [20][20]; ///////aval no' bad khatesh
int table_cont=0;

int main(){
    system("color 47");
=======
char name_table [20][20]; //////esm no' meghdar
int num_table [20][20]; ///////aval no' bad meghdar
int table_cont=0;

int main(){
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD


    temp=first;
    preprocessor();
    //printf ("hello");
    first=temp;
    include_load();
    temp=first;


    load_without_enter();
    pretokenize();

    temp=first;

    while (temp->str[0]!='?'){
        printf ("%s" , temp->str);
=======
    //printf ("HELLO");
    //include_load();

    temp=first;
    //preprocessor();

    //first=temp;
    while (temp->str[0]!='?'){
        printf ("%d " , temp->type);
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
        temp=temp->next;
    }
    printf ("%s " , temp->str);
    printf ("\n");

<<<<<<< HEAD

    temp=first;

=======
    //include_load();
    load_without_enter();

    temp=first;

    //load_without_enter();

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    printf ("\n");
    printf ("\n");
    temp=first;
    check();




    temp=first;
    if (error == 0){
        i=make_table();
        if (i==1){
<<<<<<< HEAD

            if (check_id()==1){

                temp=first;
                semantic();
                temp=first;
                IR_Generation();
                fprintf(fpIR , "RETURN \n\nCALL MAIN ");
                fclose (fpIR);
            }
        }


    }

    File_preprocessor();
    //printf ("%s" , help->str);
    //getch();

    printf ("\n");
    printf ("\n");

    //printf ("%d" , error);
=======
            if (check_id()==1){
                //table_number();
            }
        }

    }
    temp=first;
    IR_Generation();

    fprintf(fpIR , "RETURN \n\nCALL MAIN ");
    fclose (fpIR);
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
    fp=fopen ("mytext.txt" , "r");
=======
    fp=fopen ("totaldata.txt" , "r");
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    rewind(fp);
    end = 1;
    while (!feof(fp)){
        a=fgetc(fp);
<<<<<<< HEAD
        if ((a>=48 && a<=57) || (a>=65 && a<=90) || (a>=97 && a<=122) || a==43 || a==47 || a==41 || a==46 || a==40 || a==35 || a==60 || a== 61 || a==62 || a==123 || a==124 || a==125 || a==59 || a==17 || a==44 || a==39 || a==38 || a==96 || a=='"' || a=='*'){
=======
        if ((a>=48 && a<=57) || (a>=65 && a<=90) || (a>=97 && a<=122) || a==43 || a==47 || a==41 || a==46 || a==40 || a==35 || a==60 || a== 61 || a==62 || a==123 || a==124 || a==125 || a==59 || a==17 || a==44 || a==39 || a==38 || a==96 || a=='"'){
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
    myfirst=first;
=======
    first2=first;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    int j=0 , end;
    char a;
    int k=0;

    //////////////////
<<<<<<< HEAD

=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
        //printf ("%s" , include[j]);
        fp=fopen (include[j] , "r");
        if (fp!=NULL){
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
                        temp->next=myfirst;
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
=======
        printf ("%s" , include[j]);
        fp=fopen (include[j] , "r");
        end = 1;
        while (!feof(fp)){
            //printf ("hello");
            a=fgetc(fp);
            if ((a>=48 && a<=57) || (a>=65 && a<=90) || (a>=97 && a<=122) || a==43 || a==47 || a==41 || a==46 || a==40 || a==35 || a==60 || a== 61 || a==62 || a==123 || a==124 || a==125 || a==59 || a==17 || a==44 || a==39 || a==38 || a==96 || a=='"'){
                if (i==0){
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                    help=temp;
                    temp->next=malloc(sizeof(struct tokenize));
                    temp=temp->next;
                    NULLY();
                    temp->back=help;
<<<<<<< HEAD
                    temp->next=myfirst;
                    temp->str[0]='\n';
                }
            }
            fclose (fp);
            k=1;
            j++;
        }
        else {
            printf ("Cannot open \"%s\"." , include[j]);
            error++;
            j++;
        }
=======
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
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    }
}

void load_without_enter (){
    temp=first;
    while (temp->str[0] == '\n' || temp->str[0] == NULL){
        first=temp->next;
        temp=first;
    }
<<<<<<< HEAD
    //printf ("hello");
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
    //printf ("hello");
}

void pretokenize (){
    temp=first;
    while (temp != myfirst){
=======
}

void tokenize (){
    enter=2;
    temp=first;

    ////////////keywords////////////
    while (strcmp(temp->str , "?")!=0){
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
        help1=temp->back;
        help2=temp->next;
        if (strcmp(temp->str , "main")==0) {
            temp->type=1;
            temp->attribute=0;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "if")==0) {
            temp->type=1;
            temp->attribute=1;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "else")==0) {
            temp->type=1;
            temp->attribute=2;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "int")==0) {

            temp->type=1;
            temp->attribute=3;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "float")==0) {
            temp->type=1;
            temp->attribute=4;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "char")==0) {
            temp->type=1;
            temp->attribute=5;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "bool")==0) {
            temp->type=1;
            temp->attribute=6;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "void")==0) {
            temp->type=1;
            temp->attribute=7;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "NULL")==0) {
            temp->type=1;
            temp->attribute=8;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "while")==0) {
            temp->type=1;
            temp->attribute=9;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "true")==0) {
            temp->type=1;
            temp->attribute=10;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "false")==0) {
            temp->type=1;
            temp->attribute=11;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "return")==0) {
            temp->type=1;
            temp->attribute=12;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }

        ////////////operators////////////
        else if (strcmp(temp->str , "+")==0) {
            temp->type=2;
            temp->attribute=1;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "-")==0) {
            temp->type=2;
            temp->attribute=2;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "/")==0) {
            temp->type=2;
            temp->attribute=3;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "*")==0) {
            temp->type=2;
            temp->attribute=4;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , ">")==0) {
            temp->type=2;
            temp->attribute=5;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "<")==0) {
            temp->type=2;
            temp->attribute=6;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "==")==0) {
            temp->type=2;
            temp->attribute=7;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "!=")==0) {
            temp->type=2;
            temp->attribute=8;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "&&")==0) {
            temp->type=2;
            temp->attribute=9;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "||")==0) {
            temp->type=2;
            temp->attribute=10;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "=")==0) {
            temp->type=2;
            temp->attribute=11;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "<=")==0) {
            temp->type=2;
            temp->attribute=12;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , ">=")==0) {
            temp->type=2;
            temp->attribute=13;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }

        ////////////punc////////////
        else if (strcmp(temp->str , "(")==0) {
            temp->type=6;
            temp->attribute=1;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , ")")==0) {
            temp->type=6;
            temp->attribute=2;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "{")==0) {
            temp->type=6;
            temp->attribute=3;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "}")==0) {
            temp->type=6;
            temp->attribute=4;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , ",")==0) {
            temp->type=6;
            temp->attribute=5;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , ";")==0) {
            temp->type=6;
            temp->attribute=6;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "'")==0) {
            temp->type=6;
            temp->attribute=7;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "\"")==0) {
            temp->type=6;
            temp->attribute=8;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (strcmp(temp->str , "#")==0) {
            temp->type=6;
            temp->attribute=9;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }

        /////////number///////////
        else if (C_number()==1) {
            temp->type=4;
            temp->attribute=1;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        else if (C_number()==0) {
            temp->type=4;
            temp->attribute=2;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }

        ////////////char//////////////
        else if ((strcmp(help1->str , "'")==0) && (strcmp(help2->str , "'")==0) && (strlen(temp->str)==1)) {
            temp->type=5;
            temp->attribute=0;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }

        ////////////n////////////
        else if (strcmp(temp->str , "\n")==0) {
            temp->type=7;
            temp->attribute=0;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter++;
            enter_last++;
        }

        ///////////id////////////
        else if (strcmp(temp->str , "?")!=0){
            temp->type=3;
            temp->attribute=0;
<<<<<<< HEAD
            temp->line=0;
=======
            temp->line=enter;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            enter_last=0;
        }
        temp=temp->next;
    }
<<<<<<< HEAD

}

void tokenize (){
    enter=1;
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
        else if (strcmp(temp->str , "?")!=0 && C_name()==1){
            temp->type=3;
            temp->attribute=0;
            temp->line=enter;
            enter_last=0;
        }
        else {
            temp->type=0;
            temp->line=enter;
            enter_last=0;
        }
        temp=temp->next;
    }
}

int preprocessor (){
    int i , j=0;
    while (temp->str[0] == '#' ){
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
                        //printf("%s" , temp->str);
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

void File_preprocessor (){
    char ch;
    int j=0;
    FILE *fp , *fph;
    fp = fopen ("totaldata.txt" , "w");
    while (include[j][0] != '?'){
        fph = fopen(include[j] , "r");
        while (1) {
            ch = fgetc(fph);
            if (ch == EOF) break;
            else putc(ch, fp);
        }
        fputc('\n' , fp);
        fclose(fph);
        j++;

    }

    fph = fopen("mytext.txt" , "r");
    while (1) {
        ch = fgetc(fph);
        if (ch == EOF) break;
        else putc(ch, fp);
    }
    fclose(fph);

    fclose(fp);

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
=======
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
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6

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
<<<<<<< HEAD
                                break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                            }
                        }
                        else if (strcmp (temp->str , ";") == 0) {
                            go_end();
<<<<<<< HEAD
                            break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                        }
                        else {
                            error ++;
                            go_end();
                            printf ("%d : Expected to see an operator after identifire, but '%s' have been seen.\n", temp->line, temp->str);
<<<<<<< HEAD
                            break;
                        }
                    }
                    else if (strcmp(temp->str , ";")==0) {
                        break;
                    }
                    else {
                        printf ("%d : Expected to see ';', but '%s'.\n" , temp->line , temp->str);
                        error++;
                        go_end();
                        break;
=======
                        }
                    }
                    else if (strcmp(temp->str , ";")==0) {
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                    }
                }
                else {
                    printf ("%d : Expected to see an operator or identifire after '=', but '%s' have been seen.\n", temp->line, temp->str);
                    error ++;
                    go_end();
<<<<<<< HEAD
                    break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                }
            }
            else if (strcmp (temp->str , ";") == 0) {
                go_end();
<<<<<<< HEAD
                break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6

            }
            else if (strcmp (temp->str , ",") == 0){
                continue;
            }
            else {
                printf ("%d : Expected to see an ';' or '=' after identifire, but '%s' have been seen.\n", temp->line, temp->str);
                go_end();
                error ++;
<<<<<<< HEAD
                break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
            break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
            printf("%d : Expected to see an identifire, but %s have been seen.\n", temp->line, temp->str);
=======
            printf("%d : Expected to see an identifire, but %d have been seen.\n", temp->line, temp->str);
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
    if (j!=strlen(temp->str) || temp->str[0]=='.')
=======
    if (j!=strlen(temp->str))
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
    if (j!=strlen(temp->str) || k==j || (temp->str[0]<=57 && temp->str[0]>=48)) //k=j baraye emsi ke kolan addade
=======
    if (j!=strlen(temp->str) || k==j) //k=j baraye emsi ke kolan addade
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
        return 0; //esmet ghalate
    return 1;
}

void C_math(){
    if (!temp->str=='=') {
        return 2; //mosavi nadidam
    }
}

void go_end(){
<<<<<<< HEAD
    while(temp->str[0]!=';' && temp->str[0]!='?' && temp->type!=1) {
        temp=temp->next;
    }
    if (temp->type==1){
        temp=temp->back;
    }
=======
    while(temp->str[0]!=';' && temp->str[0]!='?') {
        temp=temp->next;
    }
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
    if (temp->type==1){
        temp=temp->back;
    }
=======
    temp=temp->back;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6

}

void go_end2(){
    /*while(strcmp(temp->str , "{")!=0 && strcmp(temp->str , "}")!=0 && strcmp(temp->str , "?")!=0) {
        temp=temp->next;
    }*/
<<<<<<< HEAD
    while(temp->str[0]!=';' && temp->str[0]!='?' && temp->type!=1) {
        temp=temp->next;
    }
    if (temp->type==1){
        temp=temp->back;
    }
=======
    while(temp->str[0]!=';' && temp->str[0]!='?' && temp->type==1 && temp->type==3) {
        temp=temp->next;
    }
    temp=temp->back;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
}

int C_voidAndMain() {
    int ak=0 , ak2=0;
    temp = temp->next;
        if(temp->type == 1 && temp->attribute==0){
            temp = temp->next;
<<<<<<< HEAD
            checkMain=1;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
        printf("%d : Brace has not be closed('}' expected).\n", temp->line);
    else
        printf("%d : Brace has not be closed('}' expected).\n", temp->line);
=======
        printf("%d : Brace has not be closed('{' expected).\n", temp->line);
    else
        printf("%d : Brace has not be closed('{' expected).\n", temp->line);
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
                                            break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                                        }
                                    }
                                    else{
                                        printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                                        go_end();
                                        error ++;
<<<<<<< HEAD
                                        break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                                    }
                                }
                                else{
                                    printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                                    go_end();
                                    error ++;
<<<<<<< HEAD
                                    break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                                }
                            }
                            else{
                                printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                                go_end();
                                error ++;
<<<<<<< HEAD
                                break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                            }
                        }
                        else{
                            printf("%d : Correct structure of min/max(num,num) is missed.\n",temp->line);
                            go_end();
                            error ++;
<<<<<<< HEAD
                            break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
                                break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                            }
                        }
                        else if(temp->type == 6 && temp->attribute == 6){
                            break;
                        }
                        else {
                            printf("%d : Expected to see an operator or ';' after identifires and numbers, but '%s' have been seen.\n", temp->line, temp->str);
                            error ++;
                            go_end();
<<<<<<< HEAD
                            break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
                            break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                        }
                    }
                    else{
                        printf("%d : Correct structure of \"char = ' c '\" is missed.\n" , temp->line);
                        error ++;
                        go_end();
<<<<<<< HEAD
                        break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                    }
                }
                else{
                    printf("%d : Expected to see an identifire or a number or min/max or 'c' but '%s' have been seen.\n", temp->line, temp->str);
                    go_end();
                    error ++;
<<<<<<< HEAD
                    break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                }
            }
            else{
                printf("%d : Expected to see '=' after identifre but '%s' have been seen.\n", temp->line, temp->str);
                error ++;
                go_end();
<<<<<<< HEAD
                break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            }
        }
        else{
            printf("%d : Expected to see an identifre at the strat of expression, but '%s' have been seen.\n", temp->line, temp->str);
            go_end();
            error ++;
<<<<<<< HEAD
            break;
=======
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
        }
    }
}

void check (){
    temp=first;
    while (strcmp (temp->str , "?")!=0){
<<<<<<< HEAD
        if (strcmp(temp->str , "}")==0 || strcmp(temp->str , "{")==0 || strcmp(temp->str , ";")==0) {
        }
        else if (strcmp(temp->str , "if")==0 || strcmp(temp->str , "while")==0) {
            if (checkMain==0){
                printf ("ERROR : Expected to see 'main' before if/while.\n");
                error++;
            }
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_if();
        }
        else if (strcmp(temp->str , "else")==0) {
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_else();
        }
        else if (strcmp(temp->str , "int")==0) {
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_intigerAndFloat();
        }
        else if (strcmp(temp->str , "float")==0) {
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_intigerAndFloat();
        }
        else if (strcmp(temp->str , "char")==0) {
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_character();
        }
        else if (temp->type==1 && temp->attribute==6){
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_boolean();
        }
        else if (strcmp(temp->str , "#")==0){
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            preprocessor();
        }
        else if (strcmp(temp->str , "void")==0){
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_voidAndMain();
        }
        else if (temp->type==3 && strcmp(temp->str , "?")!=0){
            if (checkReturn==1){
                printf ("ERROR : After return nothing should come.\n");
                error++;
                break;
            }
            C_expression();
        }
        else if (strcmp(temp->str , "return")==0){
            checkReturn=1;
            temp=temp->next;
            if (temp->str[0]!=';'){
                printf ("%d : Expected to see ';' after return.\n" , temp->line);
                error++;
                continue;
            }
        }
        else {
            if (temp->str[0]!='?'){
                printf ("%d : no match ('%s') !\n" , temp->line , temp->str);
                printf ("%s" , temp->str);
                error ++;
            }
        }

        if (temp->str[0]!='?'){
            temp=temp->next;

        }
    }
    if (error == 1 ){
        printf ("\n%d ERROR FOUND! \n" , error);
    }
    else if (error > 1){
        printf ("\n%d ERRORS FOUND! \n" , error);
    }
}

void semantic (){
    temp=first;
    int name_index1 , name_index2 ,name_index3;
    while (temp->str[0]!= '?'){
        if (temp->type==3){
            state_number=states();
            if (state_number==1){
                name_index2=name_index();
                name_index1=num_table[name_index2][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=temp->attribute;
                if ((name_index1==3 && name_index2==2)){
                    printf ("%d : int = float (!!)\n" , temp->line);
                    error++;
                }
                else if (name_index1==4 && name_index2==1){
                    printf ("%d : float = int (!!)\n" , temp->line);
                }
                else if (name_index1==1 && name_index2==4){
                    printf ("%d : int = float (!!)\n" , temp->line);
                }
                else if (name_index1==2 && name_index2==3){
                    printf ("%d : float = int (!!)\n" , temp->line);
                }
            }
            else if (state_number==2){
                name_index1=name_index();
                name_index1=num_table[name_index1][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=name_index();
                name_index2=num_table[name_index2][0];
                if (name_index1 == 3 && name_index2 == 4){
                    printf ("%d : int = float (!!)\n" , temp->line);
                }
                else if (name_index1 == 4 && name_index2 == 3){
                    printf ("%d : float = int (!!)\n" , temp->line);
                }
            }
            else if (state_number==3){
                name_index1=name_index();
                name_index1=num_table[name_index1][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=temp->attribute;
                temp=temp->next;
                temp=temp->next;
                name_index3=temp->attribute;
                if (name_index1==3 && name_index2==1 && name_index3==2){
                    printf ("%d : int = int (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==2 && name_index3==1){
                    printf ("%d : int = float (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==1 && name_index3==2){
                    printf ("%d : float = int (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==2 && name_index3==1){
                    printf ("%d : float = float (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==1 && name_index3==1){
                    printf ("%d : float = int (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==2 && name_index3==2){
                    printf ("%d : int = float (op) float (!!)\n" , temp->line);
                }

            }
            else if (state_number==4){
                name_index1=name_index();
                name_index1=num_table[name_index1][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=name_index();
                name_index2=num_table[name_index2][0];
                temp=temp->next;
                temp=temp->next;
                name_index3=name_index();
                name_index3=num_table[name_index3][0];
                if (name_index1==3 && name_index2==4 && name_index3==4){
                    printf ("%d : int = float (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==3 && name_index3==4){
                    printf ("%d : int = int (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==4 && name_index3==3){
                    printf ("%d : int = float (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==4 && name_index3==3){
                    printf ("%d : float = float (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==3 && name_index3==4){
                    printf ("%d : float = int (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==3 && name_index3==3){
                    printf ("%d : float = int (op) int (!!)\n" , temp->line);
                }
            }
            else if (state_number==5){
                name_index1=name_index();
                name_index1=num_table[name_index1][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=name_index();
                name_index2=num_table[name_index2][0];
                temp=temp->next;
                temp=temp->next;
                name_index3=temp->attribute;
                if (name_index1==3 && name_index2==4 && name_index3==1){
                    printf ("%d : int = float (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==4 && name_index3==2){
                    printf ("%d : int = float (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==4 && name_index3==1){
                    printf ("%d : int = float (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==3 && name_index3==1){
                    printf ("%d : float = int (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==3 && name_index3==2){
                    printf ("%d : float = int (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==3 && name_index3==1){
                    printf ("%d : float = int (op) int (!!)\n" , temp->line);
                }
            }
            else if (state_number==6){
                name_index1=name_index();
                name_index1=num_table[name_index1][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=temp->attribute;
                temp=temp->next;
                temp=temp->next;
                name_index3=name_index();
                name_index3=num_table[name_index2][0];
                if (name_index1==3 && name_index2==2 && name_index3==4){
                    printf ("%d : int = float (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==1 && name_index3==4){
                    printf ("%d : int = int (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==3 && name_index2==2 && name_index3==3){
                    printf ("%d : int = float (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==1 && name_index3==3){
                    printf ("%d : float = int (op) int (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==1 && name_index3==4){
                    printf ("%d : float = int (op) float (!!)\n" , temp->line);
                }
                else if (name_index1==4 && name_index2==2 && name_index3==3){
                    printf ("%d : float = float (op) int (!!)\n" , temp->line);
                }
            }
            else if (state_number==7){
                name_index1=name_index();
                name_index1=num_table[name_index1][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=name_index();
                name_index2=num_table[name_index2][0];
                if (name_index1==3 && name_index2==4){
                    printf ("%d : int (compare) float (!!)" , temp->line);
                }
                else if (name_index1==4 && name_index2==3){
                    printf ("%d : float (compare) int (!!)" , temp->line);
                }
            }
        }
            else if (state_number==8){
                name_index1=name_index();
                name_index1=num_table[name_index1][0];
                temp=temp->next;
                temp=temp->next;
                name_index2=temp->attribute;

                if (name_index1==3 && name_index2==2){
                    printf ("%d : int (compare) float (!!)" , temp->line);
                }
                else if (name_index1==4 && name_index2==1){
                    printf ("%d : float (compare) int (!!)" , temp->line);
                }
            }
        else if (temp->type==4){
            if (state_number==9){
                name_index1=temp->attribute;
                temp=temp->next;
                temp=temp->next;
                name_index2=name_index();
                name_index2=num_table[name_index2][0];
                if (name_index1==1 && name_index2==4){
                    printf ("%d : int (compare) float (!!)" , temp->line);
                }
                else if (name_index1==2 && name_index2==3){
                    printf ("%d : float (compare) int (!!)" , temp->line);
                }
            }
            else if (state_number==10){
                name_index1=temp->attribute;
                temp=temp->next;
                temp=temp->next;
                name_index2=temp->attribute;
                if (name_index1==1 && name_index2==2){
                    printf ("%d : int (compare) float (!!)" , temp->line);
                }
                else if (name_index1==2 && name_index2==1){
                    printf ("%d : float (compare) int (!!)" , temp->line);
                }
            }
        }
        temp=temp->next;
    }
    if (error == 0){
        printf ("NO ERROR !! \n");
    }
    else if (error == 1){
        printf ("1 ERROR FOUND !! \n");
    }
    else {
        printf ("%d ERROR FOUND !! \n" , error);
    }
}

int make_table (){
    int check=1;
    int check2 = 1;
=======
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
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6

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
<<<<<<< HEAD
                        strcpy(name_table[table_cont] , temp->str);
                        num_table[table_cont][0]=3;
                        num_table[table_cont][1]=temp->line;
=======
                        //printf ("jj");
                        strcpy(name_table[table_cont] , temp->str);
                        num_table[table_cont][0]=3;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
        temp=temp->next;
    }

    if (error == 1){
        printf ("1 ERROR FOUND !! \n");
    }
    else if (error > 1){
        printf ("%d ERROR FOUND !! \n" , error);
    }
    return check2;

=======
        //printf ("%s" , temp->str);
        temp=temp->next;
    }
    printf ("%d" , check2);
    return check2;


>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
}

int check_id (){
    temp=first;
    int check=1;
<<<<<<< HEAD
    int hhelp;
    while (temp->str[0] != '?'){
        if (temp->type==3){
                //printf ("**%s  " , temp->str);
                hhelp=name_index();
;            if (name_exist()==0 || ( (num_table[hhelp][1]) > (temp->line) )){
                printf ("%d : moteghayer '%s' ghablan tarif nashode ast.\n" , temp->line , temp->str);
                error++;
=======
    while (temp->str[0] != '?'){
        if (temp->type==3){
            if (name_exist()==0){
                printf ("%d : moteghayer '%s' ghablan tarif nashode ast.\n" , temp->line , temp->str);
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
                check=0;
            }
        }
        temp=temp->next;
    }
<<<<<<< HEAD
    if (error == 1){
        printf ("1 ERROR FOUND !! \n");
    }
    else if(error > 1) {
        printf ("%d ERRORS FOUND !! \n" , error);
    }
    return check;
}

int states (){
    ////////////state 1 \\\\\\\\\\\\\

    help=temp;
=======
    return check;
}

void change_number (){





}

void table_number (){



}

int states (){

    ////////////state 1 \\\\\\\\\\\\\

    help=temp;

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
=======

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
            }
            else if (temp->type==4){
                temp=temp->next;
                temp=help;
                return 10;
            }
        }
    }
<<<<<<< HEAD
=======


>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    temp=help;
    return 0;

}

<<<<<<< HEAD
=======

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
=======

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
    IR_Generation();
=======
    IR_Generation2();

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    if (check_else == 1){
        fprintf (fpIR , "goto L%d\nL%d\n\n" , flag , flag-1);
        temp=temp->next;
        temp=temp->next;
        temp=temp->next;
<<<<<<< HEAD
        IR_Generation();
        fprintf (fpIR , "L%d\n" , flag);
        flag=flag+1;
        check_else=0;
        //temp=temp->next;
=======
        flag=flag+1;
        IR_Generation2();
        fprintf (fpIR , "L%d\n" , flag-1);
        check_else=0;
        temp=temp->next;
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    }
    else {
        fprintf (fpIR , "L%d\n\n" , flag-1);
        check_else=0;
<<<<<<< HEAD
        //temp=temp->next;
    }
}

int IR_while (){
    temp=temp->next;
    temp=temp->next;
    state_number=states();
    if (state_number==7){
        fprintf (fpIR , "L%d\n" , flag+2);
        fprintf (fpIR , "IF T%d " , name_index());
        temp=temp->next;
        fprintf (fpIR , "%s " , temp->str);
        temp=temp->next;
        fprintf (fpIR , "T%d " , name_index());
    }
    else if (state_number==8){
        fprintf (fpIR , "L%d\n" , flag+2);
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
        fprintf (fpIR , "L%d\n" , flag+2);
        fprintf (fpIR , "T_%d = %s \n" , num , temp->str);
        temp=temp->next;
        fprintf (fpIR , "IF T_%d %s " , num , temp->str);
        temp=temp->next;
        fprintf (fpIR , "T%d" , name_index());
        num++;
    }
    else if (state_number==10){
        fprintf (fpIR , "L%d\n" , flag+2);
        fprintf (fpIR , "T_%d = %s \n" , num , temp->str);
        temp=temp->next;
        temp=temp->next;
        fprintf (fpIR , "T_%d = %s \n" , num + 1 , temp->str);
        temp=temp->back;
        fprintf (fpIR , "IF T_%d %s T_%d " , num , temp->str , num + 1);
        num=num+2;
    }
    fprintf (fpIR , "goto L%d else L%d \nL%d\n\n" , flag , flag+1 ,flag);
    IR_Generation();
    fprintf (fpIR , "goto L%d\nL%d\n\n" , flag+2 , flag+1);
    temp=temp->next;
}

void IR_Generation (){
=======
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



>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
    while (temp->str[0]!='?' && temp->str[0]!='}'){

        if (temp->type == 3){
            state_number=states();
<<<<<<< HEAD
            //printf ("%s" , temp->str);
            //printf ("%d " , state_number);
=======
            printf ("%s" , temp->str);
            printf ("%d " , state_number);

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
=======

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
=======


>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
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
<<<<<<< HEAD
        else if (strcmp(temp->str, "if")==0){
            IR_if();
        }
        else if (strcmp(temp->str, "while")==0){
            IR_while ();
            temp=temp->back;
        }
=======

        else if (strcmp(temp->str, "if")==0){
            IR_if();
        }
>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
        else if (strcmp(temp->str , "void") == 0){
            fprintf(fpIR, "PROCEDURE MAIN\nBEGIN\n\n");
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
            temp = temp->next;
<<<<<<< HEAD
        }
        if (temp->str[0]!='?')
            temp=temp->next;
    }
=======
            temp = temp->next;
        }


        if (temp->str[0]!='?')
            temp=temp->next;



    }

printf("test");

>>>>>>> 7b52b41d562f9a2fa19f80c0393477e83efa3eb6
}
