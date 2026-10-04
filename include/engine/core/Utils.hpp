#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "engine/core/Settings.hpp"

// Text styles
#define TERMINALCOLOR_RESET                  "\033[0m"
#define TERMINALCOLOR_BOLD                   "\033[1m"
#define TERMINALCOLOR_DIM                    "\033[2m"
#define TERMINALCOLOR_ITALIC                 "\033[3m"
#define TERMINALCOLOR_UNDERLINE              "\033[4m"
#define TERMINALCOLOR_BLINK                  "\033[5m"
#define TERMINALCOLOR_REVERSE                "\033[7m"
#define TERMINALCOLOR_HIDDEN                 "\033[8m"
#define TERMINALCOLOR_STRIKETHROUGH          "\033[9m"

// 256-color foregrounds
#define TERMINALCOLOR_BLACK        "\033[38;5;0m"
#define TERMINALCOLOR_RED          "\033[38;5;196m"
#define TERMINALCOLOR_GREEN        "\033[38;5;46m"
#define TERMINALCOLOR_YELLOW       "\033[38;5;226m"
#define TERMINALCOLOR_BLUE         "\033[38;5;21m"
#define TERMINALCOLOR_MAGENTA      "\033[38;5;201m"
#define TERMINALCOLOR_CYAN         "\033[38;5;51m"
#define TERMINALCOLOR_WHITE        "\033[38;5;15m"

// Bright foregrounds
#define TERMINALCOLOR_BRIGHT_BLACK   "\033[38;5;8m"
#define TERMINALCOLOR_BRIGHT_RED     "\033[38;5;196m"
#define TERMINALCOLOR_BRIGHT_GREEN   "\033[38;5;46m"
#define TERMINALCOLOR_BRIGHT_YELLOW  "\033[38;5;226m"
#define TERMINALCOLOR_BRIGHT_BLUE    "\033[38;5;39m"
#define TERMINALCOLOR_BRIGHT_MAGENTA "\033[38;5;201m"
#define TERMINALCOLOR_BRIGHT_CYAN    "\033[38;5;51m"
#define TERMINALCOLOR_BRIGHT_WHITE   "\033[38;5;15m"

// 256-color backgrounds
#define TERMINALCOLOR_BG_BLACK       "\033[48;5;0m"
#define TERMINALCOLOR_BG_RED         "\033[48;5;196m"
#define TERMINALCOLOR_BG_GREEN       "\033[48;5;46m"
#define TERMINALCOLOR_BG_YELLOW      "\033[48;5;226m"
#define TERMINALCOLOR_BG_BLUE        "\033[48;5;21m"
#define TERMINALCOLOR_BG_MAGENTA     "\033[48;5;201m"
#define TERMINALCOLOR_BG_CYAN        "\033[48;5;51m"
#define TERMINALCOLOR_BG_WHITE       "\033[48;5;15m"

using namespace std;

template <typename... Args>
void Print(const Args&... args) {
    // Prefix
    cout << TERMINALCOLOR_BOLD << TERMINALCOLOR_BRIGHT_MAGENTA << "LOG: " << TERMINALCOLOR_RESET;
    // Message
    (cout << ... << args);
    // Resets and newline
    cout << endl;
}
template <typename... Args>
void Error(const Args&... args) {
    // Prefix
    cout << TERMINALCOLOR_BG_RED << TERMINALCOLOR_BOLD << TERMINALCOLOR_BRIGHT_WHITE << "ERROR: ";
    // Message
    (cout << ... << args);
    // Resets and newline
    cout << TERMINALCOLOR_RESET << endl;
}
template <typename... Args>
void Warn(const Args&... args) {
    // Prefix
    cout << TERMINALCOLOR_BG_YELLOW << TERMINALCOLOR_BOLD << TERMINALCOLOR_BRIGHT_WHITE << "WARNING: ";
    // Message
    (cout << ... << args);
    // Resets and newline
    cout << TERMINALCOLOR_RESET << endl;;
}
sf::Texture LoadTexture(const std::string& path);