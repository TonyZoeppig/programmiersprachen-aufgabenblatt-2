#define _USE_MATH_DEFINES

#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"
#include "mat2.hpp"


int main(int argc, char* argv[])
{
    Window win{ std::make_pair(800,800) };

    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            win.close();
        }

        double time = win.get_time() * 200.0;

        // text stuff
        std::string display_text = "Time passed: " + std::to_string(time) + " seconds";
        int text_offset_x = 10;
        int text_offset_y = 5;
        unsigned int font_size = 35;
        win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

        // clock

        // create the outer circle of the clock
        float radius = -250;
        Circle clock_ring{ {400, 400}, radius, {} };
        clock_ring.draw(win, 2.0f);

        Vec2 clock_center = clock_ring.center();

        // create the seconds pointer and moving it time dependend
        Vec2 seconds_pointer = { clock_center.x, clock_center.y + radius};
        Mat2 seconds_rotation = make_rotation_mat2((time * 6 * M_PI) / 180);
        seconds_pointer = clock_center + (seconds_rotation * (seconds_pointer - clock_center));
        win.draw_line(clock_center.x, clock_center.y, seconds_pointer.x, seconds_pointer.y, 1.0f, 0.0f, 0.0f, 1.0f);

        // create the minutes pointer and moving it time dependend
        Vec2 minutes_pointer = { clock_center.x, clock_center.y + radius };
        Mat2 minutes_rotation = make_rotation_mat2(((time / 60) * 6 * M_PI) / 180);
        minutes_pointer = clock_center + (minutes_rotation * (minutes_pointer - clock_center));
        win.draw_line(clock_center.x, clock_center.y, minutes_pointer.x, minutes_pointer.y, 0.0f, 1.0f, 0.0f, 1.0f);

        // create the hours pointer and moving it time dependend
        Vec2 hours_pointer = { clock_center.x, clock_center.y + radius };
        Mat2 hours_rotation = make_rotation_mat2(((time / 3600) * 6 * M_PI) / 180);
        hours_pointer = clock_center + (hours_rotation * (hours_pointer - clock_center));
        win.draw_line(clock_center.x, clock_center.y, hours_pointer.x, hours_pointer.y, 0.0f, 0.0f, 1.0f, 1.0f);
        

        win.update();
    }

    return 0;
}