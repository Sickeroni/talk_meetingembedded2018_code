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
                    switch(iter.type_) {
                        case RecordedAction::Type::write: std::cout << "write 0x"; break;
                        case RecordedAction::Type::writeLiteral: std::cout << "writeliteral 0x"; break;
                        case RecordedAction::Type::read: std::cout << "read 0x"; break;
                        case RecordedAction::Type::unknown: std::cout << "unknown 0x"; break;

                    }
                    std::cout  << std::setfill('0') << std::hex << std::setw(8) << iter.address_;
                    std::cout << " 0x" << std::setfill('0') << std::hex << std::setw(8) << iter.value_ << "\n";

                }
                Kvasir::Register::actions_.clear();
            }
        };

    }
}