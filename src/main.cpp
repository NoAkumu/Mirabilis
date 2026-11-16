// Engine Include
#include "engine/Engine.hpp"
#include "game/Game.hpp"

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

    auto desktop = Renderer::getDesktop();

    float accumulator = 0.0f;

    // Window startup
    Window& P_Window = Renderer::createWindow(Vector2((desktop.size.x/2)-(Config.WIDTH/2),(desktop.size.y/2)-(Config.HEIGHT/2)), Vector2(Config.WIDTH,Config.HEIGHT), "Main");
    
    Time::fixedDt = 1.0f/ static_cast<float>(Config.maxFPS);

    //P_Window.setFramerateLimit(Config.maxFPS);
    
    while (P_Window.isOpen())
    {
        Time::beginFrame();
        Print("FPS: ", std::round(1/Time::deltaTime), " | Frame time: ", Time::deltaTime*1000, " ms");

        accumulator += Time::deltaTime;

        while (const std::optional event = P_Window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                P_Window.close();
        }
        // Clear Window for Next Rendering
        P_Window.clear(Color::White);

        // Input Detection Step
        MainInput.Update();

        // Fixed Update
        while (accumulator >= Time::fixedDt)
        {
            FixedUpdate();
            accumulator -= Time::fixedDt;
        }
        // Update Steps
        Update();

        Render();
        LateUpdate();
        
        // Display whats been rendered 
        P_Window.display();

        Time::limitFrameRate(1.0f/Config.maxFPS);
    }
    
    bool saved = Save(Config);
    if (saved) {
        Print("Saved Config Sucessfully!");
    } else {
        Print("There was an error when trying to save the config");
    }
}

