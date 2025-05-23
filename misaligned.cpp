#include <iostream>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int PrintColorMap = 2;
    int i = PrintColorMap / 5;
    int j = PrintColorMap % 5;
    int result = printColorMap();
    assert(std::string(majorColor[i]) == ("White"));
    assert(std::string(minorColor[j]) == ("Green"));
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
}