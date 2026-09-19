#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/ftxui.hpp>

int menu(){
}

int sortChoise(){
    using namespace ftxui;
    auto screen = ScreenInteractive::Fullscreen();

    std::vector<std::string> menuVars = {
        "Выбором",
        "Пузырьком",
        "вставками",
        "слиянием",
        "пирамидальная",
        "Быстрая",
        "Лексиграфическая",
        "Exit",
    };
    int selected = 0;

    MenuOption option;
    option.on_enter = screen.ExitLoopClosure();
    auto menu = Menu(&menuVars, &selected, option);

    screen.Loop(menu);

    return selected;
}
