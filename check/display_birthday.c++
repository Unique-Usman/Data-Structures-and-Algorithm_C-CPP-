#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstring>

int main() {
    std::string text = "Happy birthday Alli, Long life brother";  // Text to display in the figlet
    int width = 20;                      // Width of the figlet

    while (true) {
        for (int i = 0; i < text.length() + width; ++i) {
            // Calculate the starting index for the substring
            int startIndex = i % text.length();

            // Extract a substring from the original text based on the starting index and width
            std::string displayText = text.substr(startIndex, width);

            // Clear the console screen
            system("clear");
	    std::cout << "\033[0m";
            // Construct the command string with "figlet" and the displayText
            std::string command = "figlet -f big " + displayText;

            // Convert the command string to a C-style string
            const char* commandStr = command.c_str();

            // Print the figlet text
            system(commandStr);

            // Pause for a short duration to control the speed of scrolling
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
	system("./sound.sh");
    }   

    return 0;
}

