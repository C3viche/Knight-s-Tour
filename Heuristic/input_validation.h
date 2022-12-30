#ifndef INPUT_VALIDATION
    #define INPUT_VALIDATION
    #include <stdbool.h>
    #include <string.h>
    
    bool isValidFormat(const int numArgsRead, const int numArgsNeed);
	char getValidChar(const char* prompt);
	int getValidInt(const char* prompt);
	double getValidDouble(const char* prompt);
	bool inbetween(int val, int lowerBound, int upperBound);
	int getValidIntInRange(int lowerBound, int upperBound);
	bool is_num(char* str);
    int getPosInt(const char* prompt);
    int getNegInt(const char* prompt);

#endif