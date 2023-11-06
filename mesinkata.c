#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK){
        ADV();
    }
}

void STARTWORD(FILE *input){
    START(input);
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopyWord();
    }
}

void STARTINPUT(){
    currentWord = toKata("");
    STARTWORD(stdin);
}

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(){
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK){
        if (currentWord.Length < NMax){
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}

Word GetWord(){
    return currentWord;
}

int stringLength(char *str){
    int len = 0;
    while (str[len] != '\0'){
        len = len + 1;
    }

    return len;
}

Word toKata(char *str){
    Word kata;
    kata.Length = stringLength(str);

    for (int i = 0; i < stringLength(str); i++){
        kata.TabWord[i] = str[i];
    }

    return kata;
}

void PrintWord(Word kata){
    for (int i = 0; i < kata.Length; i++){
        printf("%c", kata.TabWord[i]);
    }
}

boolean WordCompare(Word currentWord, Word inputWord){
    boolean found = false;
    int i = 0;

    if (currentWord.Length != inputWord.Length){
        return found;
    }
    else{
        while (!found && i < currentWord.Length){
            if (currentWord.TabWord[i] != inputWord.TabWord[i]){
                return found;
            }
            i += 1;
        }
        return !found;
    }
}

int WordToInt(Word currentWord){
    int i = 0;
    int result = 0;
    while (i < currentWord.Length){
        result = result * 10 + (currentWord.TabWord[i] - '0');
        i += 1;
    }
    return result;
}

Word unionWord(char* str, Word b){
    Word a;
    a.Length = stringLength(str);
    for (int i = 0; i < stringLength(str); i++){
        a.TabWord[i] = str[i];
    }
    for (int i = 0; i < b.Length; i++){
        a.TabWord[a.Length + i] = b.TabWord[i];
    }
    a.Length = a.Length + b.Length;
    return a;
}

char *WordToStr(Word kata){
    char *str = (char *)malloc(kata.Length * sizeof(char));
    for (int i = 0; i < kata.Length; i++){
        str[i] = kata.TabWord[i];
    }
    str[kata.Length] = '\0';
    return str;
}

void concatWord(Word *kata1, Word kata2){
    (*kata1).TabWord[(*kata1).Length] = ' ';
    (*kata1).Length++;
    for (int i = 0; i < kata2.Length; i++){
        (*kata1).TabWord[(*kata1).Length + i] = kata2.TabWord[i];
    }
    (*kata1).Length = (*kata1).Length + kata2.Length;
}

Word intToWord(int n) {
    Word num; num.Length = 0;
    if (n == 0){
        num.TabWord[num.Length] = '0'; num.Length++;
    } 
    else{
        while (n != 0){
            for (int i = num.Length; i > 0; i--) {
                num.TabWord[i] = num.TabWord[i-1];
            }
            num.Length++;
            num.TabWord[0] = (n % 10) + '0';
            n = n / 10;
        }
    }
    return num;
}

Word toLower(Word kata){
    Word lower;
    lower.Length = kata.Length;
    for (int i = 0; i < kata.Length; i++){
        if (kata.TabWord[i] >= 'A' && kata.TabWord[i] <= 'Z'){
            lower.TabWord[i] = kata.TabWord[i] + 32;
        }
        else{
            lower.TabWord[i] = kata.TabWord[i];
        }
    }
    return lower;
}

Word toUpper(Word kata){
    Word upper;
    upper.Length = kata.Length;
    for (int i = 0; i < kata.Length; i++){
        if (kata.TabWord[i] >= 'a' && kata.TabWord[i] <= 'z'){
            upper.TabWord[i] = kata.TabWord[i] - 32;} 
        else{
            upper.TabWord[i] = kata.TabWord[i];
        }
    }
    return upper;
}