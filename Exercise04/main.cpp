/**
 * @file main.cpp
 * @author jonas
 * @date 11/18/20
 * Main file for exercise 4: Producer and Consumer + sc_fifo
 */
#include "Producer.hpp"
#include "Consumer.hpp"

#include <systemc.h>

int sc_main(int /* argc */, char * /* argv */ []) {

    sc_fifo<unsigned char> fifo;
    Producer p("P1");
    Consumer c("C1");
    p.out.bind(fifo);
    c.in.bind(fifo);

    sc_start();
    return 0;
}
