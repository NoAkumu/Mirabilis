#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <algorithm>
#include <utility>

#include "engine/renderer/Window.hpp"
#include "engine/core/Utils.hpp"

class Renderer
{
    private:
        inline static std::vector<std::unique_ptr<Window>> allWindows;
    public:
        template <typename... Args>
        static Window& createWindow(Args&&... args) {
            auto win = std::make_unique<Window>(std::forward<Args>(args)...);
            
            Window& reference = *win;

            allWindows.push_back(std::move(win));

            return reference;
        };

        static void draw(Window& w, sf::Drawable& d) {
            w.draw(d);
        };
        static void draw(sf::Drawable& d) {
            allWindows.at(0).get()->draw(d);
        };

        static void closeWindow(Window& w) {
            auto it = std::find_if(
                allWindows.begin(),
                allWindows.end(),
                [&](const std::unique_ptr<Window>& ptr) {
                    return ptr.get() == &w;
                }
            );
            if (it == allWindows.end())
                return ;

            (*it).get()->close();
            allWindows.erase(it);
        };

        static sf::VideoMode getDesktop() {
            return sf::VideoMode::getDesktopMode();
        };
        
        static sf::Texture LoadTexture(const std::string& path) {
            try
            {
                return sf::Texture(SpritePath + path);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return sf::Texture(SpritePath + "Debug.png");
            }
        }
};
