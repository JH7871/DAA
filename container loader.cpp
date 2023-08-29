#include <stdio.h>

#define MAX_ITEMS 100
#define CONTAINER_WIDTH 100
#define CONTAINER_HEIGHT 100
#define CONTAINER_DEPTH 100

struct Item {
    int width;
    int height;
    int depth;
    int weight;
};

void packItems(struct Item items[], int n) {
    int container[MAX_ITEMS][3]; // Stores the position of each item [x, y, z]

    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0, z = 0;

        for (int j = 0; j < i; ++j) {
            x = container[j][0] + items[j].width;
            if (x <= CONTAINER_WIDTH - items[i].width) {
                y = container[j][1];
                z = container[j][2];
            } else {
                x = 0;
                y = container[j][1] + items[j].height;
                if (y <= CONTAINER_HEIGHT - items[i].height) {
                    z = container[j][2];
                } else {
                    y = 0;
                    z = container[j][2] + items[j].depth;
                }
            }
        }

        container[i][0] = x;
        container[i][1] = y;
        container[i][2] = z;

        printf("Item %d: Position (%d, %d, %d)\n", i + 1, x, y, z);
    }
}

int main() {
    struct Item items[MAX_ITEMS] = {
        {20, 30, 40, 10},
        {30, 40, 20, 15},
        {10, 25, 15, 5},
        // Add more items here...
    };

    int itemCount = 3; // Number of items

    packItems(items, itemCount);

    return 0;
}
