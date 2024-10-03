#include <iostream>
#include <utility>

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

const int
	WINDOW_WIDTH {720 * 2},
	WINDOW_HEIGHT {480 * 2};

void draw_grid(int size, int space) noexcept
{
	for(int i = 0; i < size; i++)
	{
		Vector2
			start {i * space, 0},
			end {i * space, space * size};

		DrawLineV(start, end, WHITE);
	
		std::swap(start.x, start.y);
		std::swap(end.x, end.y);

		DrawLineV(start, end, WHITE);
	}
}

int main(int, char*[])
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Eye Test");
	float size {32}, space {4};

	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		draw_grid(static_cast<int>(size), static_cast<int>(space));

		
		// GUI
		DrawRectangle(WINDOW_WIDTH - 120 - 40 - 32, 40 - 16, 120 + 40 + 32, 70 + 16, BLACK);
		
		GuiSliderBar((Rectangle){WINDOW_WIDTH - 120 - 32, 40, 120, 20}, "Size", TextFormat("%.f", size), &size, 0, 720);
    GuiSliderBar((Rectangle){WINDOW_WIDTH - 120 - 32, 70, 120, 20}, "Space", TextFormat("%.f", space), &space, 0, 32);

		EndDrawing();
	}

	CloseWindow();

	return EXIT_SUCCESS;
}
