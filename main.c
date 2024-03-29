/* 
    Please ensure that all required libraries are installed 
    to make sure everything will run correctly.

    Compile and run it using GCC or premade Makefile ->
    gcc main.c interfaces.c capture.c -o output -L/usr/include -lpcap && sudo ./output
    or
    make
*/
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <unistd.h>

#include "interfaces.h"
#include "capture.h"

#define __NEWLINE__ "\r\r\n"
#define __SEPARATOR__ "------------------------"

int main(int argc, char **argv) {
    if(getuid() != 0) {
        fprintf(stderr, "Please make sure to run this tool as root!%s", __NEWLINE__);
        return 1;
    }

    char* selected = get_selected_interface();

    setup_capture(selected);
    free(selected);
    return 0;
}