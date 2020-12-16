/**
 * @file Top.hpp.h
 * @author ottojo
 * @date 12/16/20
 * Description here TODO
 */

#ifndef SYSTEMC_TOP_HPP
#define SYSTEMC_TOP_HPP

#include <systemc.h>
#include "Producer.hpp"
#include "Consumer.hpp"

class Top : public sc_module {
    private:
        Producer p{"Producer"};
        Consumer c{"Consumer"};
        sc_fifo<unsigned char> fifo;

    public:
        explicit Top(const sc_module_name &name) : sc_module(name) {
            p.out.bind(fifo);
            c.in.bind(fifo);
        };
};

#endif //SYSTEMC_TOP_HPP
