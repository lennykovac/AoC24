#include <iostream>
#include <filesystem>
#include "/home/sam/CLionProjects/AoC24/day1/task1_Historian_Hysteria.cpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char **argv) {

    if (argc > 1) {
        std::filesystem::path const inputPath = std::string(argv[1]);
        auto day1 = Task1_Historian_Hysteria(inputPath);
    }


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.