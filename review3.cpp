// file-io.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

const int maxString = 1024;    // read buffer size

int main( int argc, char ** argv ) {
    const char * fn = "test.file";            // file name
    const char * str = "This is a literal C-string.\n";
    
    // create/write the file
    printf("writing file\n");
    FILE * fw = fopen(fn, "w");
    for(int i = 0; i < 5; i++) {
        //puts to console include new line
        //and flush the buffer
        fputs(str, fw);
    }
    
    fclose(fw);
    printf("done.\n");
    
    // read the file
    printf("reading file\n");
    char buf[maxString];
    FILE * fr = fopen(fn, "r");
    while(fgets(buf, maxString, fr)) {
        //read into buf 
        // maximun amount to read from line of text
        //fputs no line ending and not flush 
        fputs(buf, stdout);
    }
    
    fclose(fr);
    remove(fn);
    
    printf("done.\n");
    
    return 0;
}