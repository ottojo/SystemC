/**
 * @file Consumer.hpp
 * @author jonas
 * @date 11/18/20
 * Module printing numbers from fifo
 */

#ifndef SYSTEMC_CONSUMER_HPP
#define SYSTEMC_CONSUMER_HPP

#include <systemc.h>

class Consumer : public sc_module {

        [[noreturn]] void process();

        SC_HAS_PROCESS(Consumer);

    public:
        sc_port<sc_fifo_in_if<unsigned char>> in;

        explicit Consumer(const sc_module_name &name) : sc_module(name) {
            SC_THREAD(process);
            sensitive << in;
        }
};


#endif //SYSTEMC_CONSUMER_HPP
