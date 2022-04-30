#include <iostream>
#include <vector>

// https://www.techiedelight.com/previous-smaller-element/
//

using namespace std;

int main() {
    //int int_list[] = { 2, 5, 3, 7, 8, 1, 9};
    int int_list[] = { 5, 7, 4, 9, 8, 10 };
    int element_count = sizeof(int_list) / sizeof(int_list[0]);
    vector<int> results(element_count);
    results[0] = -1;
    for (int i = 1; i < element_count; i++){
        if (int_list[i - 1] < int_list[i]) {
            results[i] = (int_list[i - 1]);
        } else {
            for (int j = i - 1; j >= 0; j--) {
                if (results[j] < int_list[i]) {
                    results[i] = results[j];
                    break;
                }
            }
        }
    }
    for (int i = 0 ; i < element_count; i++) { 
        cout << results[i] << ' ';
    }
    cout << endl;
}