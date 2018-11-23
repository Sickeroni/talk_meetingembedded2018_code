// wrapper header for kvasir
#include "SFR_wrapper.hpp"

// kvasir header
#include "Chip/MK64F12.hpp"

extern "C" {


int main(void); // needed here to be callable in main.c (otherwise name mangeling mismatch)
}

/*

C0-2 = rgb1
D0-3 = abcd

latch = ptb2
oe = ptb3
clk = ptb10

 */

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/option.hpp>

namespace po = boost::program_options;

int main()
{




    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ;

    std::cout << "halt" << std::endl;

    /* Port C Clock Gate Control: Clock enabled */
    apply(write(Kvasir::SimScgc5::PortcValC::v1));


    /* PORTC16 is configured as GPIO*/
    constexpr static auto pin_to_toggle = makePinLocation(Kvasir::Io::portC, Kvasir::Io::pin16);
    apply(write(Kvasir::PortcPcr16::MuxValC::v001));
    /* Port C16 to Output */
    apply(makeOutput(pin_to_toggle));

    // Define Pins
    constexpr static auto clk = makePinLocation(Kvasir::Io::portB, Kvasir::Io::pin10);
    constexpr static auto lat = makePinLocation(Kvasir::Io::portB, Kvasir::Io::pin2);
    constexpr static auto oe = makePinLocation(Kvasir::Io::portB, Kvasir::Io::pin3);

    constexpr static auto a = makePinLocation(Kvasir::Io::portD, Kvasir::Io::pin0);
    constexpr static auto b = makePinLocation(Kvasir::Io::portD, Kvasir::Io::pin1);
    constexpr static auto c = makePinLocation(Kvasir::Io::portD, Kvasir::Io::pin2);
    constexpr static auto d = makePinLocation(Kvasir::Io::portD, Kvasir::Io::pin3);

    constexpr static auto r1 = makePinLocation(Kvasir::Io::portC, Kvasir::Io::pin0);
    constexpr static auto g1 = makePinLocation(Kvasir::Io::portC, Kvasir::Io::pin1);
    constexpr static auto b1= makePinLocation(Kvasir::Io::portC, Kvasir::Io::pin2);


    constexpr static auto balla = makePinLocation(Kvasir::Io::portB, Kvasir::Io::pin20);
    apply(write(Kvasir::PortbPcr10::MuxValC::v001),
          write(Kvasir::PortbPcr2::MuxValC::v001),
          write(Kvasir::PortbPcr3::MuxValC::v001));

    apply(write(Kvasir::PortdPcr0::MuxValC::v001),
          write(Kvasir::PortdPcr1::MuxValC::v001),
          write(Kvasir::PortdPcr2::MuxValC::v001),
          write(Kvasir::PortdPcr3::MuxValC::v001));

    apply(write(Kvasir::PortcPcr0::MuxValC::v001),
          write(Kvasir::PortcPcr1::MuxValC::v001),
          write(Kvasir::PortcPcr2::MuxValC::v001));
    // Port C16 to Output
    apply(makeOutput(clk,lat,oe,a,b,c,d,r1,g1,b1));


    apply(set(oe)); //disable[high] panelthingis...
    apply(set(lat)); //enable latch
    apply(set(a));
    apply(set(r1));

    apply(clear(oe)); //enable[low] panelthingis...
    apply(clear(lat)); //disable latch
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));
    apply(write(Kvasir::PtcPtor::ptto, Kvasir::Register::value<(1<<10)>()));

    apply(set(oe)); //disable[high] panelthingis...
    apply(set(lat)); //enable latch












    while(1) {
        apply(set(balla));
    }
}
