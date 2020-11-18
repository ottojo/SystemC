#include "Producer.hpp"

void Producer::produce() {
    for (int c = 0; c < 256; c++) {
        out->write(c);
    }
}
