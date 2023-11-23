#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreSeparators(){
    while (currentChar == BLANK || currentChar == COLON){
        ADV();
    }
}

void STARTWORD(FILE *input){
    START(input);
    IgnoreSeparators();
    if (IsEOP()){
        ADV();
        endWord = false;
        CopyWord();
    } else{
        if (IsEOF()){
            endWord = true;
        } else{
            endWord = false;
            CopyWord();
        }
    }
}

void STARTINPUT(){
    currentWord = ToKata("");
    START(stdin);
    IgnoreSeparators();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreSeparators();
    if (IsEOP()){
        ADV();
        if (IsEOF()){
            endWord = true;
        } else{
            endWord = false;
            CopyWord();
            IgnoreSeparators();
        }
    } else{
        if (IsEOF()){
            endWord = true;
        } else{
            endWord = false;
            CopyWord();
            IgnoreSeparators();
        }
    }
}

void ADVWORDNOSPACE(){
    IgnoreSeparators();
    if (IsEOP()){
        ADV();
        endWord = false;
        CopyWordNoSpace();
        IgnoreSeparators();
    } else{
        if (IsEOF()){
            endWord = true;
        } else{
            endWord = false;
            CopyWordNoSpace();
            IgnoreSeparators();
        }
    }
}

void ADVINPUT(){
    IgnoreSeparators();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
        IgnoreSeparators();
    }
}

void CopyWord(){
    currentWord.Length = 0;
    while (currentChar != COLON && currentChar != MARK){
        if (currentWord.Length < (MaxEl)){
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

void CopyWordNoSpace(){
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != COLON && currentChar != MARK){
        if (currentWord.Length < (MaxEl)){
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean IsEndWord() {
    return endWord;
}

Word GetWord(){
    return currentWord;
}

int StringLength(char *str){
    int len = 0;
    while (str[len] != '\0'){
        len = len + 1;
    }

    return len;
}

Word ToKata(char *str){
    Word kata;
    kata.Length = StringLength(str);

    for (int i = 0; i < StringLength(str); i++){
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

Word UnionWord(char* str, Word b){
    Word a;
    a.Length = StringLength(str);
    for (int i = 0; i < StringLength(str); i++){
        a.TabWord[i] = str[i];
    }
    for (int i = 0; i < b.Length; i++){
        a.TabWord[a.Length + i] = b.TabWord[i];
    }
    a.Length = a.Length + b.Length;
    return a;
}

char* WordToStr(Word kata){
    char* str = (char*) malloc(kata.Length * sizeof(char));
    for (int i = 0; i < kata.Length; i++){
        str[i] = kata.TabWord[i];
    }
    str[kata.Length] = '\0';
    return str;
}

void ConcatWord(Word *kata1, Word kata2){
    for (int i = 0; i < kata2.Length; i++){
        (*kata1).TabWord[(*kata1).Length + i] = kata2.TabWord[i];
    }
    (*kata1).Length += kata2.Length;
}

Word IntToWord(int n) {
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

Word ToLower(Word kata){
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

Word ToUpper(Word kata){
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

boolean CheckValidInput(Word kata){
    int ctr = 0;
    for (int i = 0; i < kata.Length; i++){
        if (kata.TabWord[i] != ' '){
            ctr++;
        }

        if (ctr == 3){
            return true;
        } 
    }
    return false;
}

void SplitCommandThreeInt(Word* kata, int* id1, int* id2, int* id3){
    int i = 0;
    while ((i < (*kata).Length) && ((*kata).TabWord[i] != ' ')){
        i++;
    }
    int x1 = i;

    Word temp1;
    int j = i + 1;
    i = 0;
    while ((j < (*kata).Length) && ((*kata).TabWord[j] != ' ')){
        temp1.TabWord[i] = (*kata).TabWord[j];
        i++;
        j++;
    }
    int x2 = i;

    Word temp2;
    int k = j + 1;
    j = 0;
    while ((k < (*kata).Length) && ((*kata).TabWord[k] != ' ')){
        temp2.TabWord[j] = (*kata).TabWord[k];
        j++;
        k++;
    }   
    int x3 = j;

    Word temp3;
    int l = k + 1;
    k = 0;
    while ((l < (*kata).Length) && ((*kata).TabWord[l] != ' ')){
        temp3.TabWord[k] = (*kata).TabWord[l];
        k++;
        l++;
    }    

    (*kata).Length = x1;
    temp1.Length = x2;
    temp2.Length = x3;
    temp3.Length = k;

    *id1 = WordToInt(temp1);
    *id2 = WordToInt(temp2);
    *id3 = WordToInt(temp3);
}


void SplitCommandTwoInt(Word* kata, int* id1, int* id2){
    int i = 0;
    while ((i < (*kata).Length) && ((*kata).TabWord[i] != ' ')){
        i++;
    }
    int x1 = i;

    Word temp1;
    int j = i + 1;
    i = 0;
    while ((j < (*kata).Length) && ((*kata).TabWord[j] != ' ')){
        temp1.TabWord[i] = (*kata).TabWord[j];
        i++;
        j++;
    }
    int x2 = i;

    Word temp2;
    int k = j + 1;
    j = 0;
    while ((k < (*kata).Length) && ((*kata).TabWord[k] != ' ')){
        temp2.TabWord[j] = (*kata).TabWord[k];
        j++;
        k++;
    }   

    (*kata).Length = x1;
    temp1.Length = x2;
    temp2.Length = j;

    *id1 = WordToInt(temp1);
    *id2 = WordToInt(temp2);
}


void SplitCommandOneInt(Word* kata, int* id1){
    int i = 0;
    while ((i < (*kata).Length) && ((*kata).TabWord[i] != ' ')){
        i++;
    }
    int x1 = i;

    Word temp1;
    int j = i + 1;
    i = 0;
    while ((j < (*kata).Length) && ((*kata).TabWord[j] != ' ')){
        temp1.TabWord[i] = (*kata).TabWord[j];
        i++;
        j++;
    } 

    (*kata).Length = x1;
    temp1.Length = i;

    *id1 = WordToInt(temp1);
}

void SplitCommandWords(Word* kata1, Word* kata2){
    int i = 0;
    while ((i < (*kata1).Length) && ((*kata1).TabWord[i] != ' ')){
        i++;
    }
    int x1 = i;

    int j = i + 1;
    i = 0;
    while ((j < (*kata1).Length) && ((*kata1).TabWord[j] != ' ')){
        (*kata2).TabWord[i] = (*kata1).TabWord[j];
        i++;
        j++;
    } 

    (*kata1).Length = x1;
    (*kata2).Length = i;
}