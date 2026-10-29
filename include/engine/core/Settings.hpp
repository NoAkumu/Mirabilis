#pragma once
#include <string>

struct Configs
{
    int WIDTH = 1280;
    int HEIGHT = 720;
    bool Fullscreen = false;
    int maxFPS = 165;
};

extern std::string AssetPath;
extern std::string SpritePath;

bool Save(Configs c);
Configs Load();

inline Configs Config;