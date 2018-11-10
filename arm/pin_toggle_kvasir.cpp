// kinetis SDK header
#include <MK64F12.h>
// kvasir header
#include "Chip/MK64F12.hpp"

extern "C" {


int main(void); // needed here to be callable in main.c (otherwise name mangeling mismatch)
}


int main()
{

    /* Port C Clock Gate Control: Clock enabled */
    apply(write(Kvasir::SimScgc5::PortcValC::v1));

    /* PORTC16 is configured as GPIO*/
    constexpr static auto pin_to_toggle = makePinLocation(Kvasir::Io::portC, Kvasir::Io::pin16);
    apply(write(Kvasir::PortcPcr16::MuxValC::v001));
    /* Port C16 to Output */
    apply(makeOutput(pin_to_toggle));

    while (1)
    {
        apply(write(Kvasir::PtcPtor::ptto,
                    Kvasir::Register::value<(1<<16)>()));
      //  GPIO_PortToggle(PIN_TO_TOGGLE_PORT, 1u << PIN_TO_TOGGLE_PIN);
    }
}
