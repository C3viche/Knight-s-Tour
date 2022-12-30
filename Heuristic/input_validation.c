#include "input_validation.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//+++\n

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    
    /**
        Checks if the input entered is valid based on the 
        number of arguments needed and actually read

        @param numArgsRead: the number of arguments read
        @param numArgsNeed: the number of arguments needed for input to be valid
        @return: true or false, whether input is valid or not
    */
    
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do {
    scanf("%c", &character); //45  bob  \n
        if(!isspace(character)){ //found a non whitespace character on the way to the end of the line
            formatIsGood = false;
        }
    } while(character != '\n'); //read characters until the end of the line
    return formatIsGood;
}

//cat

char getValidChar(const char* prompt){
    
    /**
        Keeps prompting user for a character until a valid character is entered

        @param prompt: the string displayed to the user asking for input
        @return: the character (if it's valid)
    */
    
    char letter;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %c", &letter); // waffles 45\n
    } while(!isValidFormat(numArgsRead, numArgsNeeded));

    return letter;
}


int getValidInt(const char* prompt){
    
    /**
        Keeps prompting user for an integer until a valid integer is entered

        @param prompt: the string displayed to the user asking for input
        @return: the integer (if it's valid)
    */
    
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num); // waffles 45\n
    } while(!isValidFormat(numArgsRead, numArgsNeeded));

    return num;
}

double getValidDouble(const char* prompt){
    
    /**
        Keeps prompting user for an double until a valid double is entered

        @param prompt: the string displayed to the user asking for input
        @return: the integer (if it's valid)
    */
    
    double num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %lf", &num); //waffles\n
    } while(!isValidFormat(numArgsRead, numArgsNeeded));

    return num;
}

bool inbetween(int val, int lowerBound, int upperBound){
    
    /**
        Checks if a value is between two bounds

        @param val: a number
        @param lowerBound: the lower bound (inclusive)
        @param upperBound: the upper bound (inclusive)
        @return: true or false, whether or not the value is within the bounds
    */
    
    return val >= lowerBound && val <= upperBound;
}


int getValidIntInRange(int lowerBound, int upperBound){
    
    /**
        Continuously asks for integer value until it is valid and within the set bounds

        @param lowerBound: the lower bound (inclusive)
        @param upperBound: the upper bound (inclusive)
        @return: the number inputted, if it's within the bounds
    */
    
    int num;
    do {
        printf("Enter a number between %d-%d: ", lowerBound, upperBound);
        num = getValidInt("");
    } while(!(inbetween(num, lowerBound, upperBound)));

    return num;
}

int getPosInt(const char* prompt){
    
    /**
        Continuously asks for an integer until it is valid and positive

        @return: the number inputted, if it's positive
    */
    
    int num;
    do {
        num = getValidInt(prompt);
    } while(!(num > 0));

    return num;
}

int getNegInt(const char* prompt){
    
    /**
        Continuously asks for an integer until it is valid and negative

        @return: the number inputted, if it's negative
    */
    
    int num;
    do {
        num = getValidInt(prompt);
    } while(!(num < 0));

    return num;
}

int getIntAtLeast(int min_val, const char* prompt){
    
    /**
        Continuously asks for an integer until it is valid and at least the set minimum value

        @param min_val: the set minimum integer
        @param prompt: the string outputted when prompting the user for input
        @return: the integer inputted, if it's negative
    */
    
    int num;
    do {
        num = getValidInt(prompt);
    } while(!(num >= min_val));

    return num;
}

double getDoubleAtLeast(double min_val, const char* prompt){
    
    /** 
        Continuously asks for a double until it is valid and at least the set minimum value

        @param min_val: the set minimum double
        @param prompt: the string outputted when prompting the user for input
        @return: the double inputted, if it's negative
    */
    
    double num;
    do {
        num = getValidDouble(prompt);
    } while(!(num >= min_val));

    return num;
}

bool is_num(char* str) {
    int length = strlen(str);
    for(int i = 0; i < length - 1; i++) { // need to do length - 1 for null character apparently
        if(!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}