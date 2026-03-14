#!/bin/bash
echo "=== Compiling solutions ==="
gcc -o /app/bin/car_pooling   /app/src/car_pooling.c


echo "=== Testing car_pooling ==="
echo "4
2
3 1 5
2 3 7" | /app/bin/car_pooling

echo "=== All done ==="