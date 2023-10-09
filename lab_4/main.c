#include<stdio.h>
#include<string.h>

//Task from KulevSDA Variant 1
void kulev(){
    int a=0, e=0, i=0, o=0, u=0;
    printf("*** Base Task - Vowels Counter ***\n");
    char string[100];
    printf("Enter a string: ");
     fgets(string, sizeof(string), stdin);

    int string_len = strlen(string);

    for(int k = 0; k < string_len; k++){

        char c = tolower(string[k]);

        if(c == 'a'){
            a += 1;
        }

        if(c == 'e'){
            e += 1;
        }


        if(c == 'i'){
            i += 1;
        }


        if(c == 'o'){
            o += 1;
        }


        if(c == 'u'){
            u += 1;
        }
    }

    printf("Number of 'a': %d.\n", a);
    printf("Number of 'e': %d.\n", e);
    printf("Number of 'i': %d.\n", i);
    printf("Number of 'o': %d.\n", o);
    printf("Number of 'u': %d.\n", u);

}

//Medium Task - Punctuation Mark Counter
int pmark_check(char punct){

char marks[] = "!\"#$%&'()*+,-./:;?@[\\]^_`{|}~";
int marks_len = strlen(marks);
for(int i = 0; i<marks_len;i++){
    if (punct == marks[i]){
        return 1;
    }
}
return 0;

}

void pmarks_count(){
    char s[100];
    printf("*** Medium Task - Punctuation Marks Counter ***\n");
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int string_len = strlen(s);
    int count = 0;

    for(int k = 0; k < string_len; k++){

      if (pmark_check(s[k])) {
        count++;
      }

    }
    printf("The number of punctuation marks is: %d\n", count);
}

//Easy task Palindrome Checker
void easy_palindrome() {
    char s[100];
    printf("*** Easy Task - Palindrome Checker ***\n");
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int string_len = strlen(s) - 1;
    int count = string_len;

    if (s[string_len] == '\n') {
        s[string_len] = '\0';

    }

    char new_s[100] = "";

    for (int i = string_len; i>= 0;i--) {
        char c = tolower(s[i]);
        strncat(new_s, &c, 1);
    }

    int check = string_len;
    for (int i = 0; i < string_len; i++) {
        if (tolower(s[i]) != new_s[i]) {
            check--;
        }
    }

    printf("Reverse string: %s\n", new_s);

    if (check != count) {
        printf("The string is NOT a palindrome!\n");
    } else {
        printf("The string is a palindrome!\n");
    }


}

//Medium Task Palindrome
void medium_palindrome() {
    char s[100];
    printf("*** Medium Task - Palindrome Checker ***\n");
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int string_len = strlen(s) - 1;
    int count = string_len;

    if (s[string_len] == '\n') {
        s[string_len] = '\0';
    }

    char new_s[100] = "";
char s_clean[100] = "";
    for (unsigned i = 0; i < string_len; i++) {
        char k = tolower(s[i]);
        if ((k == ' ') || (pmark_check(k))){
            ;
        }
        else{
            strncat(s_clean, &k, 1);
        }

    }
    printf("Clean Initial String: %s\n", s_clean);

    for (int i = string_len; i >= 0; i--) {
        char c = s_clean[i];
        strncat(new_s, &c, 1);
    }

    int check = string_len;
    for (int i = 0; i < string_len; i++) {
        if (s_clean[i] != new_s[i]) {
            check--;
        }
    }

    printf("Reverse string: %s\n", new_s);

    if (check != count) {
        printf("The string is NOT a palindrome!\n");
    } else {
        printf("The string is a palindrome!\n");
    }


}
int main(){

kulev();
printf("\n");
pmarks_count();
printf("\n");
easy_palindrome();
printf("\n");
medium_palindrome();
return 0;
}
