#include <stdio.h>
#include <stdlib.h>

// Structure to store car information
typedef struct {
    int pos;
    int speed;
    double time;
} Car;

// Comparator to sort cars by position in descending order
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    Car* cars = (Car*)malloc(positionSize * sizeof(Car));
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
        // Calculate time to reach target: (distance / speed)
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Sort cars by position descending
    qsort(cars, positionSize, sizeof(Car), compareCars);

    int fleets = 0;
    double maxTime = 0.0;

    // Process cars from closest to farthest
    for (int i = 0; i < positionSize; i++) {
        // If current car takes longer, it forms a new fleet
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int size = sizeof(position) / sizeof(position[0]);
    
    printf("Number of fleets: %d\n", carFleet(target, position, size, speed, size));
    // Output: 3
    return 0;
}
