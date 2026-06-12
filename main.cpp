#include <cstddef>
#include <ctime>
#include <random>
#include <raylib.h>
#include <set>
#include <vector>

class SortingVisualizer {
public:
    SortingVisualizer() {
        InitWindow(WIDTH, HEIGHT, "SortingVisualizer");
        SetTargetFPS(144);

        std::mt19937 generator { std::random_device{} () };
        std::uniform_real_distribution<float> range { 0.0f, 1.0f };
        for (size_t i {}; i < MAX_AMT; i++) {
            arr.push_back(range(generator));
        }
    }
   

    void main() {
        while (!WindowShouldClose()) {
            PollInputEvents();

            BeginDrawing();

            ClearBackground(BLACK);
            
            draw_array();
            compared.clear();
            sort_step();
            EndDrawing();

        }
    }

    void draw_array() {
        float x_step { static_cast<float>(WIDTH) / static_cast<float>(MAX_AMT) };
        for (size_t i {}; i < MAX_AMT; i++) {
            float height_rect { arr[i] * HEIGHT * 0.9f };
            auto color { done ? GREEN : compared.count(i) ? RED : WHITE };
            DrawRectangle(x_step * i, HEIGHT - height_rect, x_step, height_rect, color);
        }
    }

    void sort_step() {
        static size_t right { 0 };

        if (right >= MAX_AMT) {
            done = true;
            return;
        }

        size_t min_idx { right };
        for (size_t i { right}; i < MAX_AMT; i++) {
            if (arr[min_idx] > arr[i])
                min_idx = i;
        }

        auto temp { arr[right] };
        arr[right] = arr[min_idx];
        arr[min_idx] = temp;
        
        compared.emplace(min_idx);
        compared.emplace(right);

        right++;
    }

private:
    const int WIDTH { 1000 };
    const int HEIGHT { 1000 };
    const int MAX_AMT { 1000 };

    std::vector<float> arr {};
    std::set<size_t> compared {};
    bool done {};
};

int main() {
    SortingVisualizer instance {};
    instance.main();

    CloseWindow();
}
