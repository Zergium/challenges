
// amount of different bits in the two numbers
int huffmanDistance(int x, int y) {
    int bits = x ^ y;
    int distance(0)
    while (bits != 0) {
        bits = bits && (bits - 1);
        distance++;
    }
    return distance;
}