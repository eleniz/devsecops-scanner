/* car_pooling.c
   You are driving a vehicle that has capacity empty seats.
   Given trips[i] = [numPassengers, from, to], return YES if
   it is possible to pick up and drop off all passengers, NO otherwise.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int passengers;
} Event;

int compare(const void *a, const void *b) {
    Event *ea = (Event *)a;
    Event *eb = (Event *)b;
    return ea->position - eb->position;
}

int main() {
    int capacity, n;

    printf("Give capacity: ");
    scanf("%d", &capacity);

    printf("Give number of trips: ");
    scanf("%d", &n);

    Event *events = malloc(2 * n * sizeof(Event));

    printf("Give all trips (num of passengers, from, to):\n");
    for (int i = 0; i < n; i++) {
        int passengers, from, to;
        scanf("%d %d %d", &passengers, &from, &to);
        events[2*i].position   = from;
        events[2*i].passengers = +passengers;
        events[2*i+1].position   = to;
        events[2*i+1].passengers = -passengers;
    }

    qsort(events, 2 * n, sizeof(Event), compare);

    int current = 0;
    int possible = 1;
    for (int i = 0; i < 2 * n; i++) {
        current += events[i].passengers;
        if (current > capacity) {
            possible = 0;
            break;
        }
    }

    printf("Is it possible to pick up and drop off all passengers: %s\n",
           possible ? "YES" : "NO");

    free(events);
    return 0;
}