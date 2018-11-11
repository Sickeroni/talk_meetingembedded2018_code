#include <Register/Seam.hpp>
// needed dependency for seamlib
#include <Common/Tags.hpp>

// stringfunctions to format output
#include <bitset>
#include <iomanip>
#include <iostream>

namespace Kvasir
{
    namespace Register
    {
        template <typename T>
        struct ExecuteSeam<T, ::Kvasir::Tag::User> : RecordActions<T>
        {
            ~ExecuteSeam() {
                for (auto iter : Kvasir::Register::actions_)
                {
                    std::cout << "mww 0x" << std::setfill('0') << std::hex << std::setw(8) << iter.address_;
                    std::cout << " 0x" << std::setfill('0') << std::hex << std::setw(8) << iter.value_ << "\n";

                }
                Kvasir::Register::actions_.clear();
            }
        };

    }
}