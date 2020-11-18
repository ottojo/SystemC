/**
 * @file Producer.hpp
 * @author jonas
 * @date 11/18/20
 * Module outputting numbers from 0 to 255
 */

#ifndef SYSTEMC_PRODUCER_HPP
#define SYSTEMC_PRODUCER_HPP

#include <systemc.h>

class Producer : public sc_module {

        void produce();

        SC_HAS_PROCESS(Producer);

    public:
        sc_port<sc_fifo_out_if<unsigned char>> out;

        explicit Producer(const sc_module_name &name) : sc_module(name) {
            SC_THREAD(produce);
        }
};


#endif //SYSTEMC_PRODUCER_HPP
