#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Flashlight Player");

    // Load player image
    Texture2D playerTexture = LoadTexture("player.png");
    Vector2 playerPosition = { screenWidth / 2, screenHeight / 2 }; // Initial position

    // Load background image
    Texture2D background = LoadTexture("background.png");

    // Load shader
    Shader shader = LoadShader(0, TextFormat("resources/shaders/glsl%i/base_light.fs", 330));

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update player position to follow the cursor
        playerPosition = GetMousePosition();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginShaderMode(shader);
        DrawTexture(background, 0, 0, WHITE);

        // Draw a circle around the player as a flashlight
        DrawCircle(playerPosition.x, playerPosition.y, 200, Fade(BLACK, 0.5f));

        EndShaderMode();

        // Draw player at cursor position
        DrawTexture(playerTexture, (int)(playerPosition.x - playerTexture.width / 2), (int)(playerPosition.y - playerTexture.height / 2), WHITE);

        EndDrawing();
    }

    UnloadTexture(playerTexture);
    UnloadTexture(background);
    UnloadShader(shader);
    CloseWindow();

    return 0;
}
