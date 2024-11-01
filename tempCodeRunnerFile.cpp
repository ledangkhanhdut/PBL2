#include <windows.h>
#include <string>

using namespace std;

// Các bi?n di?u khi?n (handle) cho các tru?ng thông tin c?a d?i tu?ng Doctor
HWND hId, hName, hAge, hPhoneNumber, hAddress, hGender, hTimeWorking, hExp, hSubmit;

// Hàm x? lý s? ki?n c?a c?a s?
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            // T?o nhãn và các tru?ng nh?p cho t?ng thu?c tính c?a Doctor
            CreateWindow("static", "ID:", WS_VISIBLE | WS_CHILD, 20, 20, 100, 20, hwnd, NULL, NULL, NULL);
            hId = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 20, 300, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("static", "Name:", WS_VISIBLE | WS_CHILD, 20, 50, 100, 20, hwnd, NULL, NULL, NULL);
            hName = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 50, 300, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("static", "Age:", WS_VISIBLE | WS_CHILD, 20, 80, 100, 20, hwnd, NULL, NULL, NULL);
            hAge = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 80, 300, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("static", "Phone Number:", WS_VISIBLE | WS_CHILD, 20, 110, 100, 20, hwnd, NULL, NULL, NULL);
            hPhoneNumber = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 110, 300, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("static", "Address:", WS_VISIBLE | WS_CHILD, 20, 140, 100, 20, hwnd, NULL, NULL, NULL);
            hAddress = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 140, 300, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("static", "Gender (M/F):", WS_VISIBLE | WS_CHILD, 20, 170, 100, 20, hwnd, NULL, NULL, NULL);
            hGender = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 170, 300, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("static", "Time Working:", WS_VISIBLE | WS_CHILD, 20, 200, 100, 20, hwnd, NULL, NULL, NULL);
            hTimeWorking = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 200, 300, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("static", "Experience:", WS_VISIBLE | WS_CHILD, 20, 230, 100, 20, hwnd, NULL, NULL, NULL);
            hExp = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 250, 300, 60, hwnd, NULL, NULL, NULL);

            // T?o nút Submit
            hSubmit = CreateWindow("button", "Submit", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 330, 100, 30, hwnd, (HMENU)1, NULL, NULL);
            break;

        case WM_COMMAND:
            // Ki?m tra n?u ngu?i dùng nh?n nút Submit
            if (LOWORD(wp) == 1) {
                char id[10], name[30], age[10], phone[15], address[50], gender[5], timeWorking[30], exp[100];
				
                GetWindowText(hId, id, 10);
                GetWindowText(hName, name, 30);
                GetWindowText(hAge, age, 10);
                GetWindowText(hPhoneNumber, phone, 15);
                GetWindowText(hAddress, address, 50);
                GetWindowText(hGender, gender, 5);
                GetWindowText(hTimeWorking, timeWorking, 30);
                GetWindowText(hExp, exp, 100);

                // In ra các giá tr? nh?n du?c
                MessageBox(hwnd, "Thông tin Doctor dã du?c luu", "Thông báo", MB_OK);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

// Hàm kh?i t?o c?a s?
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASS wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = "DoctorWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClass(&wc)) {
        return -1;
    }

    HWND hwnd = CreateWindow("DoctorWindowClass", "Edit Doctor Information", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 450, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
