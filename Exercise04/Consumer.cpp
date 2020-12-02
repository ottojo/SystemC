#include "Consumer.hpp"

[[noreturn]] void Consumer::process() {
    while (true) {
        auto i = in->read();
        std::cout << "Consumer " << name() << " received: " << static_cast<int>(i) << std::endl;
    }
}
