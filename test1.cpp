#include <string>
#include <cstring>
using namespace std;

int main(){

return 0;
}

char* string_to_charArray(string text){
    int n = text.length();
    char char_array[n+1];
    strcpy(char_array, text.c_str());
    return char_array;
}