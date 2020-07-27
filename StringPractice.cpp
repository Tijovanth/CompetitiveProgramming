#include <iostream>
#include <stdio.h>
using namespace std;

int Length(string s){
    int i = 0;
    int count = 0;
    while(s[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

void ToUpperCase(char *s){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 97 && s[i] <= 122){
            s[i] -= 32;
        }
        i++;
    }
}

void ToLoweCase(char *s){
     int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 65 && s[i] <= 90){
            s[i] += 32;
        }
        i++;
    }
}

void ToggleCases(char *s){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 65 && s[i] <= 90){
            s[i] += 32;
        }else{
            s[i] -= 32;
        }
        i++;
    }
}

void CountingVowelsAndConsonants(char *s){
    int vcount = 0; int ccount = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'  ){
            vcount++;
        }else if((s[i] >=65 && s[i] <=90) || (s[i] >=97 && s[i] <=122)){
            ccount++;
        }
    }
    cout << vcount << endl;
    cout << ccount << endl;
}

int CountingWordsInAProgram(char *s){
    int words = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' ' && s[i - 1] != ' '){
            words++;
        }
    }
    return words + 1;
}

int ValidateString(char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if(!(s[i] >= 65 && s[i] <= 90) &&  !(s[i] >= 97 && s[i] <= 122)  &&  !(s[i] >= 48 && s[i] <= 57) ){
            return 0;
        }
    }
    return 1;
}

void ReversingAStringUsingAnotherArray(char *s){
    int length = Length(s);
    char name[length];
    int i,j;
    for( i = 0; s[i] != '\0'; i++){

    }
    i = i - 1;
    for( j = 0; i >= 0; i--,j++){
        name[j] = s[i];
    }
    name[j] = '\0';

    for(int k = 0; name[k] != '\0'; k++){
        cout << name[k];
    }
}

void ReversingAStringUsingSwaping(char *s){
    int i,j;
    for(i = 0; s[i] != '\0'; i++){

    }
    i--;
    for(j = 0; j < i; j++,i--){
        char t = s[j];
        s[j] = s[i];
        s[i] = t;
    }
}

int ComparingAString(char *s, char *s1){
    int i,j;
    for(i=0,j=0; s[i] != '\0' && s1[j] != '0'; i++,j++){
        if(s[i] != s1[i]){
            return 0;
        }
    }
    if(i == j){
        return 1;
    }else{
        return 0;
    }
}

int Palindrome(char *s){
    int i,j,length;
    int flag = 1;
    length = Length(s);
    for(i = 0,j = length - 1; i <= j; i++,j--){
        if(s[i] != s[j]){
            flag = 0;
            break;
        }
    }
    return flag;
}

// should do it later
void FindingTheDuplicatesUsingHashTable(char *s){
    int hash[50];
    // for(int i = 0; i < 50; i++){
    //     hash[i] = 0;
    // }
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 65 && s[i] <= 90 ){
            hash[s[i] - 39] += 1;
        }else if(s[i] >= 97 && s[i] <= 122 ){
            hash[s[i] - 97] += 1;
        }
    }

    for(int i = 0; i < 50; i++){
        if(hash[i] > 1 && i < 26){
            printf("%c ",i + 97);
        }else if(hash[i] > 1 && i > 25){
            printf("%c ",i + 39);
        }
    }
}

void FindingDuplicatesUsingBits(char *s){
    int x = 0,h = 0;
    for(int i = 0; s[i] != '\0'; i++){
        x = 1;
        x = x << (s[i] - 97);
        if((x & h) > 0){
            cout << "Duplicate value " << s[i] << " ";
        }else{
            h = h | x;
        }
    }
}


// should do it later
int FindingGivenStringIsAnagramOrNot(char *s, char *s1){
    int hash[26];
    for(int i = 0; s[i] != '\0'; i++){
        hash[s[i] - 97] += 1;
    }
    for(int i = 0; s1[i] != '\0'; i++){
        if((s1[i] - 97) == -1){
            return 0;
        }else{
            hash[s1[i] - 97] -= 1;
        }
    }
    return 1;
}

void swap(char *s, char *s1){
    char *temp = s;
    s = s1;
    s1 = temp;
}
void perm(char *s, int k){
    static char res[10] = {0};
    static int flag[10] = {0};
    if(s[k] == '\0'){
        res[k] = '\0';
        cout << res <<" ";
    }else{
        for(int i = 0; s[i] != '\0'; i++){
            if(flag[i] == 0){
                res[k] = s[i];
                flag[i] = 1;
                perm(s,k+1);
                flag[i] = 0;
            }
        }
    }
}

void permUsingSwap(char *s, int low, int high){
    int i;
    if(low == high){
        cout << s <<" ";
    }else{
        for(i = low; i <=high; i++){
            swap(s[i],s[low]);
            permUsingSwap(s,low+1,high);
            swap(s[i],s[low]);
        }
    }
}

int main(){
    string s = "tijovanth";
    //cout<<Length(s);
    char name[] = "ABC";
    char name1[] = "medical";
    // ToUpperCase(name);
    // cout << name << endl;
    // ToLoweCase(name);
    // cout << name << endl;
    // ToggleCases(name);
    // cout << name << endl;
    // ToggleCases(name);
    // cout << name << endl;
    //CountingVowelsAndConsonants(name);
    //cout << CountingWordsInAProgram(name);
    //cout << ValidateString(name);
    //ReversingAStringUsingAnotherArray(name);
    //ReversingAStringUsingSwaping(name);
    //cout << name;
    //cout << ComparingAString(name,name1);
    //cout << Palindrome(name);
    //FindingTheDuplicatesUsingHashTable(name1);
    //FindingDuplicatesUsingBits(name1);
    //cout << FindingGivenStringIsAnagramOrNot(name,name1);
    //perm(name1,0);
    permUsingSwap(name,0,2);
}



// void ToUpperCase(char **s){
//     int i = 0;
//     while(*(s[0] + i) != '\0'){
//         if(*(s[0] + i) >= 97 && *(s[0] + i) <= 122){
//             cout<< (s[0] + i) << endl;
//         }
//         i++;
//     }
// }

// int main(){
//     // string s = "tijovanth";
//     // //cout<<Length(s);
//     // char *name = "tijovanth";
//     // ToUpperCase(&name);
//     // cout << s;
//     char *a = "aaa";
//     cout<<a<<endl;
//     char **c = &a;
//     cout<<*(c[0]);
// }