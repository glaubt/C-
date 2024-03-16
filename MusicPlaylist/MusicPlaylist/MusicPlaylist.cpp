#include <windows.h>
#include <commdlg.h> // Для использования диалогового окна открытия файла

// Прототип функции обработки сообщений
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Глобальная переменная для хранения имени выбранного файла
TCHAR selectedFile[MAX_PATH] = { 0 };

// Определение идентификаторов для кнопок
enum ButtonID {
    BUTTON_SELECT_MUSIC = 1,
    BUTTON_PLAY_MUSIC,
    BUTTON_STOP_MUSIC,
    BUTTON_NEXT_MUSIC,
    BUTTON_PREVIOUS_MUSIC,
    BUTTON_LOAD_MUSIC
};

// Window
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Регистрация класса окна
    WNDCLASS wc = {};
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;           // Указатель на функцию обработки сообщений
    wc.lpszClassName = TEXT("MusicPlaylist");
    RegisterClass(&wc);

    // Создание окна
    HWND hWnd = CreateWindow(
        TEXT("MusicPlaylist"),           // Имя класса окна
        TEXT("Music Playlist"),         // Заголовок окна
        WS_OVERLAPPEDWINDOW,            // Стиль окна
        CW_USEDEFAULT, CW_USEDEFAULT,   // Позиция X и Y
        1920, 1080,                       // Ширина и высота
        NULL,                           // Родительское окно
        NULL,                           // Дескриптор меню
        hInstance,                      // Дескриптор экземпляра
        NULL                            // Данные создания
    );

    // Проверка на успешное создание окна
    if (!hWnd) {
        MessageBox(NULL, TEXT("Не удалось создать окно!"), TEXT("Ошибка"), MB_ICONERROR);
        return 1;
    }

    // Создание кнопок
    CreateWindow(
        TEXT("BUTTON"), TEXT("Выбрать музыку"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        20, 20, 150, 30, hWnd, (HMENU)BUTTON_SELECT_MUSIC, hInstance, NULL
    );

    CreateWindow(
        TEXT("BUTTON"), TEXT("Включить музыку"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        180, 20, 150, 30, hWnd, (HMENU)BUTTON_PLAY_MUSIC, hInstance, NULL
    );

    CreateWindow(
        TEXT("BUTTON"), TEXT("Остановить музыку"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        340, 20, 150, 30, hWnd, (HMENU)BUTTON_STOP_MUSIC, hInstance, NULL
    );

    CreateWindow(
        TEXT("BUTTON"), TEXT("Выбрать следующую музыку"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        20, 70, 220, 30, hWnd, (HMENU)BUTTON_NEXT_MUSIC, hInstance, NULL
    );

    CreateWindow(
        TEXT("BUTTON"), TEXT("Выбрать прошлую музыку"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        260, 70, 220, 30, hWnd, (HMENU)BUTTON_PREVIOUS_MUSIC, hInstance, NULL
    );

    CreateWindow(
        TEXT("BUTTON"), TEXT("Загрузить музыку"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        20, 120, 460, 30, hWnd, (HMENU)BUTTON_LOAD_MUSIC, hInstance, NULL
    );

    // Отображение окна
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Запуск цикла обработки сообщений
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Функция обработки сообщений
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_COMMAND: {
        // Обработка сообщений от кнопок
        switch (LOWORD(wParam)) {
        case BUTTON_SELECT_MUSIC:
            MessageBox(hWnd, TEXT("Выбрать музыку"), TEXT("Button Clicked"), MB_OK);
            break;
        case BUTTON_PLAY_MUSIC:
            MessageBox(hWnd, TEXT("Включить музыку"), TEXT("Button Clicked"), MB_OK);
            break;
        case BUTTON_STOP_MUSIC:
            MessageBox(hWnd, TEXT("Остановить музыку"), TEXT("Button Clicked"), MB_OK);
            break;
        case BUTTON_NEXT_MUSIC:
            MessageBox(hWnd, TEXT("Выбрать следующую музыку"), TEXT("Button Clicked"), MB_OK);
            break;
        case BUTTON_PREVIOUS_MUSIC:
            MessageBox(hWnd, TEXT("Выбрать прошлую музыку"), TEXT("Button Clicked"), MB_OK);
            break;
        case BUTTON_LOAD_MUSIC:
        {
            OPENFILENAME ofn;
            TCHAR szFile[MAX_PATH] = { 0 };
            ZeroMemory(&ofn, sizeof(ofn));
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = TEXT("MP3 files\0*.mp3\0");
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

            ofn.lpstrFile = szFile;
            ofn.nMaxFile = MAX_PATH;

            if (GetOpenFileName(&ofn) == TRUE) {
                MessageBox(hWnd, szFile, TEXT("Выбранный файл"), MB_OK);
            }
        }
        break;
        }
        break;
    }
    case WM_DESTROY: {
        // Завершение приложения при закрытии окна
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}
