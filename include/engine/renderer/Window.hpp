#pragma once
#include "engine/math/Math.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class Window
{
    private:
        sf::RenderWindow _window;
        Vector2 position;
        std::string title = "Window";
        Vector2 size = Vector2(640, 360);
    public:
        Window(Vector2 position, Vector2 size) : position(position), size(size), _window(sf::VideoMode(size),"Window") {
            _window.setPosition(position);
            _window.setSize(size);
        };
        Window(Vector2 position, Vector2 size, std::string title) : position(position), size(size), title(title), _window(sf::VideoMode(size),title) {
            _window.setPosition(position);
            _window.setSize(size);
            _window.setTitle(title);
        };
        ~Window() = default;
        const sf::RenderWindow& getNativeWindow() const {
            return _window;
        }
        void setPosition(Vector2 pos) {
            position = pos;
            _window.setPosition(position);
        }
        void setSize(Vector2 s) {
            size = s;
            _window.setSize(size);
        }
        void setTitle(std::string t) {
            title = t;
            _window.setTitle(title);
        }
        Vector2 getPosition() const {
            return position;
        }
        Vector2 getSize() const {
            return size;
        }
        std::string getTitle() const {
            return title;
        }
        void draw(sf::Drawable& d) {
            _window.draw(d);
        }
        void close() {
            _window.close();
        }
        void clear(sf::Color c) {
            _window.clear(c);
        }
        void display() {
            _window.display();
        }
        bool isOpen() const {
            return _window.isOpen();
        }
        void setFramerateLimit(unsigned int limit) {
            _window.setFramerateLimit(limit);
        }
        void setView(const sf::View view) {
            _window.setView(view);
        }
        const std::optional<sf::Event> pollEvent() {
            return _window.pollEvent();
        }
};