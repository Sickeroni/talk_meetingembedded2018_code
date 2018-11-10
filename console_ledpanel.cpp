#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>

#include "2018.h"   //graphic-array
#include "unicorn.h" //graphic-array
using std::uint8_t;

struct led_color_t {
  std::uint8_t r;
  std::uint8_t g;
  std::uint8_t b;
};

namespace panel {
constexpr static const uint8_t width = 64;
constexpr static const uint8_t height = 32;
}


using panel_width_t = std::array<led_color_t, panel::width>;
using panel_framebuffer_t = std::array<panel_width_t, panel::height>;

panel_framebuffer_t write_rainbow() {
    panel_framebuffer_t Array_Buffer;

        int y = 0;
        for (panel_width_t &X_Array : Array_Buffer) {
            int x = 0;
            for (led_color_t &Led_Pixel : X_Array) {
                Led_Pixel.r = x *4 ;
                Led_Pixel.g = 255 - x *4;
                Led_Pixel.b = y * 8;
                x++;
            }
            y++;
        }
    return Array_Buffer;
}

panel_framebuffer_t write_unicorn() {
    panel_framebuffer_t Array_Buffer;
    int index = 0;
    int y = 0;
    for (panel_width_t &X_Array : Array_Buffer) {
        int x = 0;
        for (led_color_t &Led_Pixel : X_Array) {

            // code source:
            // https://www.disk91.com/2014/technology/programming/use-create-thegimp-header-file-format/

            int data[4];
            data[0] = (int) header_data_unicorn[index];
            data[1] = (int) header_data_unicorn[index + 1];
            data[2] = (int) header_data_unicorn[index + 2];
            data[3] = (int) header_data_unicorn[index + 3];
            index += 4;

            Led_Pixel.r = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4));
            Led_Pixel.g = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2));
            Led_Pixel.b = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33)));

            x++;
        }
        y++;
    }
    return Array_Buffer;
}

panel_framebuffer_t write_2018() {
    panel_framebuffer_t Array_Buffer;
    int index = 0;
    int y = 0;
    for (panel_width_t &X_Array : Array_Buffer) {
        int x = 0;
        for (led_color_t &Led_Pixel : X_Array) {

            // code source:
            // https://www.disk91.com/2014/technology/programming/use-create-thegimp-header-file-format/

            int data[4];
            data[0] = (int) header_data_2018[index];
            data[1] = (int) header_data_2018[index + 1];
            data[2] = (int) header_data_2018[index + 2];
            data[3] = (int) header_data_2018[index + 3];
            index += 4;

            Led_Pixel.r = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4));
            Led_Pixel.g = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2));
            Led_Pixel.b = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33)));

            x++;
        }
        y++;
    }
    return Array_Buffer;
}


void output_panel(const panel_framebuffer_t Array_Buffer) {
    // Output of Framebuffer
    for (panel_width_t X_Array : Array_Buffer) {
        for (led_color_t Led_Pixel : X_Array) {
            std::cout << "\x1b[38;2;";          // start truecolor-color
            std::cout << (uint32_t)Led_Pixel.r; // red
            std::cout << ";";
            std::cout << (uint32_t)Led_Pixel.g; // green
            std::cout << ";";
            std::cout << (uint32_t)Led_Pixel.b;  // blue
            std::cout << "m\u2588\u2588\x1b[0m"; // symbols [unicode "fullblocks"]
            // and end of truecolor.
        }
        std::cout << "\n";
    }
}

int main() {
    panel_framebuffer_t Array_Buffer;

    Array_Buffer = write_rainbow();
    output_panel(Array_Buffer);

    std::cin.get();

    Array_Buffer = write_2018();
    output_panel(Array_Buffer);

    std::cin.get();

    Array_Buffer = write_unicorn();
    output_panel(Array_Buffer);

  return 0;
}