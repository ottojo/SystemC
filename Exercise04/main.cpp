/**
 * @file main.cpp
 * @author jonas
 * @date 11/18/20
 * Main file for exercise 4: Producer and Consumer + sc_fifo
 */
#include "Top.hpp"

#include <systemc.h>

int sc_main(int /* argc */, char * /* argv */ []) {

   Top top("Top Level Module");

    sc_start();
    return 0;
}
