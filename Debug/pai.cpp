#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>

using namespace std;

inline void make_sound() {
	Beep(494, 100);
    Sleep(100); 
    Beep(777, 100);
    Sleep(100); 
    Beep(845, 100);
	Sleep(100);
} 

int main () {

	while (1) {
		make_sound();
	} 

    int n = 100000000;

    for (int i = 1; i <= n; i++) {
        system ("gen.exe > in");
        system ("std.exe < in > std.out");
        system ("temp.exe < in > temp.out");
		
		int res = system ("fc temp.out std.out");        
					
        if (res) {
        	while (1) {
				make_sound();
			}
			
			system ("pause");
            return 0;
        }
	}

    return 0;
}
