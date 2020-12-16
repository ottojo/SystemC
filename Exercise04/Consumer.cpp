#include "Consumer.hpp"

[[noreturn]] void Consumer::process() {
    while (true) {
        auto i = in->read();
        std::cout << sc_time_stamp() << ": " << "Consumer " << name() << " received: " << static_cast<int>(i)
                  << std::endl;
    }
}
