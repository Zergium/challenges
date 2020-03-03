

///Nim Game
// n stones in heap
// each turn 1..3 stones taken
// winner who takes last stone(s)
// all players play smart!
// return true if you will win with start n stones
bool willIWin(int n) {
    return 0 == n % 4;
}