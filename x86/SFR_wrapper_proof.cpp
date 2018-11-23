// wrapper header for kvasir
#include "SFR_wrapper_proof.hpp"

// kvasir header
#include "Chip/MK64F12.hpp"


#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

//thanks kalven for tips/debugging

using boost::asio::ip::tcp;


extern "C" {


int main(void); // needed here to be callable in main.c (otherwise name mangeling mismatch)
}


int main()
{
    std::cout << "\nread modify write something (set clock) \n";
    apply(write(Kvasir::SimScgc5::PortcValC::v1));

    std::cout << "\nread something (adc) \n";
    uint32_t readvalue = apply(read(Kvasir::Adc0Ra::d));

    std::cout << "\nwrite something (timer) \n";
    apply(write(Kvasir::Ftm0C0v::val,3));
}
