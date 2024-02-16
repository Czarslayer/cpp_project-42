#include "identify.hpp"

int main() {
    srand(time(NULL));
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    return 0;
}