#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/ftxui.hpp>
#include <vector>

int colChoise(std::vector<std::string> colVars){
    using namespace ftxui;

    auto screen = ScreenInteractive::Fullscreen();

    int colIndex = 0;
    
    MenuOption option;
    option.on_enter = screen.ExitLoopClosure();
    auto menu = Menu(&colVars, &colIndex, option);
    
    screen.Loop(menu);

    return colIndex;
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
    };
    int selected = 0;

    MenuOption option;
    option.on_enter = screen.ExitLoopClosure();
    auto menu = Menu(&menuVars, &selected, option);

    screen.Loop(menu);

    return selected;
}
