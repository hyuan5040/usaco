#include <iostream>
using namespace std;
int main () {
    int c1, c2, c3, m1, m2, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    for (int i = 0; i < 100; i ++) {
        if (i % 3 == 0) {
            while (m1 >= 0 && m2 < c2) {
                m1 --;
                m2 ++;
            }
        }
        else if (i % 3 == 1) {
            while (m2 >= 0 && m3 < c3) {
                m2 --;
                m3 ++;
            }
        }
        else {
            while (m3 >= 0 && m1 < c1) {
                m3 --;
                m1 ++;
            }
        }
    }
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3;
}
