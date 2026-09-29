// Engine Include
#include "engine/Engine.hpp"
#include "game/Game.hpp"

// Start when the game starts
void Awake() {
    // Calls Awake() in all objects
    gameObjects.AwakeAll();
}

// Physics Step
void FixedUpdate() {
    gameObjects.FixedUpdateAll();
}
// Render Step
void Render() {
    // Rendering all objects
    gameObjects.RenderAll();
}
// Update Step
void Update() {
    // Calls Update() in all objects
    gameObjects.UpdateAll();
}
// Late Update Step
void LateUpdate() {
    gameObjects.LateUpdateAll();
}

int main() {
    Config = Load();

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Clocks
    sf::Clock clock;
    clock.start();
    sf::Clock dtclock;

    float accumulator = 0.0f;

    // Window startup
    Main_Window = sf::RenderWindow(sf::VideoMode({Config.WIDTH,Config.HEIGHT}), "SFML", sf::Style::Close | sf::Style::Titlebar);
    Main_Window.setPosition(sf::Vector2i((desktop.size.x/2)-(Config.WIDTH/2),(desktop.size.y/2)-(Config.HEIGHT/2)));
    Main_Window.setFramerateLimit(Config.maxFPS);
    Time::fixedDt = 1.0f/ static_cast<float>(Config.maxFPS);
    
    // Functions    
    Awake(); // This should be run after object loading

    while (Main_Window.isOpen())
    {
        // Clock to count DeltaTime
        sf::Time deltaTimer = dtclock.restart();
        Time::deltaTime = deltaTimer.asMilliseconds()/1000.0f;
        Time::time = clock.getElapsedTime().asMilliseconds()/1000.0f;
        
        accumulator += Time::deltaTime;

        while (const std::optional event = Main_Window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                Main_Window.close();
        }
        // Clear Window for Next Rendering
        Main_Window.clear(sf::Color::White);

        // Input Detection Step
        MainInput.Update();

        // Fixed Update
        while (accumulator >= Time::fixedDt)
        {
            FixedUpdate();
            accumulator -= Time::fixedDt;
        }
        // Update Steps
        Render();
        Update();
        LateUpdate();
        
        // Display whats been rendered 
        Main_Window.display();
    }

    bool saved = Save(Config);
    if (saved) {
        Print("Saved Config Sucessfully!");
    }
}

